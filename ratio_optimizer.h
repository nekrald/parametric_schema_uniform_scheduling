// Author: Aliaksandr Nekrashevich, nekrald@gmail.com

#pragma once
#include <string>

class RatioOptimizer {
    public:
        RatioOptimizer();
        RatioOptimizer(double speed);
        RatioOptimizer(int fast, int unit, double speed);

        void SetMachines(int fast, int unit);
        void SetSpeed(double speed);

        virtual bool update(double candidate);
        virtual double GetOptimalPerformance() = 0;

        std::string GetName() const;
        bool IsSet() const;

        virtual ~RatioOptimizer();

        static const double NO_ANSWER;
    protected:
        int fast_, unit_;

        // Below speed_ is the speed of fast machines,
        // best_ is the best known bound by current
        // state of the algorithm.
        double speed_, best_;

        // Below set_ is true iff we have found
        // at least one feasible solution at the
        // current state of the algorithm.
        bool set_;

        std::string algo_name_;

        static const double UNIT_SPEED;
        static const double EPS;
};
