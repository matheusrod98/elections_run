#include <stdlib.h>
#include <iostream>
#include <vector>

#include "Estadual.hpp"

#define MAX_MONTHS 5
#define MAX_SAMPLES 200000

Estadual::Estadual(std::string name) {
    stateName = name;

    std::vector<int> candidateAVotes;
    for (int monthIndex = 0; monthIndex < MAX_MONTHS; monthIndex++) {
        int votes = rand() % MAX_SAMPLES;
	candidateAVotes.push_back(votes);
	        
    }

    std::vector<int> candidateBVotes;
    for (int monthIndex = 0; monthIndex < MAX_MONTHS; monthIndex++) {
        int votes = rand() % MAX_SAMPLES;
        candidateBVotes.push_back(MAX_SAMPLES - votes);
	        
    }
    
    candidatesVotes.push_back(candidateAVotes);
    candidatesVotes.push_back(candidateBVotes);
}

std::string Estadual::getName() {
    return stateName;
}

std::vector<std::vector<int>> Estadual::getSamples(int begin, int end) {

    std::vector<int> tempASamples = candidatesVotes.at(0);
    std::vector<int> candidateASamples;
    for (int samplesIndex = begin; samplesIndex <= end; samplesIndex++) {
        candidateASamples.push_back(tempASamples.at(samplesIndex));
    }

    std::vector<int> tempBSamples = candidatesVotes.at(1);
    std::vector<int> candidateBSamples;
    for (int samplesIndex = begin; samplesIndex <= end; samplesIndex++) {
        candidateBSamples.push_back(tempBSamples.at(samplesIndex));
    }

    std::vector<std::vector<int>> candidatesSamples;	
    candidatesSamples.push_back(candidateASamples);
    candidatesSamples.push_back(candidateBSamples);
    
    return candidatesSamples;
}
