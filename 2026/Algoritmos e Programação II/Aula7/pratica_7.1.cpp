#include <iostream>

using namespace std;

// Definir uma struct (registro) para representar um estudante
struct Estudante {
    string nome;
    int idade;
    string matricula;
};

int main() {
    // Declarar uma variável de Estudante e inicializar os valores de seus campos
    Estudante meuEstudante = {"Gregory", 42, "21341234"};

    // Exibir os valores dos campos do(a) estudante
    cout << "Valores iniciais...\n";
    cout << "Nome: " << meuEstudante.nome << endl;
    cout << "Idade: " << meuEstudante.idade << endl;
    cout << "Matrícula: " << meuEstudante.matricula << endl;

    // Alterar a idade e a matrícula do estudante
    meuEstudante.idade = 43;
    meuEstudante.matricula = "313241234";

    // Exibir os alterados dos campos do(a) estudante
    cout << "\n\nValores finais...\n";
    cout << "Nome: " << meuEstudante.nome << endl;
    cout << "Idade: " << meuEstudante.idade << endl;
    cout << "Matrícula: " << meuEstudante.matricula << endl;


    return 0;
}
