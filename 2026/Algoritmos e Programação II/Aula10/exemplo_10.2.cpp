#include <fstream>
#include <iostream>
using namespace std;

int main (){
    int x;
    float vetor [4];



    fstream meuArquivo;
        meuArquivo.open("arquivo.bin",ios::in | ios::binary);
            if(meuArquivo.is_open()) {
                meuArquivo.read((char *) &x, sizeof(x));
                meuArquivo.read((char *) &vetor, sizeof(vetor));
                meuArquivo.close();
            }



cout << "X = " << x << endl;
cout << "Vetor = ";
    for(int i=0; i<4; i++){
        cout << vetor[i] << " ";
    }
}