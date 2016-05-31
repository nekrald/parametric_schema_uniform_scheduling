// Author: Aliaksandr Nekrashevich, nekrald@gmail.com

#pragma once
#include "ratio_optimizer.h"
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include <cmath>

typedef std::vector<std::unique_ptr<RatioOptimizer>> OptimizerPack;

// Evaluates each algorithm in optimizer pack on parameters
// for fast processor count in [fast_lower, fast_upper], and
// unit-speed processor count in [unit_lower, unit_upper].
// Speed is given as parameter.
// Result is written in file filename.

class GroupEvaluator {

public:
    GroupEvaluator(OptimizerPack* compared_optimizers);

    void Evaluate(
            int fast_lower,
            int fast_upper,
            int unit_lower,
            int unit_upper,
            double speed,
            std::string filename);

private:
    OptimizerPack* optimizers_;
    std::ofstream target_output_;
};
