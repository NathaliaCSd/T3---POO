#ifndef ANIMALDOMESTICO_H
#define ANIMALDOMESTICO_H

#include <string>
#include <iostream>
using namespace std;

#include "Pessoa.h"

class AnimalDomestico {
public:
    AnimalDomestico(string nome, double peso, int idade, Pessoa& tutor);
    virtual ~AnimalDomestico();
    string getNome() const;
    void setNome(string nome);
    double getPeso() const;
    void setPeso(double peso);
    Pessoa& getTutor() const;
    void setDono(Pessoa* Tutor);
    virtual string getEspecie() const = 0; //metodo abstrato
    virtual void imprime() const;
private:
    Pessoa* tutor;
    string nome;
    double peso;
    int idade;

};

#endif 