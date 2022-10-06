#include <stdlib.h>
#include <time.h>
#include <vector>

#include "Estadual.hpp"

Estadual::Estadual (std::string name) {
    stateName = name;

    for (int month = 0; month < MAX_MONTHS; month++) {
        std::vector<int> candidateVotes;
        int votes = 0;
        for (int indexCandidate = 0; indexCandidate < 2; indexCandidate++) {
            srand(time(NULL));
            votes = rand() % MAX_SAMPLES;
            candidateVotes.push_back(votes);
            candidateVotes.push_back(MAX_SAMPLES - votes);
        }
        votesByMonth.push_back(candidateVotes);
    }
}

std::string Estadual::getName() {
    return stateName;
}

std::vector Estadual::getVotes () {
    return votesByMonth;
}
