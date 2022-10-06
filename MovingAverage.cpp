#include <vector>

#include "MovingAverage.hpp"
#include "Estadual.hpp"
#include "Nacional.hpp"

std::vector<std::vector<int>> calculateStateMovingAverage () {

    std::vector<std::vector<int>> stateMovingAverage;
    for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
        std::vector<int> stateVotes;  
        stateVotes = Nacional::states.at(stateIndex).getVotes;

        int movingAverageCandidateA = 0;
        int movingAverageCandidateB = 0;
        std::vector<int> movingAverageCandidates;
        for (int month = 0; month < MAX_MONTHS; month++) {
            movingAverageCandidateA += stateVotes.at(month).at(0) / MAX_MONTHS;
            movingAverageCandidateB += stateVotes.at(month).at(1) / MAX_MONTHS;
        }
        movingAverageCandidates.push_back(movingAverageCandidateA);
        movingAverageCandidates.push_back(movingAverageCandidateB);
        stateMovingAverage.push_back(movingAverageCandidates);
    }

    return stateMovingAverage;
}

std::vector<int> calculateNationalMovingAverage () {

}

std::vector<std::vector<int>> getStateMovingAverage () {
    return calculateStateMovingAverage;
}

std::vector<int> getNationalMovingAverage () {
    return calculateNationalMovingAverage;
}
