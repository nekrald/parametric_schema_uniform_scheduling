// Author: Aliaksandr Nekrashevich, nekrald@gmail.com

#include "group_evaluator.h"

#include <map>
#include <iostream>

using std::map;
using std::string;
using std::endl;

GroupEvaluator::GroupEvaluator(OptimizerPack* compared_optimizers) :
    optimizers_(compared_optimizers) {
}

void GroupEvaluator::Evaluate(
        int fast_lower,
        int fast_upper,
        int unit_lower,
        int unit_upper,
        double speed,
        string filename) {
    target_output_.open(filename);
    // Prepare header.
    target_output_ << "speed \t fast \t unit \t performance \t best_algo \t qualities" << endl;
    target_output_ << std::fixed;
    target_output_.precision(4);
    for (int fast_count = fast_lower; fast_count <= fast_upper; ++fast_count) {
        for (int unit_count = unit_lower; unit_count <= unit_upper; ++unit_count) {
            string best_algo = "None";
            bool best_set = false;
            double best_performance = RatioOptimizer::NO_ANSWER;
            map<string, double> algo_to_performance;
            for (auto& optimizer : *optimizers_) {
                optimizer->SetSpeed(speed);
                optimizer->SetMachines(fast_count, unit_count);
                double current_performance = optimizer->GetOptimalPerformance();
                algo_to_performance[optimizer->GetName()] = current_performance;
                if (optimizer->IsSet() && (!best_set || best_performance > current_performance)) {
                    best_set = true;
                    best_performance = current_performance;
                    best_algo = optimizer->GetName();
                }
            }
            // Output performance of best algorithm.
            target_output_ << speed << " \t "
                << fast_count << " \t "
                << unit_count << " \t "
                << best_performance << " \t "
                <<  best_algo << "\t";
            // Output performance of each algorithm.
            for (auto item : algo_to_performance) {
                target_output_ << item.first << "\t" << item.second << "\t";
            }
            target_output_ << endl;
        }
    }
    target_output_.close();
}
