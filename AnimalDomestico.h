<<<<<<< HEAD
#ifndef ANIMALDOMESTICO_H  
#define ANIMALDOMESTICO_H  

#include <string>  
#include <iostream> 
using namespace std;  

#include "Pessoa.h"  

// Definição da classe AnimalDomestico
class AnimalDomestico {
public:
    // Construtor da classe AnimalDomestico
    // Inicializa os atributos nome, peso, idade e tutor
    AnimalDomestico(string nome, double peso, int idade, Pessoa& tutor);

    // Destruidor virtual, necessário para destruição adequada em classes derivadas
    virtual ~AnimalDomestico();

    // Método para obter o nome do animal
    string getNome() const;

    // Método para modificar o nome do animal
    void setNome(string nome);

    // Método para obter o peso do animal
    double getPeso() const;

    // Método para modificar o peso do animal
    void setPeso(double peso);

    // Método para obter o tutor do animal
    Pessoa& getTutor() const;

    // Método para modificar o tutor do animal
    void setDono(Pessoa* Tutor);

    // Método abstrato para retornar a espécie do animal (deve ser implementado nas classes derivadas)
    virtual string getEspecie() const = 0;

    // Método para imprimir as informações do animal
    virtual void imprime() const;

private:
    Pessoa* tutor;  // Ponteiro para o tutor do animal, representando a relação entre o animal e a pessoa responsável
    string nome;    // Atributo para armazenar o nome do animal
    double peso;    // Atributo para armazenar o peso do animal
    int idade;      // Atributo para armazenar a idade do animal
};

#endif  // Fim da definição condicional do cabeçalho ANIMALDOMESTICO_H
=======
#ifndef ANIMALDOMESTICO_H
#define ANIMALDOMESTICO_H

#include <string>
#include "Pessoa.h"  // Importa a classe Pessoa

class AnimalDomestico {
protected:
    int codigoRegistro;
    std::string nomeAnimal;
    int idade;
    char sexo;
    float peso;
    Pessoa* tutor;  // Ponteiro para o tutor

public:
    AnimalDomestico(int codigo, std::string nome, int idade, char sexo, float peso, Pessoa* tutor = nullptr);
    virtual ~AnimalDomestico() = default;

    virtual void exibirInfo() const = 0;
    int getCodigoRegistro() const;
    void setIdade(int idade);
    void setPeso(float peso);
    Pessoa* getTutor() const;  // Getter do tutor
    void setTutor(Pessoa* novoTutor);  // Setter do tutor
};

#endif
>>>>>>> 154301e (Trocando por trabalho refeito)
