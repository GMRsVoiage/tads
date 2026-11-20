#include <iostream>
#include <fstream>
#include <strstring>

using namespace std;

struct cpu
{
    char fabricante[15];
    char modelo[15];
    float valor;
};

void PreencherVetor(cpu, vet[]

                    void salvar(cpu vet[], int n)
{
    fstream meuArquivo;

    meu Arquivo.i_open("cpu.bin", ios::out | ios::binary);
    if(meuArquivo.is_open())
    {
        meuArquivo.write((char *) &vet, sizeof(vet));
        meuArquivo.close();

        cout << "Dados salvos com sucesso!" << endl;

    }
    else
    {
        cout << "Não foi possível abrir o arquivo para escrita!" << endl;

    }
}

void carregar(cpu vet[], int n)
{
    fstream meuArquivo;

    meu Arquivo.i_open("cpu.bin", ios::in | ios::binary);
    if(meuArquivo.is_open())
    {
        meuArquivo.read((char *) &vet, sizeof(vet));
        meuArquivo.close();

        cout << "Dados lidos com sucesso!" << endl;

    }
    else
    {
        cout << "Não foi possível carregar as informações!" << endl;

    }
}

void mostrarVetor(cpu vet[], int n)
{
    cout << "Informações das CPUs: \n";
    for(int i=0; i<n; i++)
    {
        cout << "Fabricante: " << vet[i].fabricante << endl;
        cout << "Modelo: " << vet[i].modelo << endl;
        cout << "Valor: " << vet[i].valor << endl;
    }
}

void mostrarMenu()
{
    cout << "$#$#$#$#$#$#$ MENU $#$#$#$#$#$#$" << endl;
    cout << "1 - Para exibir informações de CPUs" << endl;
    cout << "2 - Para preencher informações de CPUs" << endl;
    cout << "3 - Para salvar informações de CPUs" << endl;
    cout << "4 - Para carregar informações de CPUs" << endl << endl;
    cout << "================================" << endl;
    cout << "0 - Para sair do programa" << endl;
    cout << "Digite a opção desejada: ";
}


int main()
{
    cpu listaCPUs[3];
    int opcao;

    cin >> opcao;
    while(opcao == 0)
        break;

    switch(opcao)
    {
    case 1:
        mostrarVetor(listaCPUs, 3);
        break;

        return 0;
    case 2:
        PreencherVetor(listaCPUs, 3);
        break;

        return 0;
    case 3:
        salvar(listaCPUs, 3);
        break;

        return 0;
    case 4:
        carregar(listaCPUs, 3);
        break;

        return 0;

    case 0:
        cout << "Saindo do programa..." << endl;
        break;
    }
}