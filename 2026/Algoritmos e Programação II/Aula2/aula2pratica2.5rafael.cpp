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
int datahora(){
    // Codigo adaptado do W3Schools
    time_t timestamp = time(&timestamp);
    struct tm datetime = *localtime(&timestamp);
    // metodo encontrado para que eu consiga colocar o anoatual
    // (por algum motivo quando tentava puxar o ano, ficava como se fosse 126)
    int anoatual = datetime.tm_year + 1900;
    int anopassado = anoatual - 1;

    // Realizar chamadas do procedimetno das saudacoes

    cout << "Ano atual:" << anoatual << endl;

    return 0;
}

float calcularDesconto(float preco, float percentual){

float descon = preco * percentual;
float desconto = descon / 100;
float pdescontado = preco - desconto;

cout << "O desconto foi de: " << desconto << endl;
cout << "E o preco ficou entao: " << pdescontado << endl;

return 0;
}

int main(){
    // Invocar Menu
    exibirSystemHeader();

    calcularDesconto(2800, 0.26);


return 0;
}
