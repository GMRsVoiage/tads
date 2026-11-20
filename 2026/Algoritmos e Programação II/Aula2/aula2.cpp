#include <iostream>

using namespace std;

void exibirMenu(){
    cout << "**********************\n";
    cout << "*        MENU        *\n";
    cout << "**********************\n";
    cout << "| 1    Cadastrar   1 |\n";
    cout << "| 2     Excluir    2 |\n";
    cout << "| 3      Sair      3 |\n";
    cout << "**********************\n";
    cout << "\n" << "\n";
}
// Retorno de valor fixo

float obterTaxaFixa(){
    return 0.15;
}


int main(){

    // Invocar Menu
    exibirMenu();

    // Chamada da função da Taxa Fixa que apenas exibe o valor da taxa
    cout << "Valor da taxa: " << obterTaxaFixa() << endl;

    float valor_bruto = 2000.00;
    float valor_taxado = valor_bruto * obterTaxaFixa();

    // Exibir valor taxado

    cout << "Valor da taxa: " << valor_taxado << endl;

return 0;
}
