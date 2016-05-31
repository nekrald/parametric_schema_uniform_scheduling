// Author: Aliaksandr Nekrashevich, nekrald@gmail.com
#pragma once
#include "ratio_optimizer.h"

class ChoSahniOptimizer final : public RatioOptimizer {
    public:
        ChoSahniOptimizer();
        ChoSahniOptimizer(double speed);
        ChoSahniOptimizer(int fast, int unit, double speed);

        // Returns result stated in Cho-Sahni paper.
        virtual double GetOptimalPerformance() override;
        virtual ~ChoSahniOptimizer();
};
