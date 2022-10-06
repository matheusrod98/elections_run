#include <iostream>
#include <string>
#include <cstdlib>

int main () {

    bool firstRun = true;
    std::string option = "";

    do {

        if (firstRun == true) {
            std::cout << "Bem-vindo ao portal das eleições presidenciais!" << std::endl;
            firstRun = false;
        }
        std::cout << "Por favor, selecione uma das opções abaixo:" << std::endl;
        std::cout << "1 - Evolução média das intenções de voto" << std::endl;
        std::cout << "2 - Alta, baixa e estabilidade dos candidatos por estado" << std::endl;
        std::cout << "3 - Alta, baixa e estabilidade dos candidatos no país" << std::endl;
        std::cout << "4 - Maior alta e maior baixa dos candidatos" << std::endl;
        std::cout << "5 - Qual candidato está na frente" << std::endl;
        std::cout << "0 - Encerrar o programa" << std::endl;
        std::getline(std::cin, option);

        if (option == "1") {
            std::cout << "Option 1" << std::endl;
        }
        if (option == "2") {
            std::cout << "Option 2" << std::endl;
        }
        if (option == "3") {
            std::cout << "Option 3" << std::endl;
        }
        if (option == "4") {
            std::cout << "Option 4" << std::endl;
        }
        if (option == "5") {
            std::cout << "Option 5" << std::endl;
        }
        if (option == "0") {
            std::cout << "Programa encerrado." << std::endl;
            exit(EXIT_SUCCESS);
        }
        else
            std::cout << "Opção inválida, tente novamente." << std::endl;

    } while (option != "0");

    return 0;
}