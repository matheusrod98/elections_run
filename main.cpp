#include <iostream>
#include <string>
#include <cstdlib>

#include "Nacional.hpp"
#include "Estadual.hpp"

#include "moving_average.hpp"

#define STABILITY 0.02
#define MAX_SAMPLES 200000

using namespace std;

int main () {

    bool firstRun = true;
    string option = "";

    Nacional nac;

    do {

        if (firstRun == true) {
            cout << "Bem-vindo ao portal das eleições presidenciais!" << endl;
            firstRun = false;
        }
        cout << endl;
        cout << "1 - Evolução média das intenções de voto" << endl;
        cout << "2 - Alta, baixa e estabilidade dos candidatos por estado" << endl;
        cout << "3 - Alta, baixa e estabilidade dos candidatos no país" << endl;
        cout << "4 - Maior alta e maior baixa dos candidatos" << endl;
        cout << "5 - Qual candidato está na frente" << endl;
        cout << "0 - Encerrar o programa" << endl;
        cout << "Por favor, selecione uma das opções abaixo: ";
        getline(cin, option);

        cout << endl;
        if (option == "1") {

            cout << "ESTADO    " << "Candidato A    " << "Candidato B    " << endl;
                        
            vector<Estadual> states = nac.getStates();
            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                vector<vector<int>> samples = state.getSamples(0, 4);
                cout << state.getName() << "         ";
                cout << calculateMovingAverage(samples.at(0)) << "          ";
                cout << calculateMovingAverage(samples.at(1)) << endl;
            }

            float candidateAMovingAverage = 0;
            float candidateBMovingAverage = 0;
            cout << "BRASIL     ";
            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                vector<vector<int>> samples = state.getSamples(0, 4);
                candidateAMovingAverage += calculateMovingAverage(samples.at(0));
                candidateBMovingAverage += calculateMovingAverage(samples.at(1));
            }
            cout << candidateAMovingAverage / 26 << "        ";
            cout << candidateBMovingAverage / 26 << endl;
        }

        else if (option == "2") {
            vector<Estadual> states = nac.getStates();
            vector<float> candidateAStability;
            vector<float> candidateBStability;

            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                vector<vector<int>> previousSamples = state.getSamples(0, 3);
                vector<vector<int>> nextSamples = state.getSamples(0, 4);
                candidateAStability.push_back(calculateMovingAverage(nextSamples.at(0)) / calculateMovingAverage(previousSamples.at(0)));
                candidateBStability.push_back(calculateMovingAverage(nextSamples.at(1)) / calculateMovingAverage(previousSamples.at(1)));
            }

            cout << "Candidato A" << endl;
            cout << "Alta: ";
            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                if (candidateAStability.at(stateIndex) - STABILITY > 1 + STABILITY)
                    cout << state.getName() << " ";
            }
            cout << endl;

            cout << "Baixa: ";
            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                if (candidateAStability.at(stateIndex) - STABILITY < 1 - STABILITY)
                    cout << state.getName() << " ";
            }
            cout << endl;

            cout << "Estabilidade: ";
            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                if (candidateAStability.at(stateIndex) - STABILITY <= 1 + STABILITY &&
                    candidateAStability.at(stateIndex) - STABILITY >= 1 - STABILITY)
                    
                    cout << state.getName() << " ";
            }
            cout << endl;
            cout << endl;
            
            cout << "Candidato B" << endl;
            cout << "Alta: ";
            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                if (candidateBStability.at(stateIndex) - STABILITY > 1 + STABILITY)
                    cout << state.getName() << " ";
            }
            cout << endl;

            cout << "Baixa: ";
            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                if (candidateBStability.at(stateIndex) - STABILITY < 1 - STABILITY)
                    cout << state.getName() << " ";
            }
            cout << endl;

            cout << "Estabilidade: ";
            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                if (candidateBStability.at(stateIndex) - STABILITY <= 1 + STABILITY &&
                    candidateBStability.at(stateIndex) - STABILITY >= 1 - STABILITY)
                    cout << state.getName() << " ";
            }
            cout << endl;
        }

        else if (option == "3") {
            vector<Estadual> states = nac.getStates();

            float candidateAPreviousMovingAverage = 0;
            float candidateANextMovingAverage = 0;
            float candidateBPreviousMovingAverage = 0;
            float candidateBNextMovingAverage = 0;

            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                vector<vector<int>> previousSamples = state.getSamples(0, 3);
                vector<vector<int>> nextSamples = state.getSamples(0, 4);
                candidateAPreviousMovingAverage += calculateMovingAverage(previousSamples.at(0));
                candidateBPreviousMovingAverage += calculateMovingAverage(previousSamples.at(1));
                candidateANextMovingAverage += calculateMovingAverage(nextSamples.at(0));
                candidateBNextMovingAverage += calculateMovingAverage(nextSamples.at(1));
            }

            cout << "Candidato A: ";
            if ((candidateANextMovingAverage / candidateAPreviousMovingAverage) - STABILITY > (1 + STABILITY))
                cout << "Alta" << endl;
            else if ((candidateANextMovingAverage / candidateAPreviousMovingAverage) - STABILITY < (1 - STABILITY))
                cout << "Baixa" << endl;
            else
                cout << "Estabilidade" << endl;

            cout << "Candidato B: ";
            if ((candidateBNextMovingAverage / candidateBPreviousMovingAverage) - STABILITY > (1 + STABILITY))
                cout << "Alta" << endl;
            else if ((candidateBNextMovingAverage / candidateBPreviousMovingAverage) - STABILITY < (1 - STABILITY))
                cout << "Baixa" << endl;
            else
                cout << "Estabilidade" << endl;
        }

        else if (option == "4") {

            vector<Estadual> states = nac.getStates();
            int highestACandidate = 0;
            int lowestACandidate = MAX_SAMPLES;
            int highestBCandidate = 0;
            int lowestBCandidate = MAX_SAMPLES;
            string highestACandidateState;
            string lowestACandidateState;
            string highestBCandidateState;
            string lowestBCandidateState;

            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                vector<vector<int>> samples = state.getSamples(0, 4);

                if (highestACandidate < calculateMovingAverage(samples.at(0))) {
                    highestACandidate = calculateMovingAverage(samples.at(0));
                    highestACandidateState = state.getName();
                }

                if (lowestACandidate > calculateMovingAverage(samples.at(0))) {
                    lowestACandidate = calculateMovingAverage(samples.at(0));
                    lowestACandidateState = state.getName();
                }

                if (highestBCandidate < calculateMovingAverage(samples.at(1))) {
                    highestBCandidate = calculateMovingAverage(samples.at(1));
                    highestBCandidateState = state.getName();
                }   

                if (lowestBCandidate > calculateMovingAverage(samples.at(1))) {
                    lowestBCandidate = calculateMovingAverage(samples.at(1));
                    lowestBCandidateState = state.getName();
                }
            }

            cout << "Maior alta do candidato A: " << highestACandidateState <<  " - " << highestACandidate << endl;
            cout << "Maior baixa do candidato A: " << lowestACandidateState << " - " << lowestACandidate << endl << endl;
            cout << "Maior alta do candidato B: " << highestBCandidateState <<  " - " << highestBCandidate << endl;
            cout << "Maior baixa do candidato B: " << lowestBCandidateState << " - " << lowestBCandidate << endl;
        }

        else if (option == "5") {
            int candidateALastMonth = 0;
            int candidateBLastMonth = 0;

            vector<Estadual> states = nac.getStates();
            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                vector<vector<int>> samples = state.getSamples(4, 4);
                candidateALastMonth += calculateMovingAverage(samples.at(0));
                candidateBLastMonth += calculateMovingAverage(samples.at(1));
            }

            if (candidateALastMonth > candidateBLastMonth)
                cout << "O candidato A está na frente com: " << candidateALastMonth << " votos." << endl;

            else if (candidateALastMonth < candidateBLastMonth) 
                cout << "O candidato B está na frente com: " << candidateBLastMonth << " votos." << endl;

            else
                cout << "Os candidatos estão empatados" << endl;
        }

        else if (option == "0") {
            cout << "Programa encerrado." << endl;
            exit(EXIT_SUCCESS);
        }

        else
            cout << "Opção inválida, tente novamente." << endl;

    } while (option != "0");

    return 0;
}
