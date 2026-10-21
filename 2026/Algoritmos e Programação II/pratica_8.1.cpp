#include <iostream>
#include <limits>
#include <string>

#define MAX 10

using namespace std;

struct TipoProduto {
    int id;
    string nome;
};

struct Produto {
    string nome;
    double valor;
    int tipoProduto;
};

int buscarTipoProduto(TipoProduto tipos[], int quantidade, int id) {
    for(int i = 0; i < quantidade; i++) {
        if(tipos[i].id == id)
            return i;
    }
    return -1;
}

void mostrarMenu() {
    cout << "##################### MENU #####################\n";
    cout << "1 - para cadastrar um Tipo de Produto.\n";
    cout << "2 - para mostrar os Tipos de Produto cadastrados.\n";
    cout << "3 - para cadastrar um Produto.\n";
    cout << "4 - para mostrar os Produtos cadastrados.\n";
    cout << "0 - para sair.\n";
    cout << "################################################\n\n";
    cout << "Digite sua opcao: ";
}

void cadastrarTipoProduto(TipoProduto tipos[], int &quantidade) {
    if(quantidade == MAX) {
        cout << "Limite de Tipos de Produto atingido.\n\n";
        return;
    }

    int id;
    cout << "Digite o ID do Tipo de Produto: ";
    cin >> id;

    if(buscarTipoProduto(tipos, quantidade, id) != -1) {
        cout << "Ja existe um Tipo de Produto com esse ID.\n\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Digite o nome do Tipo de Produto: ";
    getline(cin, tipos[quantidade].nome);
    tipos[quantidade].id = id;
    quantidade++;
}

void mostrarTiposProduto(TipoProduto tipos[], int quantidade) {
    if(quantidade == 0) {
        cout << "Nenhum Tipo de Produto cadastrado.\n\n";
        return;
    }

    cout << "Tipos de Produto cadastrados:\n";
    for(int i = 0; i < quantidade; i++) {
        cout << "-----------------------------------\n";
        cout << "ID: " << tipos[i].id << endl;
        cout << "Nome: " << tipos[i].nome << endl;
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
    TipoProduto listaTipos[MAX];
    Produto listaProdutos[MAX];
    int quantidadeTipos = 0;
    int quantidadeProdutos = 0;
    int opcao;

    while(true) {
        mostrarMenu();
        cin >> opcao;

        if(opcao == 0)
            break;

        switch(opcao) {
            case 1:
                cadastrarTipoProduto(listaTipos, quantidadeTipos);
                break;
            case 2:
                mostrarTiposProduto(listaTipos, quantidadeTipos);
                break;
            case 3:
                cadastrarProduto(listaProdutos, quantidadeProdutos,
                                 listaTipos, quantidadeTipos);
                break;
            case 4:
                mostrarProdutos(listaProdutos, quantidadeProdutos,
                                listaTipos, quantidadeTipos);
                break;
            default:
                cout << "Opcao invalida. Digite novamente.\n\n";
                break;
        }
    }

    return 0;
}
