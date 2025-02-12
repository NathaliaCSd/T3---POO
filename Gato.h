<<<<<<< HEAD
#ifndef GATO_H
#define GATO_H

// Inclui o cabeçalho de "AnimalDomestico" para permitir herança
#include "AnimalDomestico.h"

// Definição da classe Gato que herda da classe AnimalDomestico
class Gato : public AnimalDomestico
{
public:
    // Construtor da classe Gato
    // Inicializa os atributos específicos do gato e o tutor (herdado de AnimalDomestico)
    Gato(string nome, int idade, string raca, double peso, string vacinas, string comportamento, string porte, Pessoa &tutor);

    // Destruidor da classe Gato
    virtual ~Gato();

    // Métodos getters para acessar os atributos privados
    string getRaca() const;             // Retorna a raça do gato
    string getComportamento() const;    // Retorna o comportamento do gato
    string getVacinas() const;          // Retorna as vacinas aplicadas ao gato
    string getPorte() const;            // Retorna o porte do gato

    // Métodos setters para modificar os atributos privados
    void setVacinas(string vacinas);    // Modifica as vacinas aplicadas ao gato
    void setRaca(string raca);          // Modifica a raça do gato
    void setPorte(string porte);        // Modifica o porte do gato
    void setComportamento(string comportamento); // Modifica o comportamento do gato

    // Método virtual para imprimir informações detalhadas sobre o gato
    virtual void imprime();

    // Método virtual que retorna a espécie do gato
    virtual string getEspecie();

    // Método que retorna o status de vacinação do gato
    string StatusVacinacao() const;

private:
    // Atributos privados da classe Gato
    string raca;              // Raça do gato
    vector<string> vacinas;   // Lista de vacinas aplicadas ao gato
    string comportamento;     // Comportamento do gato (ex: agressivo, calmo)
    string porte;             // Porte do gato (ex: pequeno, médio, grande)
};

#endif
=======
#ifndef GATO_H
#define GATO_H

#include "AnimalDomestico.h"

class Gato : public AnimalDomestico {
private:
    bool ronroneiaComFrequencia;
    bool usaCaixaDeAreia;
    std::string raca;
    std::string tipoPelo;

public:
    Gato(int codigo, std::string nome, int idade, char sexo, float peso, bool ronroneia, bool usaCaixa, std::string raca, std::string pelo, Pessoa* tutor);
    void exibirInfo() const override;
};

#endif
>>>>>>> 154301e (Trocando por trabalho refeito)
