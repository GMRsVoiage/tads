#include <iostream>
#include <limits>

using namespace std;

// Definir uma struct para representar uma data
struct Data {
    int dia;
    int mes;
    int ano;
};

// Definir uma struct para representar uma pessoa
struct Pessoa {
    string nome;
    string endereco;
    Data dataNascimento;
};

// Procedimento que exibe um menu para o usuário
void mostrarMenu() {
    cout << "################### MENU ###################\n";
    cout << "1 - para cadastrar uma pessoa.\n";
    cout << "2 - para exibir a pessoa cadastrada.\n";
    cout << "0 - para sair.\n";
    cout << "############################################\n";
    cout << "Digite sua opcao: ";
}

// Procedimento para mostrar as informações de uma pessoa
void exibirPessoa(Pessoa p) {
    cout << "Informacoes da pessoa...\n";
    cout << "Nome: " << p.nome << endl;
    cout << "Endereco: " << p.endereco << endl;
    cout << "Data de Nascimento: " << p.dataNascimento.dia << "/"
         << p.dataNascimento.mes << "/" << p.dataNascimento.ano << endl;
}

// Procedimento para cadastrar as informações de uma pessoa
void cadastrarPessoa(Pessoa *p) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Digite o nome: ";
    getline(cin, p->nome);
    cout << "Digite o endereco: ";
    getline(cin, p->endereco);
    // Solicitar a data de nascimento
    cout << "Digite o dia, mes e ano de nascimento (separados por espaco):";
    cin >> p->dataNascimento.dia >> p->dataNascimento.mes >> p->dataNascimento.ano;
}

int main() {
    int opcao;
    Pessoa minhaPessoa;

    while(true) {
        mostrarMenu();
        cin >> opcao;

        if(opcao == 0)
            break;

        switch(opcao) {
            case 1:
                cadastrarPessoa(&minhaPessoa);
                break;
            case 2:
                exibirPessoa(minhaPessoa);
                break;
            default:
                cout << "Opcao invalida. Digite novamente...\n";
                break;
        }
    }

    return 0;
}
