#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void mostrarMenu()
{
    cout << "************************************\n";
    cout << "*              MENU                *\n";
    cout << "************************************\n";
    cout << "************************************\n";
    cout << "| 1 - Para gerar o vetor.      - 1 |\n";
    cout << "| 2 - Para exibir o vetor.     - 2 |\n";
    cout << "| 3 - Para mostrar o maior     - 3 |\n";
    cout << "|     valor do vetor               |\n";
    cout << "| 4 - Para buscar um           - 4 |\n";
    cout << "|     numero no vetor              |\n";
    cout << "| 0 - Para Encerrar.           - 0 |\n";
    cout << "************************************\n";
    cout << "\n" << "\n";
}

int main()
{
    // Assistencia por IA pois tudo que o professor falou foi pra evitar o cstdlib :P
    srand(time(0));


    int opcao;

    int num[20] =
    {
        0
    };

    while(true)
    {
        mostrarMenu();
        cin>> opcao;

        if(opcao == 0)
            break;

        switch(opcao)
        {
        case 1:
            // Preencher o vetor com números aleatórios

            break;
        case 2:
            // Exibir o vetor
            for(int i=0; i<20; i++)
            {
                cout << num[i] << " ";
            }
            cout << endl;
            break;
        case 3:
        {
            int maior = num[0];
            for(int i = 1; i < 20; i++)
            {
                if(num[i] > maior)
                {
                    maior = num[i];
                }
            }
            cout << "O maior valor encontrado no vetor e: " << maior << "\n";
        }


        break;
        case 4:
                // Buscar um número X no vetor
                {
                    int x;
                    cout << "Digite um valor para buscar (1 a 100): ";
                    cin >> x;

                    int posicaoEncontrada = -1; // -1 indica que não foi encontrado

                    for(int i = 0; i < 20; i++)
                    {
                        if(num[i] == x)
                        {
                            posicaoEncontrada = i;
                            break; // Interrompe no primeiro que encontrar
                        }
                    }

                    if(posicaoEncontrada != -1)
                    {
                        cout << "O valor " << x << " existe no vetor na primeira posicao: " << posicaoEncontrada << "\n\n";
                    }
                    else
                    {
                        cout << "O valor " << x << " nao foi encontrado no vetor.\n\n";
                    }
                }
            break;
        default:
            cout << "Opcao invalida. Vire gente.\n" << "\n";
            break;
        }

    }
    return 0;
}
