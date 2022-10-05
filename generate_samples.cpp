#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

std::vector<int> generateSamples (int numberSamples) {

    int candidateASamples = 0;
    int candidateBSamples = 0;
    std::vector<int> samples;

    srand(time(0));
    candidateASamples = rand() % numberSamples;
    candidateBSamples = numberSamples - candidateASamples;

    samples.push_back(candidateASamples);
    samples.push_back(candidateBSamples);
    return samples;
}
