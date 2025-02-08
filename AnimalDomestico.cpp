#include "AnimalDomestico.h"

AnimalDomestico::AnimalDomestico(string nome, double peso, int idade, Pessoa &tutor)
: nome(nome), peso(peso), idade(idade), tutor(&tutor)
{
}

AnimalDomestico::~AnimalDomestico()
{
}

string AnimalDomestico::getNome() const
{
    return nome;
}

double AnimalDomestico::getPeso() const
{
    return peso;
}

void AnimalDomestico::setNome(string nome)
{
    this->nome = nome;
}

void AnimalDomestico::setPeso(double peso)
{
    this->peso = peso;
}

Pessoa &AnimalDomestico::getTutor() const
{
    return tutor;
}

void AnimalDomestico::imprime() const
{
    cout << "Espécie: " << this->getEspecie() << endl;
    cout << "Nome: " << this->nome << endl;
    cout << "Peso: " << this->peso << endl;
}
