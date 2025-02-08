#ifndef GATO_H
#define GATO_H

#include "AnimalDomestico.h"

class Gato : public AnimalDomestico
{
public:
    Gato(string nome, int idade, string raca, double peso, string vacinas, string comportamento, string porte, Pessoa &tutor);
    virtual ~Gato();
    string getRaca() const;
    string getComportamento() const;
    string getVacinas() const;
    string getPorte() const;
    void setVacinas(string vacinas);
    void setRaca(string raca);
    void setPorte(string porte);
    void setComportamento(string comportamento);

    virtual void imprime();

    virtual string getEspecie();
    string StatusVacinacao() const;

private:
    string raca;
    vector<string> vacinas;
    string comportamento;
    string porte;
};

#endif