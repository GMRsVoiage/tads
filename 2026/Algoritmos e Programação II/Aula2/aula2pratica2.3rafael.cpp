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



void exibirSaudacao(string nome, int hora) {

if (hora < 12)
        cout << "Bom dia, " << nome << ".\n";
    else if (hora < 18)
        cout << "Boa tarde, " << nome << ".\n";
    else
        cout << "Boa noite, " << nome << ".\n";
}

void verificarAprovacao(float nota1, float nota2) {

float notam = nota1 + nota2;
float notaf = notam / 2;

if (notaf >= 7.0)
    cout << "Aluno aprovado" << endl;
else
    cout << "Aluno em exame" << endl;
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

    // Realizar chamadas do procedimetno das saudacoes

    exibirSaudacao("Rafael", 6);
    exibirSaudacao("Rafael", 14);
    exibirSaudacao("Rafael", 21);

    verificarAprovacao(10, 5);
    verificarAprovacao(1,1);
    verificarAprovacao(10,0);

    cout << "Ano atual:" << anoatual << endl;


return 0;
}
