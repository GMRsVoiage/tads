#include <iostream>

using namespace std;

// Procedimento que exibe o conteudo  de um vetor
void exibirVetor(int vet[], int n){
    for(int i=0; i<n; i++){
        cout << vet[i] << " ";
    }
    cout << endl;
}

int main() {
    // Declarar um vetor de inteiros com 5 elementos e inicializar
    int valores[] = { 3, 10, 1, 7, 4 };

    // Exibir o vetor 'valores'
    exibirVetor(valores, 5);

        for(int i=0; i<5; i++){
            cout << "Digite o valor da posicao " << i << ":";
            cin >> valores[i];
        }

    // Exibir novamente o vetor
    exibirVetor(valores, 5);

return 0;
}
