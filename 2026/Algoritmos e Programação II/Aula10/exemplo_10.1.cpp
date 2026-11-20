#include <fstream>
#include <iostream>
using namespace std;

int main (){

    int x = 10;
    float vetor [] = { 10.5, 33.33, 15.8, 100.987};



    fstream meuArquivo;
    meuArquivo.open("arquivo.bin",ios::out | ios::binary);
    if(meuArquivo.is_open()) {
    meuArquivo.write((char *) &x, sizeof(x));
    meuArquivo.write((char *) &vetor, sizeof(vetor));
    meuArquivo.close();
    }
    else {
        cout << "Falha ao criar o arquivo\n";
    }

}
