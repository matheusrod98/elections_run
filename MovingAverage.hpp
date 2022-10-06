#include "Nacional.hpp"

class MovingAverage {

    public:
        MovingAverage();
        std::vector<std::vector<int>> getStatesMovingAverage();
        std::vector<std::vector<int>> getNationalMovingAverage();

    private:
        void calculateStatesMovingAverage();
        void calculateNationalMovingAverage();

        std::vector<int> nationalMovingAverage;
        std::vector<std::vector<int>> statesMovingAverage;
};
