//REFERENTE AO DONO DO ANIMAL

#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

class Pessoa {
public:
    Pessoa(string nome, int idade);
    virtual ~Pessoa();
    string getNome() const;
    void setNome(string nome);
    int getCPF() const;
    void setCPF(int CPF);
    virtual void imprime() const;
private:
    string nome;
    int CPF;
};

#endif /* PESSOA_H */