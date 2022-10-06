#include <stdlib.h>
#include <iostream>

#include "Estadual.hpp"

#define MAX_MONTHS 5
#define MAX_SAMPLES 200000

Estadual::Estadual(std::string name) {
    stateName = name;

    for (int month = 0; month < MAX_MONTHS; month++) {
        std::vector<int> candidateVotes;
        int votes = rand() % MAX_SAMPLES;
        candidateVotes.push_back(votes);
        candidateVotes.push_back(MAX_SAMPLES - votes);
	votesByMonth.push_back(candidateVotes);
    }
}

std::string Estadual::getName() {
    return stateName;
}

std::vector<std::vector<int>> Estadual::getVotes() {
    return votesByMonth;
}
