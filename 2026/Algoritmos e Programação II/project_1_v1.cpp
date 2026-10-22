#include <iostream>
#include <limits>
#include <string>
#include <conio.h>

#define MAX 10

using namespace std;

struct Usuario {
    int matricula;
    string nome;
    int tipo; // 1 = Professor, 2 = Aluno
};

struct Livro {
    int codigo;
    string titulo;
    string autor;
    string edicao;
    int matriculaUsuario;
};

int buscarUsuario(Usuario usuarios[], int quantidade, int matricula) {
    for(int i = 0; i < quantidade; i++) {
        if(usuarios[i].matricula == matricula)
            return i;
    }
    return -1;
}

void cadastrarUsuario(Usuario usuarios[], int &quantidade) {
    if(quantidade == MAX) {
        cout << "Limite de usuarios atingido.\n\n";
        return;
    }

    int matricula;
    cout << "Digite a matricula: ";
    cin >> matricula;

    if(buscarUsuario(usuarios, quantidade, matricula) != -1) {
        cout << "Ja existe um usuario com essa matricula.\n\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Digite o nome: ";
    getline(cin, usuarios[quantidade].nome);

    int tipo;
    do {
        cout << "Tipo: Professor ou Aluno?\n";
        cout << "1 - Professor\n";
        cout << "2 - Aluno: \n\n";
        cout << "Digite sua opcao: ";
        cin >> tipo;

        if(tipo != 1 && tipo != 2)
            cout << "Opcao invalida. Digite 1 ou 2.\n";
    } while(tipo != 1 && tipo != 2);

    usuarios[quantidade].matricula = matricula;
    usuarios[quantidade].tipo = tipo;
    quantidade++;

    cout << "Usuario cadastrado.\n\n";
}

void mostrarUsuarios(Usuario usuarios[], int quantidade) {
    if(quantidade == 0) {
        cout << "Nenhum usuario cadastrado.\n\n";
        return;
    }

    cout << "Usuarios cadastrados:\n";
    for(int i = 0; i < quantidade; i++) {
        cout << "------------------------------\n";
        cout << "Matricula: " << usuarios[i].matricula << endl;
        cout << "Nome: " << usuarios[i].nome << endl;
        cout << "Tipo: ";

        if(usuarios[i].tipo == 1)
            cout << "Professor\n";
        else
            cout << "Aluno\n";
    }
    cout << "------------------------------\n\n";
}

void mostrarMenu() {
    cout << "^^^^^^^^^^^^^^^^^^^^^^ Menu ^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "1 - para cadastrar um Usuario.\n";/*
        ◦ Permite inserir os dados de um novo usuário.
        ◦ Deve impedir que dois usuários tenham a mesma matrícula.
        */
    cout << "2 - para cadastrar um Livro.\n\n";/*
        ◦ Permitir inserir os dados de um livro.
        ◦ Ao vincular com um usuário, obrigatoriamente o usuário já deve estar cadastrado.
        */
    cout << "3 - para mostrar os Usuarios cadastrados.\n";
    //  ◦ Exibir todos os usuários cadastrados (matrícula, nome, tipo).
    cout << "4 - para mostrar os Livros cadastrados.\n\n";
    //  ◦ Exibir todos os livros cadastrados com o nome do usuário para quem estão emprestados.
    cout << "5 - para buscar livros por usuarios.\n\n";
    //  ◦ Exibir os livros emprestados para um usuário específico (filtrar por matrícula).
    cout << "6 - Relatorio Geral.\n\n";
    //  ◦ Exibir quantos livros estão emprestados para cada usuário.


    cout << "0 - para sair.\n";
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
    cout << "Digite sua opcao: ";
}

int buscarLivro(Livro livros[], int quantidade, int codigo) {


    for(int i = 0; i < quantidade; i++) {
        if(livros[i].codigo == codigo)
            return i;
    }
    return -1;
}

void cadastrarLivro(Livro livros[], int &quantidade, Usuario usuarios[], int quantidadeUsuarios) {
    if(quantidade == MAX) {
        cout << "Limite de Livros atingido.\n\n";
        return;
    }

    int matriculaUsuario;
    cout << "Digite a matricula do usuario: ";
    cin >> matriculaUsuario;

    int indiceUsuario = buscarUsuario(usuarios, quantidadeUsuarios, matriculaUsuario);
    if(indiceUsuario == -1) {
        cout << "Usuario não encontrado.\n\n";
        return;
    }

    int codigo;
    cout << "Digite o codigo do livro: ";
    cin >> codigo;

    if(buscarLivro(livros, quantidade, codigo) != -1) {
        cout << "Ja existe um livro com esse codigo.\n\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Digite o nome do Livro: ";
    getline(cin, livros[quantidade].titulo);
    cout << "Digite o nome do Autor: ";
    getline(cin, livros[quantidade].autor);
    cout << "Digite a edicao do Livro: ";
    getline(cin, livros[quantidade].edicao);
    livros[quantidade].codigo = codigo;
    livros[quantidade].matriculaUsuario = matriculaUsuario;
    quantidade++;
}

void mostrarLivros(Livro livros[], int quantidade, Usuario usuarios[], int quantidadeUsuarios) {
    if(quantidade == 0) {
        cout << "Nenhum Livro cadastrado.\n\n";
        return;
    }

    cout << "Livros cadastrados:\n";
    for(int i = 0; i < quantidade; i++) {
        cout << "-----------------------------------\n";
        cout << "Codigo: " << livros[i].codigo << endl;
        cout << "Titulo: " << livros[i].titulo << endl;
        cout << "Autor: " << livros[i].autor << endl;
        cout << "Edicao: " << livros[i].edicao << endl;
        cout << "Matricula do Usuario: " << livros[i].matriculaUsuario << endl;
    }
    cout << "-----------------------------------\n";
}

int main() {
Usuario listaUsuarios[MAX];
Livro listaLivros[MAX];

int quantidadeUsuarios = 0;
int quantidadeLivros = 0;
int opcao;

    while(true) {
        mostrarMenu();
        cin >> opcao;

        if(opcao == 0)
            break;

        switch(opcao) {
            case 1:
                cadastrarUsuario(listaUsuarios, quantidadeUsuarios);
                break;
            case 2:
                cadastrarLivro(listaLivros, quantidadeLivros,
                listaUsuarios, quantidadeUsuarios);
                break;
            case 3:
                mostrarUsuarios(listaUsuarios, quantidadeUsuarios);
                break;
            case 4:
                mostrarLivros(listaLivros, quantidadeLivros, listaUsuarios, quantidadeUsuarios);
                break;
            default:
                cout << "Opcao invalida. Digite novamente.\n\n";
                break;
        }
        cout << "Pressione qualquer tecla para continuar";
        getch();
        system("cls");
    }

    return 0;
}
