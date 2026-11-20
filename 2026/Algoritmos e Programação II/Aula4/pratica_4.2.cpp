#include <iostream>
#include <random>

#include <cstdlib>
#include <ctime>

using namespace std;

// Inicializador da semente
srand(time(0));

// Exemplo de um numero de 1 até o 10
int x = 1 + rand() % 10;

void

int main {


cout << x << endl;
return 0;
}

// Procedimento que exibe o conteúdo de um vetor
/* codigo valido, mas a instalação do codeblocks no pc da escola tá com B.O


void exibirFrequencias(in t vet[], int n) {
    for(int i=2; i<n; i++) {
        cout << "Face " << i << ": " << vet[i] << " vezes\n";
    }
}

// Função que sorteia e retorna um número aleatório entre 2 e 12
int jogarDados() {
    random_device rd;

    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1,6);

    int somaDados = dist(gen);

    return somaDados;
}

int main() {
    // Declarar um vetor para registrar as frequencias
    int frequencias[13] = { 0 };

    // Realizar 1000 sorteios
    for(int cont=1; cont<=1000; cont++) {
        int soma = jogarDados();
        frequencias[soma]++;
    }

    // Exibir a frequencia de sorteio de cada face
    exibirFrequencias(frequencias,13);

    return 0;
}
*/
