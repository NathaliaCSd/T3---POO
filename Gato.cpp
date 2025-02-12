<<<<<<< HEAD
#include "Gato.h"

// Construtor da classe Gato. Inicializa as informações do gato e seu tutor,
// e processa as vacinas que foram fornecidas como uma string.
Gato::Gato(string nome, int idade, string raca, double peso, string vacinas, string comportamento, string porte, Pessoa& tutor)
: AnimalDomestico(nome, peso, idade, tutor), raca(raca), comportamento(comportamento), porte(porte)
{
    size_t pos = 0;
    string token;
    // Processa a string de vacinas separada por vírgulas
    while ((pos = vacinas.find(',')) != string::npos)
    {
        token = vacinas.substr(0, pos);  // Extrai a vacina até a vírgula
        this->vacinas.push_back(token);  // Adiciona a vacina à lista
        vacinas.erase(0, pos + 1);  // Remove a vacina já processada
    }
    // Adiciona a última vacina (sem vírgula)
    this->vacinas.push_back(vacinas);
}

// Destruidor da classe Gato
Gato::~Gato() {}

// Getter para a raça do gato
string Gato::getRaca() const
{
    return raca;
}

// Setter para a raça do gato
void Gato::setRaca(string raca)
{
    this->raca = raca;
}

// Getter para o comportamento do gato
string Gato::getComportamento() const
{   
    return comportamento;
}

// Getter para o porte do gato
string Gato::getPorte() const
{
    return porte;
}

// Setter para o porte do gato
void Gato::setPorte(string porte)
{
    this->porte = porte;
}

// Setter para o comportamento do gato
void Gato::setComportamento(string comportamento)
{
    this->comportamento = comportamento;
}

// Getter para as vacinas aplicadas ao gato
string Gato::getVacinas() const
{
    string vacinas_str;
    // Concatena todas as vacinas em uma string separada por vírgulas
    for (const auto &vacina : vacinas)
    {
        vacinas_str += vacina + ", ";
    }
    // Remove a última vírgula extra
    if (!vacinas_str.empty())
    {
        vacinas_str = vacinas_str.substr(0, vacinas_str.size() - 2); 
    }
    return vacinas_str;
}

// Setter para as vacinas do gato, que recebe uma string com vacinas separadas por vírgulas
void Gato::setVacinas(string vacinas)
{
    this->vacinas.clear();  // Limpa a lista de vacinas
    size_t pos = 0;
    string token;
    // Processa a string de vacinas separada por vírgulas
    while ((pos = vacinas.find(',')) != string::npos)
    {
        token = vacinas.substr(0, pos);  // Extrai a vacina até a vírgula
        this->vacinas.push_back(token);  // Adiciona a vacina à lista
        vacinas.erase(0, pos + 1);  // Remove a vacina já processada
    }
    // Adiciona a última vacina (sem vírgula)
    this->vacinas.push_back(vacinas);
}

// Método que verifica o status de vacinação do gato
string Gato::StatusVacinacao() const {
    // Retorna o status de vacinação baseado na lista de vacinas
    if (vacinas.empty()) {
        return "Animal não vacinado";
    } else {
        return "Vacinado";
    }
}

// Getter para a espécie do animal, sempre retorna "Felino"
string Gato::getEspecie() {
    return "Felino";
}

// Método para imprimir as informações do gato, incluindo as vacinas
void Gato::imprime() {
    AnimalDomestico::imprime();  // Imprime informações do animal base (nome, peso, idade)
    cout << "Raça: " << raca << endl;
    cout << "Porte do Animal: " << porte << endl;
    cout << "Comportamento: " << comportamento << endl;
    
    // Caso o comportamento seja "Agressivo", é dado um aviso extra
    if (comportamento == "Agressivo"){
        cout << "Necessário cuidado no manejo." << endl;
    }
    
    cout << "Vacinas aplicadas: " << endl;
    // Imprime todas as vacinas aplicadas
    for(int i = 0; i < vacinas.size(); i++){
        cout << vacinas[i] << endl;
    }
    
    // Exibe o status da vacinação
    cout << StatusVacinacao() << endl;
}
=======
#include "Gato.h"
#include <iostream>

Gato::Gato(int codigo, std::string nome, int idade, char sexo, float peso, bool ronroneia, bool usaCaixa, std::string raca, std::string pelo, Pessoa* tutor)
    : AnimalDomestico(codigo, nome, idade, sexo, peso, tutor), ronroneiaComFrequencia(ronroneia), usaCaixaDeAreia(usaCaixa), raca(raca), tipoPelo(pelo) {}

void Gato::exibirInfo() const {
    std::cout << "Gato: " << nomeAnimal << ", Idade: " << idade << " anos, Peso: " << peso << "kg\n";
    std::cout << "Ronroneia com frequencia: " << (ronroneiaComFrequencia ? "Sim" : "Nao") << "\n";
    std::cout << "Usa caixa de areia: " << (usaCaixaDeAreia ? "Sim" : "Nao") << "\n";
    std::cout << "Raca: " << raca << "\n";
    std::cout << "Tipo de pelo: " << tipoPelo << "\n";
    
    if (tutor != nullptr) {
        tutor->exibirInfo();  // Exibe as informações do tutor
    }
}
>>>>>>> 154301e (Trocando por trabalho refeito)
