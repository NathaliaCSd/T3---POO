#ifndef PEIXE_H
#define PEIXE_H

#include "AnimalDomestico.h"

class Peixe : public AnimalDomestico {
private:
    std::string escamas;
    std::string temperatura;
    std::string especie;

public:
    Peixe(int codigo, std::string nome, int idade, char sexo, float peso, std::string escamas, std::string temperatura, std::string especie, Pessoa* tutor);
    public:
    std::string getEscamas() const { return escamas; }
    std::string getTemperatura() const { return temperatura; }
    std::string getEspecie() const { return especie; }
    void exibirInfo() const override;
};

#endif
