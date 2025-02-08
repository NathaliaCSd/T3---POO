#include "Pessoa.h"

Pessoa::Pessoa(string nome, int CPF) :
nome(nome), CPF(CPF) {
}

Pessoa::~Pessoa() {
}

string Pessoa::getNome() const {
    return nome;
}

void Pessoa::setNome(string nome) {
    this->nome = nome;
}

int Pessoa::getCPF() const {
    return CPF;
}

void Pessoa::setCPF(int CPF) {
    this->CPF = CPF;
}


void Pessoa::imprime() const{
    cout << "========== Nome do Tutor ==========" << endl;
    cout << "Nome:  " << nome << endl;
    cout << "CPF: " << CPF << endl;
}