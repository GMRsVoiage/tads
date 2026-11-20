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
float valorFinal = preco - preco * percentual;

return valorFinal;
}

float convCelsiusToFahrenheit(float celsius){
float C = celsius;
float Fahrenheit = (C * 1.8) + 32;

return Fahrenheit;
}

int main(){
    // Invocar Menu
    exibirSystemHeader();

    cout << "Atividade 2.4 Calculo de desconto" << endl;
    // Declaracao de variaveis locais
    float valorProduto, percDesconto;

    // Ler os valores do usuario
    cout << "Digite o preco do produto: " << endl;
    cin >> valorProduto;
    cout << "Digite o percentual de desconto: ";
    cin >> percDesconto;
    cout << "Valor com desconto: " << calcularDesconto(valorProduto,percDesconto);

    cout << "Atividade 2.4 Celcius para Fahrenheit" << endl;
    float celsius;
    cout << "Coloque o valor em Celsius" << endl;
    cin >> celsius;
    cout << "A temperatura convertida em Fahrenheit ficou em: " << convCelsiusToFahrenheit(celsius) << endl;

return 0;
}
