// Author: Aliaksandr Nekrashevich, nekrald@gmail.com

#pragma once
#include "ratio_optimizer.h"

class SchemaOptimizerBrute final : public RatioOptimizer {

public:
    SchemaOptimizerBrute();
    SchemaOptimizerBrute(double speed);
    SchemaOptimizerBrute(int fast, int unit, double speed);

    virtual double GetOptimalPerformance() override;

    virtual ~SchemaOptimizerBrute();

protected:
    // Checks if obtained border is feasible, i.e. if all
    // equations of system holds. Input parameters:
    // border = B; phi, R, m1, m2 correspond to notation in
    // the paper.
    bool can(double border, double phi, int R, int m1, int m2);
};
