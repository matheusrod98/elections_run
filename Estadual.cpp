#include <stdlib.h>
#include <iostream>
#include <vector>

#include "Estadual.hpp"

#define MAX_MONTHS 5
#define MAX_SAMPLES 200000

using namespace std;

Estadual::Estadual(string name) {
    stateName = name;

    vector<int> candidateAVotes;
    for (int monthIndex = 0; monthIndex < MAX_MONTHS; monthIndex++) {
        int votes = rand() % MAX_SAMPLES;
	candidateAVotes.push_back(votes);
	        
    }

    vector<int> candidateBVotes;
    for (int monthIndex = 0; monthIndex < MAX_MONTHS; monthIndex++) {
        int votes = rand() % MAX_SAMPLES;
        candidateBVotes.push_back(MAX_SAMPLES - votes);
	        
    }
    
    candidatesVotes.push_back(candidateAVotes);
    candidatesVotes.push_back(candidateBVotes);
}

string Estadual::getName() {
    return stateName;
}

vector<vector<int>> Estadual::getSamples(int begin, int end) {

    vector<int> tempASamples = candidatesVotes.at(0);
    vector<int> candidateASamples;
    for (int samplesIndex = begin; samplesIndex <= end; samplesIndex++) {
        candidateASamples.push_back(tempASamples.at(samplesIndex));
    }

    vector<int> tempBSamples = candidatesVotes.at(1);
    vector<int> candidateBSamples;
    for (int samplesIndex = begin; samplesIndex <= end; samplesIndex++) {
        candidateBSamples.push_back(tempBSamples.at(samplesIndex));
    }

    vector<vector<int>> candidatesSamples;	
    candidatesSamples.push_back(candidateASamples);
    candidatesSamples.push_back(candidateBSamples);
    
    return candidatesSamples;
}
