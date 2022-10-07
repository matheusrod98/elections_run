#include <iostream>
#include <string>
#include <cstdlib>

#include "Nacional.hpp"
#include "Estadual.hpp"

#include "moving_average.hpp"

#define STABILITY_CRITERIA 0.02

int main () {

    bool firstRun = true;
    std::string option = "";

    Nacional nac;

    do {

        if (firstRun == true) {
            std::cout << "Bem-vindo ao portal das eleições presidenciais!" << std::endl;
            firstRun = false;
        }
        std::cout << std::endl;
        std::cout << "1 - Evolução média das intenções de voto" << std::endl;
        std::cout << "2 - Alta, baixa e estabilidade dos candidatos por estado" << std::endl;
        std::cout << "3 - Alta, baixa e estabilidade dos candidatos no país" << std::endl;
        std::cout << "4 - Maior alta e maior baixa dos candidatos" << std::endl;
        std::cout << "5 - Qual candidato está na frente" << std::endl;
        std::cout << "6 - Mostrar a base de dados" << std::endl;
        std::cout << "0 - Encerrar o programa" << std::endl;
        std::cout << "Por favor, selecione uma das opções abaixo: ";
        std::getline(std::cin, option);

        std::cout << std::endl;
        if (option == "1") {

            std::cout << "ESTADO    " << "Candidato A    " << "Candidato B    " << std::endl;
                        
            std::vector<Estadual> states = nac.getStates();
            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                std::vector<std::vector<int>> samples = state.getSamples(0, 4);
                std::cout << state.getName() << "         ";
                std::cout << calculateMovingAverage(samples.at(0)) << "          ";
                std::cout << calculateMovingAverage(samples.at(1)) << std::endl;
            }

            float candidateAMovingAverage = 0;
            float candidateBMovingAverage = 0;
            std::cout << "BRASIL     ";
            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                std::vector<std::vector<int>> samples = state.getSamples(0, 4);
                candidateAMovingAverage += calculateMovingAverage(samples.at(0));
                candidateBMovingAverage += calculateMovingAverage(samples.at(1));
            }
            std::cout << candidateAMovingAverage / 26 << "        ";
            std::cout << candidateBMovingAverage / 26 << std::endl;
        }

        else if (option == "2") {
            std::vector<Estadual> states = nac.getStates();
            std::vector<float> candidateAStability;
            std::vector<float> candidateBStability;

            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                std::vector<std::vector<int>> previousSamples = state.getSamples(0, 3);
                std::vector<std::vector<int>> nextSamples = state.getSamples(0, 4);
                candidateAStability.push_back(calculateMovingAverage(nextSamples.at(0)) / calculateMovingAverage(previousSamples.at(0)));
                candidateBStability.push_back(calculateMovingAverage(nextSamples.at(1)) / calculateMovingAverage(previousSamples.at(1)));
            }

            std::cout << "Candidato A" << std::endl;
            std::cout << "Alta: ";
            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                if (candidateAStability.at(stateIndex) - 1 > STABILITY_CRITERIA)
                    std::cout << state.getName() << " ";
            }
            std::cout << std::endl;

            std::cout << "Baixa: ";
            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                if (candidateAStability.at(stateIndex) - 1 < STABILITY_CRITERIA)
                    std::cout << state.getName() << " ";
            }
            std::cout << std::endl;

            std::cout << "Estabilidade: ";
            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                if ((candidateAStability.at(stateIndex) - 1 == STABILITY_CRITERIA))
                    std::cout << state.getName() << " ";
            }
            std::cout << std::endl;
            std::cout << std::endl;
            
            std::cout << "Candidato B" << std::endl;
            std::cout << "Alta: ";
            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                if (candidateBStability.at(stateIndex) - 1 > STABILITY_CRITERIA)
                    std::cout << state.getName() << " ";
            }
            std::cout << std::endl;

            std::cout << "Baixa: ";
            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                if (candidateBStability.at(stateIndex) - 1 < STABILITY_CRITERIA)
                    std::cout << state.getName() << " ";
            }
            std::cout << std::endl;

            std::cout << "Estabilidade: ";
            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                if ((candidateBStability.at(stateIndex) - 1 == STABILITY_CRITERIA))
                    std::cout << state.getName() << " ";
            }
            std::cout << std::endl;
        }

        else if (option == "3") {

        }

        else if (option == "4") {
            std::cout << "Option 4" << std::endl;
        }

        else if (option == "5") {
            std::cout << "Option 5" << std::endl;
        }

        else if (option == "6") {
            std::vector<Estadual> states = nac.getStates();
            for (int stateIndex = 0; stateIndex < 26; stateIndex++) {
                Estadual state = states.at(stateIndex);
                std::vector<std::vector<int>> samples = state.getSamples(0, 4);
                std::cout << state.getName() << "  ";

                std::vector<int> candidateASamples = samples.at(0);
                std::vector<int> candidateBSamples = samples.at(1);
                for (int monthIndex = 0; monthIndex < 5; monthIndex++) {
                    std::cout << candidateASamples.at(monthIndex) << "  ";
                    std::cout << candidateBSamples.at(monthIndex) << "  ";
                } 
                std::cout << std::endl;
            }
        }

        else if (option == "0") {
            std::cout << "Programa encerrado." << std::endl;
            exit(EXIT_SUCCESS);
        }

        else
            std::cout << "Opção inválida, tente novamente." << std::endl;

    } while (option != "0");

    return 0;
}
