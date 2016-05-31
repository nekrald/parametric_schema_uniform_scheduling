// Author: Aliaksandr Nekrashevich, nekrald@gmail.com

#include "cho_sahni_optimizer.h"
#include <cmath>

ChoSahniOptimizer::ChoSahniOptimizer()
        : RatioOptimizer() {
    algo_name_ = "ChoSahniOptimizer";
}

ChoSahniOptimizer::ChoSahniOptimizer(double speed)
        : RatioOptimizer(speed) {
    algo_name_ = "ChoSahniOptimizer";
}

ChoSahniOptimizer::ChoSahniOptimizer(int fast, int unit, double speed)
        : RatioOptimizer(fast, unit, speed) {
    algo_name_ = "ChoSahniOptimizer";
}

double ChoSahniOptimizer::GetOptimalPerformance() {
    int m = fast_ + unit_;
    set_ = true;
    if (m == 2) return (sqrt(5.) + 1.) / 2.;
    return (1. + 0.5 * sqrt(2. * m - 2.));
}

ChoSahniOptimizer::~ChoSahniOptimizer() {}
