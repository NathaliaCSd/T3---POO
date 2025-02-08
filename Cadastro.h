#ifndef CADASTRO_H
#define CADASTRO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

#include "AnimalDomestico.h"
#include "Pessoa.h"

enum TipoCadastro { Tutor = 1, Animal = 2 };

using namespace std;

class Cadastro {
private:
    int indice(int CPF);
    vector<Pessoa> tutor;
    string nomeArq;
    void grava(void* dados, size_t tamanho);
    void recupera();
public:
    Cadastro(string fileName);
    virtual ~Cadastro();
    void adiciona(int tipo);
    bool adicionaTutor();
    bool adicionaAnimal(const AnimalDomestico& animal, int cpfTutor);
    void imprime(int CPF);
    void remove(int tipo);
    bool removeTutor(int CPF);
    bool removeAnimal(const string &nomeAnimal);
    void atualiza(int tipo);
    bool atualizaTutor(int CPF);
    bool atualizaAnimal(string nome);
};


#endif /* CADASTRO_H */
