#include <iostream>
#include <string>

int main () {

    bool firstRun = true;
    do {

        if (firstRun == true) {
            std::cout << "Bem-vindo ao portal das eleições." << std::endl;
            firstRun = false;
        }
        std::cout << "Por favor, selecione uma das opções abaixo:" << std::endl;
        std::cout << "1 - Evolução média das intenções de voto" << std::endl;
        std::cout << "2 - Alta, baixa e estabilidade dos candidatos por estado" << std::endl;
        std::cout << "3 - Alta, baixa e estabilidade dos candidatos no país" << std::endl;
        std::cout << "4 - Maior alta e maior baixa dos candidatos" << std::endl;
        std::cout << "5 - Qual candidato está na frente" << std::endl;
        std::cout << "0 - Encerrar o programa" << std::endl;

        // TODO use a char to do this, probably getchar
        std::string insertedOption = "";
        std::getline (std::cin, insertedOption);

        switch(insertedOption) {
            case 1:
                std::cout << "option 1" << std::endl;
            case 2:
                std::cout << "option 1" << std::endl;
            case 3:
                std::cout << "option 1" << std::endl;
            case 4:
                std::cout << "option 1" << std::endl;
            case 1:
                std::cout << "option 1" << std::endl;
            case 1:
                std::cout << "option 1" << std::endl;

            default:
                std::cout << "Opção inválida, tente novamente." << std::endl;
        }

    } while (insertedOption != 0);

    return 0;
}
