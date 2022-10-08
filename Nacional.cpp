#include <string>
#include <time.h>
#include <stdlib.h>

#include "Nacional.hpp"

using namespace std;

Nacional::Nacional() {
    vector<string> statesCodes = { "AC", "AL", "AM", "AP", "BA", "CE", 
				        "DF", "ES", "GO", "MA", "MG", "MS",
				        "MT", "PA", "PB", "PE", "PI", "PR",
				        "RJ", "RN", "RO", "RR", "RS", "SC",
				        "SE", "SP", "TO" };

    srand(time(NULL));
    for (int stateIndex = 0; stateIndex < 26; stateIndex++)
        states.push_back(Estadual(statesCodes.at(stateIndex)));
}

vector<Estadual> Nacional::getStates() {
    return states;
}
