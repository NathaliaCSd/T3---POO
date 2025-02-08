#ifndef CACHORRO_H
#define CACHORRO_H

// Inclusão do cabeçalho da classe base AnimalDomestico
#include "AnimalDomestico.h"

// A classe Cachorro herda de AnimalDomestico, representando um animal do tipo cachorro.
class Cachorro : public AnimalDomestico {
public:
    // Construtor da classe Cachorro. Inicializa os atributos do Cachorro e chama o construtor da classe base AnimalDomestico.
    Cachorro(string nome, int idade, string raca, double peso, string vacinas, string comportamento, string porte, Pessoa& tutor);
    
    // Destruidor da classe Cachorro. Não há implementação adicional neste caso.
    virtual ~Cachorro();
    
    // Métodos de acesso (getters) para os atributos específicos do Cachorro
    string getRaca() const;             // Retorna a raça do cachorro
    string getComportamento() const;   // Retorna o comportamento do cachorro
    string getVacinas() const;         // Retorna a lista de vacinas do cachorro em formato string
    string getPorte() const;           // Retorna o porte do cachorro
    
    // Métodos de modificação (setters) para os atributos específicos do Cachorro
    void setVacinas(string vacinas);   // Define as vacinas do cachorro
    void setRaca(string raca);         // Define a raça do cachorro
    void setPorte(string porte);       // Define o porte do cachorro
    void setComportamento(string comportamento); // Define o comportamento do cachorro
    
    // Método para imprimir informações sobre o cachorro
    virtual void imprime();
    
    // Método para retornar a espécie do animal (no caso, "Cão")
    virtual string getEspecie();
    
    // Método para verificar o status da vacinação do cachorro
    string StatusVacinacao() const;

private:
    // Atributos específicos do Cachorro
    string raca;                      // Raça do cachorro
    vector<string> vacinas;           // Vetor de vacinas aplicadas no cachorro
    string comportamento;             // Comportamento do cachorro 
    string porte;                     // Porte do cachorro 

#endif /* CACHORRO_H */
