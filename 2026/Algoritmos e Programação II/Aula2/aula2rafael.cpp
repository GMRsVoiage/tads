#include <iostream>
#include <ctime>

using namespace std;




void exibirSystemHeader(){
    cout << "************************************ () ||||   \n";
    cout << "* Instituto Federal Do Parana      * || ||     \n";
    cout << "************************************ || ||||   \n";
    cout << "************************************ || ||     \n";
    cout << "| Aulas Ministradas pelo           |\n";
    cout << "| Prof. Gregory | Disciplina de    |\n";
    cout << "| Algoritmos e Progamacao II       |\n";
    cout << "************************************\n";
    cout << "\n" << "\n";
}

int main(){
    // Invocar Menu
    exibirSystemHeader();

    // Codigo adaptado do W3Schools
    time_t timestamp = time(&timestamp);
    struct tm datetime = *localtime(&timestamp);
    // metodo encontrado para que eu consiga colocar o anoatual
    // (por algum motivo quando tentava puxar o ano, ficava como se fosse 126)
    int anoatual = datetime.tm_year + 1900;
    int anopassado = anoatual - 1;

    cout << "Ano atual:" << anoatual << endl;
    cout << "Ano passado: "<< anopassado << endl;

return 0;
}
