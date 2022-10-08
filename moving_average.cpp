#include <vector>

#include "moving_average.hpp"

using namespace std;

float calculateMovingAverage(vector<int> samples) {
    float movingAverage = 0;
    for (unsigned int sampleIndex = 0; sampleIndex < samples.size(); sampleIndex++){
        movingAverage += samples.at(sampleIndex) / samples.size();
    } 
    
    return movingAverage;
}
