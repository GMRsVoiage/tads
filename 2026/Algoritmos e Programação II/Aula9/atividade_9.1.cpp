#include <fstream>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Struct que representa um filme
struct Filme
{
    string titulo;
    string genero;
    int duracao;
};

// Exibe as opcoes do menu principal
void mostrarMenu()
{
    cout << "##################### MENU #####################\n";
    cout << "1 - Cadastrar informacoes de um filme\n";
    cout << "2 - Mostrar as informacoes do filme\n";
    cout << "3 - Salvar informacoes em um arquivo de texto\n";
    cout << "4 - Carregar informacoes do arquivo de texto\n";
    cout << "0 - Sair\n";
    cout << "################################################\n";
    cout << "Digite sua opcao: ";
}

// Le os dados do filme pelo teclado (passagem por referencia para alterar o original)
void cadastrarFilme(Filme &filme)
{
    // Limpa o '\n' deixado pelo cin >> opcao antes de usar getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Digite o titulo do filme: ";
    getline(cin, filme.titulo);
    while (filme.titulo == "")
    {
        cout << "O titulo nao pode ficar vazio. Digite novamente: ";
        getline(cin, filme.titulo);
    }

    cout << "Digite o genero do filme: ";
    getline(cin, filme.genero);
    while (filme.genero == "")
    {
        cout << "O genero nao pode ficar vazio. Digite novamente: ";
        getline(cin, filme.genero);
    }

    cout << "Digite a duracao do filme (em minutos): ";
    while (!(cin >> filme.duracao) || filme.duracao <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Duracao invalida. Digite um numero inteiro positivo: ";
    }

    cout << "Filme cadastrado com sucesso!\n\n";
}

// Mostra na tela os dados do filme atual
void mostrarFilme(Filme filme)
{
    if (filme.titulo == "")
    {
        cout << "Nenhum filme cadastrado ou carregado.\n\n";
        return;
    }

    cout << "-----------------------------------\n";
    cout << "Titulo: " << filme.titulo << endl;
    cout << "Genero: " << filme.genero << endl;
    cout << "Duracao: " << filme.duracao << " minutos\n";
    cout << "-----------------------------------\n\n";
}

// Salva os dados no arquivo "filme.txt" sobrescrevendo o conteudo anterior
void salvarFilme(Filme filme)
{
    if (filme.titulo == "")
    {
        cout << "Nenhum filme para salvar. Cadastre ou carregue um filme primeiro.\n\n";
        return;
    }

    fstream meuArquivo;
    // ios::out abre para escrita e ios::trunc apaga o conteudo anterior (sobrescreve)
    meuArquivo.open("filme.txt", ios::out | ios::trunc);

    if (meuArquivo.is_open())
    {
        meuArquivo << filme.titulo << endl;
        meuArquivo << filme.genero << endl;
        meuArquivo << filme.duracao << endl;
        meuArquivo.close();

        cout << "Informacoes salvas em filme.txt com sucesso!\n\n";
    }
    else
    {
        cout << "Nao foi possivel abrir o arquivo para salvar.\n\n";
    }
}

// Carrega os dados de "filme.txt" para a struct filme
void carregarFilme(Filme &filme)
{
    fstream meuArquivo;
    // ios::in abre o arquivo para leitura
    meuArquivo.open("filme.txt", ios::in);

    if (meuArquivo.is_open())
    {
        string titulo;
        string genero;
        string duracaoTexto;

        if (getline(meuArquivo, titulo) &&
            getline(meuArquivo, genero) &&
            getline(meuArquivo, duracaoTexto))
        {
            filme.titulo = titulo;
            filme.genero = genero;
            // Converte a duracao lida como texto para inteiro
            filme.duracao = stoi(duracaoTexto);

            cout << "Informacoes carregadas do arquivo com sucesso!\n\n";
        }
        else
        {
            cout << "Arquivo vazio ou com formato invalido.\n\n";
        }

        meuArquivo.close();
    }
    else
    {
        cout << "Nao foi possivel abrir o arquivo filme.txt.\n\n";
    }
}

int main()
{
    Filme meuFilme = {"", "", 0};
    int opcao;

    while (true)
    {
        mostrarMenu();

        if (!(cin >> opcao))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcao invalida. Digite um numero de 0 a 4.\n\n";
            continue;
        }

        if (opcao == 0)
        {
            cout << "Encerrando o programa...\n";
            break;
        }

        switch (opcao)
        {
        case 1:
            cadastrarFilme(meuFilme);
            break;
        case 2:
            mostrarFilme(meuFilme);
            break;
        case 3:
            salvarFilme(meuFilme);
            break;
        case 4:
            carregarFilme(meuFilme);
            break;
        default:
            cout << "Opcao invalida. Digite novamente.\n\n";
            break;
        }
    }

    return 0;
}
