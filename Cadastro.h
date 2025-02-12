#ifndef CADASTRO_H
#define CADASTRO_H

<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <vector>
#include "AnimalDomestico.h" 
#include "Pessoa.h" 

using namespace std;

class Cadastro {
private:
    // Vetores que armazenam os tutores e animais cadastrados
    vector<Pessoa*> tutores; 
    vector<AnimalDomestico*> animais; 
    string nomeArquivo; // Nome do arquivo onde os dados serão armazenados
    
    // Métodos privados responsáveis por buscar o índice do tutor e do animal
    int indiceTutor(int CPF); 
    int indiceAnimal(string nomeAnimal);
    
    // Método privado para salvar os dados no arquivo
    void salvarArquivo();
    
    // Método privado para carregar os dados do arquivo
    void carregarArquivo();

public:
    // Construtor que recebe o nome do arquivo a ser utilizado
    Cadastro(string fileName);
    
    // Destruidor responsável por liberar a memória alocada
    ~Cadastro();
    
    // Métodos públicos para adicionar tutor e animal
    bool adicionaTutor(Pessoa* novoTutor);
    bool adicionaAnimal(AnimalDomestico* animal, int cpfTutor);
    
    // Métodos públicos para imprimir informações sobre os tutores e animais
    void imprimeTutores() const;
    void imprimeAnimais() const;
    
    // Métodos públicos para remover tutor e animal
    bool removeTutor(int CPF);
    bool removeAnimal(string nomeAnimal);
    
    // Métodos públicos para atualizar os dados do tutor e do animal
    bool atualizaTutor(int CPF, string novoNome);
    bool atualizaAnimal(string nomeAnimal, string novoNome);
    
    // Métodos públicos para carregar e salvar dados
    void carregarDados();
    void salvarDados() const;
};

#endif /* CADASTRO_H */
=======
#include "AnimalDomestico.h"
#include "Pessoa.h"
#include <vector>
#include <string>

class Cadastro {
private:
    std::vector<AnimalDomestico*> animais;  // Vetor de ponteiros para animais

public:
    void adicionarAnimal(AnimalDomestico* animal);
    void listarAnimais() const;
    void removerAnimal(int codigo);
    void atualizarAnimal(int codigo);
    void salvarArquivo(const std::string& filename);
    void carregarArquivo(const std::string& filename);
};

#endif
>>>>>>> 154301e (Trocando por trabalho refeito)
