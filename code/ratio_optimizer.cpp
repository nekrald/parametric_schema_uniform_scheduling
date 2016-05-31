// Author: Aliaksandr Nekrashevich, nekrald@gmail.com

#include "ratio_optimizer.h"

using std::string;
const double RatioOptimizer::UNIT_SPEED = 1.L;
const double RatioOptimizer::NO_ANSWER = -1.L;
const double RatioOptimizer::EPS = 1e-8;

RatioOptimizer::RatioOptimizer() :
    set_(false)
{}

RatioOptimizer::RatioOptimizer(double speed) :
    speed_(speed),
    set_(false)
{}

RatioOptimizer::RatioOptimizer(int fast, int unit, double speed) :
    fast_(fast),
    unit_(unit),
    speed_(speed),
    set_(false)
{}

void RatioOptimizer::SetMachines(int fast, int unit) {
    fast_ = fast;
    unit_ = unit;
    set_ = false;
}

void RatioOptimizer::SetSpeed(double speed) {
    speed_ = speed;
    set_ = false;
}

bool RatioOptimizer::update(double candidate) {
    if (!set_ || (candidate < best_)) {
        best_ = candidate;
        set_ = true;
        return true;
    }
    return false;
}

std::string RatioOptimizer::GetName() const {
    return algo_name_;
}

bool RatioOptimizer::IsSet() const {
    return set_;
}

RatioOptimizer::~RatioOptimizer() {}
