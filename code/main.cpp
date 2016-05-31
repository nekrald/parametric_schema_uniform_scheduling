// Author: Aliaksandr Nekrashevich, nekrald@gmail.com

#include "schema_optimizer_brute.h"
#include "cho_sahni_optimizer.h"
#include "group_evaluator.h"

#include <iostream>
#include <cmath>
#include <cassert>
#include <sstream>
#include <experimental/filesystem>

// Prepares filename on parameters submitted to GroupEvaluator.
std::string BuildNameGroup(
        const OptimizerPack& who,
        double speed,
        int fast_lower,
        int fast_upper,
        int unit_lower,
        int unit_upper) {

    // Create directory if it does not exist yet.
    std::string directory_name = "./group_evaluation";
    std::experimental::filesystem::path path(directory_name);
    std::experimental::filesystem::create_directories(path);

    std::string result = directory_name + "/group-";

    // Write all optimizers.
    for (const auto& item : who) {
        result += item->GetName() + "-";
    }

    result += "speed=";
    std::string speed_string;

    std::stringstream builder;
    builder << speed;
    builder >> speed_string;
    result += speed_string;

    // Write borders of parameters.
    std::vector<int> borders = {fast_lower, fast_upper, unit_lower, unit_upper};
    std::vector<std::string> names =
        {"-fast_lower=", "-fast_upper=", "-unit_lower=", "-unit_upper="};
    for (size_t id = 0; id < borders.size(); ++id) {
        auto number = borders[id];
        auto word = names[id];
        std::string string_number;
        builder.clear();
        builder << number;
        builder >> string_number;
        result += word;
        result += string_number;
    }

    result += ".res";
    return result;
}

void CompareAlgorithms() {
        OptimizerPack compared;
        compared.push_back(std::unique_ptr<RatioOptimizer>(new ChoSahniOptimizer()));
        compared.push_back(std::unique_ptr<RatioOptimizer>(new SchemaOptimizerBrute()));
        GroupEvaluator evaluator(&compared);
        for (double speed = 1.5; speed < 5.1;  speed += 0.5) {
            auto group_name = BuildNameGroup(compared, speed, 1, 100, 1, 100);
            evaluator.Evaluate(1, 100, 1, 100, speed, group_name);
            std::cout <<  group_name << " finished \n";
        }
}

int main() {
    CompareAlgorithms();
}
