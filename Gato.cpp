#include "Gato.h"

Gato::Gato(string nome, int idade, string raca, double peso, string vacinas, string comportamento, string porte, Pessoa& tutor)
: AnimalDomestico(nome, peso, idade, tutor), raca(raca), comportamento(comportamento), porte(porte)
{
    size_t pos = 0;
    string token;
    while ((pos = vacinas.find(',')) != string::npos)
    {
        token = vacinas.substr(0, pos);
        this->vacinas.push_back(token);
        vacinas.erase(0, pos + 1);
    }
    // Adiciona a última vacina
    this->vacinas.push_back(vacinas);
}

Gato::~Gato()
{
}

string Gato::getRaca() const
{
    return raca;
}

void Gato::setRaca(string raca)
{
    this->raca = raca;
}

string Gato::getComportamento() const
{   
    return comportamento;
}
string Gato::getPorte() const
{
    return porte;
}
void Gato::setRaca(string raca)
{
    this->raca = raca;
}
void Gato::setPorte(string porte)
{
    this->porte = porte;
}
void Gato::setComportamento(string comportamento)
{
    this->comportamento = comportamento;
}

string Gato::getVacinas() const
{
    string vacinas_str;
    for (const auto &vacina : vacinas)
    {
        vacinas_str += vacina + ", ";
    }
    if (!vacinas_str.empty())
    {
        vacinas_str = vacinas_str.substr(0, vacinas_str.size() - 2); // Remove a vírgula extra no final
    }
    return vacinas_str;
}

void Gato::setVacinas(string vacinas)
{
    this->vacinas.clear();
    size_t pos = 0;
    string token;
    while ((pos = vacinas.find(',')) != string::npos)
    {
        token = vacinas.substr(0, pos);
        this->vacinas.push_back(token);
        vacinas.erase(0, pos + 1);
    }
    // Adiciona a última vacina
    this->vacinas.push_back(vacinas);
}

string Gato::StatusVacinacao() const {
    if (vacinas.empty()) {
        return "Animal não vacinado";
    } else if (vacinas.size() > 0) {
        return "Vacinado";
    }
}

string Gato::getEspecie() {
    return "Felino";
}

void Gato::imprime() {
    AnimalDomestico::imprime();
    cout << "Raça: " << raca << endl;
    cout << "Animal Porte " << porte << endl;

    cout << "Comportamento: " << comportamento << endl;
    if (comportamento == "Agressivo"){
        cout << "Necessário cuidado no manejo";
    }
    cout << "Vacinas aplicadas" << endl;
    for(int i = 0; i < vacinas.size(); i++){
        cout << vacinas[i] << endl;
    }
    Gato::StatusVacinacao(); 
}