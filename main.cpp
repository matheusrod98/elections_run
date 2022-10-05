#include <iostream>

int main () {

    bool firstRun = true;
    do {

        if (firstRun = true) {
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

        char insertedOption = '';
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

while(run == true)
        {
    cout<<endl<<"1 = mean "<<endl;
    cout<<"2 = max/min "<<endl;
    cout<<"3 = sum "<<endl;
    cout<<"4 = quit "<<endl;
    cin >> choice;

    if (choice == 1)
    {
        cout<<endl<<"Mean = "<<avr<<endl;

    }
    else if (choice == 2)
    {
        cout<<endl<<"Max = "<<max<<endl<<"Min = "<<min<<endl;
    }
     else if (choice == 3)
    {
        cout<<endl<<"Sum = "<<sum<<endl;
    }
    else if (choice == 4)
    {
        run == false;
    }
    else
    {
        cout << "Error";
    }
