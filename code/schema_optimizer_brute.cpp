// Author: Aliaksandr Nekrashevich, nekrald@gmail.com

#include <cmath>
#include "schema_optimizer_brute.h"


SchemaOptimizerBrute::SchemaOptimizerBrute():
    RatioOptimizer() {
    algo_name_ = "SchemaOptimizerBrute";
}

SchemaOptimizerBrute::SchemaOptimizerBrute(double speed) : RatioOptimizer(speed) {
    algo_name_ = "SchemaOptimizerBrute";
}

SchemaOptimizerBrute::SchemaOptimizerBrute(int fast, int unit, double speed) :
    RatioOptimizer(fast, unit, speed) {
    algo_name_ = "SchemaOptimizerBrute";
}

double SchemaOptimizerBrute::GetOptimalPerformance() {
    int n = ceil(speed_ - EPS) + EPS;
    int group_size = (n - 1) * fast_;
    int Rmax = unit_ / group_size;
    double best_phi;
    double d = double(unit_ + fast_) / fast_;
    int best_r;
    for (int R = 0; R <= Rmax; ++R) {
        int m2 = R * group_size;
        int m1 = unit_ - m2;
        for (double phi = 0.01, add = 0.01; phi < 1.0 + EPS; phi += add) {
            double l = speed_, r = speed_ * 100.;
            r = std::max(r, 2. + 2. + (speed_ - 1) * (d - 1) / (speed_ + d - 1));
            // Binary search for border B.
            for (int iter = 0; iter < 50; ++iter) {
                double mid = (l + r) / 2.;
                if (can(mid, phi, R, m1, m2)) {
                    // If we have better answer then before,
                    // update it.
                    if (update(mid)) {
                        best_phi = phi;
                        best_r = R;
                    }
                    r = mid;
                } else {
                    l = mid;
                }
            }
        }
    }
    if (set_) {
        return best_;
    } else {
        return NO_ANSWER;
    }
}

bool SchemaOptimizerBrute::can(double border, double phi, int R, int m1, int m2) {
    bool second_condition =  (m1 >= 0 || m2 >= 0);
    bool first_condition = ((border - 1.) * speed_ * fast_  + (1. - phi) * m1 * border >=
            double(speed_) * fast_ + m1 + m2);
    bool third_condition = ((1. - phi) * border <= pow(phi * border, R) * (border - speed_));
    bool fourth_condition = (border + EPS >= speed_);
    return first_condition && second_condition && third_condition && fourth_condition;
}

SchemaOptimizerBrute::~SchemaOptimizerBrute() {};
