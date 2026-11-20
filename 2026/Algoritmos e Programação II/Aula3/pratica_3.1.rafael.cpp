#include <iostream>

using namespace std;


int header (){
 cout <<"Teste" << endl;

 return 1;
}
// Função recursiva para cálculo do fatorial
int fat (int n) {
    // Caso base (mais simples) => resposta direta
    if (n == 0 || n == 1)
            return 1;

    return n * fat(n-1);
}

int main(){
    header();

    int x = 4;

    cout << x << "!  = " << fat(x) << endl;

return 0;
}
