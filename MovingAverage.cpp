#include <vector>

#include "MovingAverage.hpp"

MovingAverage::MovingAverage() {
    calculateStatesMovingAverage();
    calculateNationalMovingAverage();
}

void calculateStateMovingAverage () {

    Nacional nac;

    std::vector<std::vector<int>> statesMovingAverage;
    for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
        std::vector<int> stateVotes;  
        stateVotes = nac.getStates().at(stateIndex).getVotes();

        int movingAverageCandidateA = 0;
        int movingAverageCandidateB = 0;
        std::vector<int> movingAverageCandidates;
        for (int month = 0; month < MAX_MONTHS; month++) {
            movingAverageCandidateA += stateVotes.at(month).at(0) / MAX_MONTHS;
            movingAverageCandidateB += stateVotes.at(month).at(1) / MAX_MONTHS;
        }
        movingAverageCandidates.push_back(movingAverageCandidateA);
        movingAverageCandidates.push_back(movingAverageCandidateB);
        statesMovingAverage.push_back(movingAverageCandidates);
    }
}

void calculateNationalMovingAverage () {

    int candidateANationalMovingAverage = 0;
    int candidateBNationalMovingAverage = 0;
    for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
        candidateANationalMovingAverage += statesMovingAverage.at(stateIndex).at(0);
        candidateBNationalMovingAverage += statesMovingAverage.at(stateIndex).at(1);
    }

    nationalMovingAverage.push_back(candidateANationalMovingAverage);
    nationalMovingAverage.push_back(candidateBNationalMovingAverage);
}

std::vector<std::vector<int>> getStatesMovingAverage () {
    return statesMovingAverage;
}

std::vector<int> getNationalMovingAverage () {
    return nationalMovingAverage;
}
