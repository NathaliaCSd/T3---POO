<<<<<<< HEAD
#include "AnimalDomestico.h"

// Construtor da classe AnimalDomestico
// Inicializa os atributos do animal (nome, peso, idade) e associa um tutor (Pessoa)
AnimalDomestico::AnimalDomestico(string nome, double peso, int idade, Pessoa &tutor)
: nome(nome), peso(peso), idade(idade), tutor(&tutor) // Inicialização da lista de membros
{
}

// Destruidor da classe AnimalDomestico
// Neste caso, não há nenhum recurso alocado dinamicamente, então o destruidor não faz nada
AnimalDomestico::~AnimalDomestico()
{
}

// Método para obter o nome do animal
string AnimalDomestico::getNome() const
{
    return nome; // Retorna o nome do animal
}

// Método para obter o peso do animal
double AnimalDomestico::getPeso() const
{
    return peso; // Retorna o peso do animal
}

// Método para modificar o nome do animal
void AnimalDomestico::setNome(string nome)
{
    this->nome = nome; // Atribui o novo nome ao atributo nome
}

// Método para modificar o peso do animal
void AnimalDomestico::setPeso(double peso)
{
    this->peso = peso; // Atribui o novo peso ao atributo peso
}

// Método para obter o tutor (Pessoa) do animal
Pessoa &AnimalDomestico::getTutor() const
{
    return tutor; // Retorna o tutor associado ao animal
}

// Método para imprimir as informações do animal
void AnimalDomestico::imprime() const
{
    cout << "Espécie: " << this->getEspecie() << endl; // Imprime a espécie do animal (método getEspecie deve ser implementado em uma classe derivada)
    cout << "Nome: " << this->nome << endl; // Imprime o nome do animal
    cout << "Peso: " << this->peso << endl; // Imprime o peso do animal
}
=======
#include "AnimalDomestico.h"
#include <iostream>

AnimalDomestico::AnimalDomestico(int codigo, std::string nome, int idade, char sexo, float peso, Pessoa* tutor)
    : codigoRegistro(codigo), nomeAnimal(nome), idade(idade), sexo(sexo), peso(peso), tutor(tutor) {}

int AnimalDomestico::getCodigoRegistro() const {
    return codigoRegistro;
}

void AnimalDomestico::setIdade(int idade) {
    this->idade = idade;
}

void AnimalDomestico::setPeso(float peso) {
    this->peso = peso;
}

Pessoa* AnimalDomestico::getTutor() const {
    return tutor;
}

void AnimalDomestico::setTutor(Pessoa* novoTutor) {
    tutor = novoTutor;
}
>>>>>>> 154301e (Trocando por trabalho refeito)
