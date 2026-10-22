#include <iostream>
#include <limits>
#include <string>

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

void cadastrarLivro(Livro livros[], int &quantidade, Usuario usuarios[], int quantidadeUsuarios) {
    if(quantidade == MAX) {
        cout << "Limite de Livros atingido.\n\n";
        return;
    }

    int matriculaUsuario;
    cout << "Digite a matrícula do usuário: ";
    cin >> matriculaUsuario;

    int indiceUsuario = buscarUsuario(usuarios, quantidadeUsuarios, matriculaUsuario);
    if(indiceUsuario == -1) {
        cout << "Usuário não encontrado.\n\n";
        return;
    }

    int codigo;
    cout << "Digite o código do livro: ";
    cin >> codigo;

    if(buscarLivro(livros, quantidade, codigo) != -1) {
        cout << "Ja existe um livro com esse código.\n\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Digite o nome do Livro: ";
    getline(cin, livros[quantidade].titulo);
    cout << "Digite o nome do Autor: ";
    getline(cin, livros[quantidade].autor);
    cout << "Digite a edição do Livro: ";
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
        cout << "Código: " << livros[i].codigo << endl;
        cout << "Título: " << livros[i].titulo << endl;
        cout << "Autor: " << livros[i].autor << endl;
        cout << "Edição: " << livros[i].edicao << endl;
        cout << "Matrícula do Usuário: " << livros[i].matriculaUsuario << endl;
    }
    cout << "-----------------------------------\n";
}

void cadastrarProduto(Produto produtos[], int &quantidade,
                      TipoProduto tipos[], int quantidadeTipos) {
    if(quantidade == MAX) {
        cout << "Limite de Produtos atingido.\n\n";
        return;
    }

    if(quantidadeTipos == 0) {
        cout << "Cadastre um Tipo de Produto antes de cadastrar um Produto.\n\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Digite o nome do Produto: ";
    getline(cin, produtos[quantidade].nome);
    cout << "Digite o valor do Produto: ";
    cin >> produtos[quantidade].valor;

    cout << "Digite o ID do Tipo de Produto: ";
    cin >> produtos[quantidade].tipoProduto;
    if(buscarTipoProduto(tipos, quantidadeTipos, produtos[quantidade].tipoProduto) == -1) {
        cout << "Tipo de Produto nao encontrado. Cadastre um tipo valido.\n\n";
        return;
    }

    quantidade++;
}

void mostrarProdutos(Produto produtos[], int quantidade,
                     TipoProduto tipos[], int quantidadeTipos) {
    if(quantidade == 0) {
        cout << "Nenhum Produto cadastrado.\n\n";
        return;
    }

    cout << "Produtos cadastrados:\n";
    for(int i = 0; i < quantidade; i++) {
        int indiceTipo = buscarTipoProduto(tipos, quantidadeTipos,
                                           produtos[i].tipoProduto);
        cout << "-----------------------------------\n";
        cout << "Nome: " << produtos[i].nome << endl;
        cout << "Valor: " << produtos[i].valor << endl;
        cout << "Tipo de Produto: ";
        if(indiceTipo != -1)
            cout << tipos[indiceTipo].nome << " (ID: " << tipos[indiceTipo].id << ")\n";
        else
            cout << "nao encontrado (ID: " << produtos[i].tipoProduto << ")\n";
    }
    cout << "-----------------------------------\n";
}

int main() {
Usuario listaUsuarios[MAX];
Livro listaLivros[MAX];

int quantidadeUsuarios = 0;
int quantidadeLivros = 0;


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
                mostrarUsuarios(listaUsuarios, quantidadeUsuarios);
                break;
            case 3:
                cadastrarLivro(listaLivros, quantidadeLivros, listaUsuarios, quantidadeUsuarios);
                break;
            case 4:
                mostrarLivros(listaLivros, quantidadeLivros, listaUsuarios, quantidadeUsuarios);
                break;
            default:
                cout << "Opcao invalida. Digite novamente.\n\n";
                break;
        }
    }
c
    return 0;
}
