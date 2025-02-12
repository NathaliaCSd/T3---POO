<<<<<<< HEAD
//REFERENTE AO DONO DO ANIMAL

#ifndef PESSOA_H  // Diretiva de pré-processamento para evitar inclusão múltipla do cabeçalho
#define PESSOA_H

#include <iostream>  
#include <algorithm>  
#include <vector>  

using namespace std;  // Para evitar o uso do prefixo 'std::' antes de tipos e funções da biblioteca padrão

// Definição da classe Pessoa
class Pessoa {
public:
    // Construtor da classe Pessoa. Inicializa o nome e a idade de uma pessoa
    Pessoa(string nome, int idade);

    // Destruidor da classe Pessoa. Usado para liberar recursos, se necessário
    virtual ~Pessoa();

    // Método para obter o nome da pessoa
    string getNome() const;

    // Método para definir o nome da pessoa
    void setNome(string nome);

    // Método para obter o CPF da pessoa
    int getCPF() const;

    // Método para definir o CPF da pessoa
    void setCPF(int CPF);

    // Método virtual para imprimir os dados da pessoa. Pode ser sobrescrito em classes derivadas
    virtual void imprime() const;

private:
    string nome;  // Atributo para armazenar o nome da pessoa
    int CPF;      // Atributo para armazenar o CPF da pessoa
};

#endif /* PESSOA_H */  // Fim da inclusão condicional do cabeçalho
=======
#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

class Pessoa {
private:
    std::string nome;
    std::string endereco;
    std::string telefone;

public:
    Pessoa(std::string nome, std::string endereco, std::string telefone);
    
    std::string getNome() const;
    std::string getEndereco() const;
    std::string getTelefone() const;
    
    void exibirInfo() const;
};

#endif
>>>>>>> 154301e (Trocando por trabalho refeito)
