
#include <iostream>

using namespace std;


int header (){
        cout << "IFPR 12/08/2026" << endl << endl;
        cout << "Algoritmos e Programacao II" << " | Me. Gregory" << endl << endl;
        cout << "Atividade #3.1: Recursividade" << endl;
        cout << "Exercicio 2: Pell" << endl << endl;
    return 1;
}

int pell (int n){
if (n == 0)
	return 0;

else if (n == 1)
	return 1;

else

	return (2* pell(n-1) + pell(n-2));

}



int main(){
    header();
        cout << "Pell de 3: " << pell(3) << endl;
        cout << "Pell de 5: " << pell(5) << endl;
        cout << "Pell de 8: " << pell(8) << endl;
        cout << "Pell de 9: " << pell(9) << endl;
return 1;
}
