
#include <iostream>

using namespace std;

int header (){
    cout << "IFPR 12/08/2026" << endl << endl;
    cout << "Algoritmos e Programacao II" << " | Me. Gregory" << endl << endl;
    cout << "Atividade #3.1: Recursividade" << endl;
    cout << "Exercicio 1: Funcao dos numeros de Catalan" << endl << endl;

 return 1;
}

int catalan(int n){
    if (n == 0)
        return 1;

    else
        return (2*(2*n-1) * catalan(n-1))/ (n+1);

cout << n << endl;
}

int main(){
    header();
        cout << "Catalan de 3: " << catalan(3) << endl;
        cout << "Catalan de 4: " << catalan(4) << endl;
        cout << "Catalan de 8: " << catalan(8) << endl;
        cout << "Catalan de 10: " << catalan(10) << endl;

    return 1;
}
