#include "Pessoa.h"  

// Construtor da classe Pessoa
Pessoa::Pessoa(string nome, int CPF) :
    nome(nome), CPF(CPF) {  // Inicializa o nome e CPF com os valores fornecidos no momento da criação do objeto
}

// Destruidor da classe Pessoa
Pessoa::~Pessoa() {  // O destruidor não faz nada aqui, mas pode ser usado para liberar recursos caso necessário
}

// Método para obter o nome da pessoa
string Pessoa::getNome() const {
    return nome;  // Retorna o nome armazenado no objeto
}

// Método para definir o nome da pessoa
void Pessoa::setNome(string nome) {
    this->nome = nome;  // Define o nome da pessoa com o valor fornecido como argumento
}

// Método para obter o CPF da pessoa
int Pessoa::getCPF() const {
    return CPF;  // Retorna o CPF armazenado no objeto
}

// Método para definir o CPF da pessoa
void Pessoa::setCPF(int CPF) {
    this->CPF = CPF;  // Define o CPF da pessoa com o valor fornecido como argumento
}

// Método para imprimir as informações da pessoa
void Pessoa::imprime() const {
    cout << "========== Nome do Tutor ==========" << endl;  // Imprime um título para as informações
    cout << "Nome:  " << nome << endl;  // Imprime o nome da pessoa
    cout << "CPF: " << CPF << endl;  // Imprime o CPF da pessoa
}
