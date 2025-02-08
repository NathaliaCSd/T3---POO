#include "Cachorro.h"

// Construtor da classe Cachorro
// Inicializa os atributos específicos do Cachorro, além de chamar o construtor da classe base AnimalDomestico
Cachorro::Cachorro(string nome, int idade, string raca, double peso, string vacinas, string comportamento, string porte, Pessoa& tutor)
: AnimalDomestico(nome, peso, idade, tutor), raca(raca), comportamento(comportamento), porte(porte)
{
    // Para o vetor de vacinas, vamos dividir a string "vacinas" em um vetor
    // de vacinas separadas por vírgula, caso seja esse o formato que você espera.
    size_t pos = 0;
    string token;
    // Enquanto encontrar uma vírgula na string de vacinas
    while ((pos = vacinas.find(',')) != string::npos)
    {
        token = vacinas.substr(0, pos); // Extrai a vacina até a vírgula
        this->vacinas.push_back(token); // Adiciona a vacina ao vetor
        vacinas.erase(0, pos + 1); // Remove a vacina já processada da string original
    }
    // Adiciona a última vacina (caso não tenha vírgula no final)
    this->vacinas.push_back(vacinas);
}

// Destruidor da classe Cachorro (não há implementação adicional neste caso)
Cachorro::~Cachorro()
{
}

// Método para obter a raça do cachorro
string Cachorro::getRaca() const
{
    return raca; // Retorna a raça do cachorro
}

// Método para modificar a raça do cachorro
void Cachorro::setRaca(string raca)
{
    this->raca = raca; // Atribui a nova raça ao atributo
}

// Método para obter o comportamento do cachorro
string Cachorro::getComportamento() const
{   
    return comportamento; // Retorna o comportamento do cachorro
}

// Método para obter o porte do cachorro
string Cachorro::getPorte() const
{
    return porte; // Retorna o porte do cachorro
}

// Método para modificar a raça do cachorro
void Cachorro::setRaca(string raca)
{
    this->raca = raca; // Atribui a nova raça ao atributo
}

// Método para modificar o porte do cachorro
void Cachorro::setPorte(string porte)
{
    this->porte = porte; // Atribui o novo porte ao atributo
}

// Método para modificar o comportamento do cachorro
void Cachorro::setComportamento(string comportamento)
{
    this->comportamento = comportamento; // Atribui o novo comportamento ao atributo
}

// Método para obter as vacinas aplicadas no cachorro, retornando-as como uma string
string Cachorro::getVacinas() const
{
    string vacinas_str;
    // Concatena cada vacina com uma vírgula
    for (const auto &vacina : vacinas)
    {
        vacinas_str += vacina + ", ";
    }
    // Se a string resultante não estiver vazia, remove a vírgula extra no final
    if (!vacinas_str.empty())
    {
        vacinas_str = vacinas_str.substr(0, vacinas_str.size() - 2); 
    }
    return vacinas_str; // Retorna a string com as vacinas
}

// Método para modificar as vacinas do cachorro (similar ao construtor, processando a string separada por vírgulas)
void Cachorro::setVacinas(string vacinas)
{
    this->vacinas.clear(); // Limpa o vetor de vacinas atual
    size_t pos = 0;
    string token;
    // Enquanto encontrar uma vírgula na string de vacinas
    while ((pos = vacinas.find(',')) != string::npos)
    {
        token = vacinas.substr(0, pos); // Extrai a vacina até a vírgula
        this->vacinas.push_back(token); // Adiciona a vacina ao vetor
        vacinas.erase(0, pos + 1); // Remove a vacina já processada da string original
    }
    // Adiciona a última vacina (caso não tenha vírgula no final)
    this->vacinas.push_back(vacinas);
}

// Método para verificar o status da vacinação do cachorro
string Cachorro::StatusVacinacao() const
{
    if (vacinas.empty()) // Se o vetor de vacinas estiver vazio, significa que o animal não foi vacinado
    {
        return "Animal não vacinado";
    }
    else if (vacinas.size() != 0) // Se o vetor de vacinas não estiver vazio, há vacinas pendentes
    {
        return "Há vacinas Pendentes";
    }
    else // Caso contrário, o cachorro está vacinado
    {
        return "Vacinado";
    }
}

// Método para retornar a espécie do animal (no caso, "Cão")
string Cachorro::getEspecie()
{
    return "Cão"; // Retorna o nome da espécie
}

// Método para imprimir as informações sobre o cachorro
void Cachorro::imprime()
{
    AnimalDomestico::imprime(); // Chama o método imprime da classe base (AnimalDomestico)
    cout << "Raça: " << raca << endl; // Imprime a raça do cachorro
    cout << "Animal Porte " << porte << endl; // Imprime o porte do cachorro
    cout << "Comportamento: " << comportamento << endl; // Imprime o comportamento do cachorro
    if (comportamento == "Agressivo"){ // Se o comportamento for "Agressivo", imprime uma mensagem especial
        cout << "Necessário cuidado no manejo";
    }
    cout << "Vacinas aplicadas: " << endl;
    for(int i = 0; i < vacinas.size(); i++){ // Imprime cada vacina aplicada no cachorro
        cout << vacinas[i] << endl;
    }
    Cachorro::StatusVacinacao(); // Imprime o status da vacinação
}
