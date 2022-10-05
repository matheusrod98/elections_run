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
            
        switch(option.at(0)) {
            case '1':
                std::cout << "option 1" << std::endl;
                break;
            case '2':
                std::cout << "option 2" << std::endl;
                break;
            case '3':
                std::cout << "option 3" << std::endl;
                break;
            case '4':
                std::cout << "option 4" << std::endl;
                break;
            case '5':
                std::cout << "option 5" << std::endl;
                break;
            case '0':
                std::cout << "Programa encerrado." << std::endl;
                exit (EXIT_SUCCESS);

            default:
                std::cout << "Opção inválida, tente novamente." << std::endl;
        }

    } while (option.at(0) != 0);

    return 0;
}
