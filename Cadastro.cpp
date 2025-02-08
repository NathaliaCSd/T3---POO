#include "Cadastro.h"

int Cadastro::indice(int CPF) {
    long unsigned int tam = tutor.size();
    long unsigned int pos = 0;

    while (pos < tam && tutor[pos]->getCPF() != CPF) {
        pos++;
    }

    if (pos < tam) {
        return pos;
    } else {
        return -1;
    }
}

void Cadastro::grava(void* dados, size_t tamanho) {
    ofstream arquivo(nomeArq, ios::app | ios::binary);
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo para gravação." << endl;
        return;
    }
    arquivo.write(reinterpret_cast<char*>(dados), tamanho);
    arquivo.close();
}


void Cadastro::recupera() {
    ifstream arquivo(nomeArq, ios::in | ios::binary);
    while (arquivo.read(reinterpret_cast<char*>(&tutor), sizeof(Pessoa))) {
        cout << "Nome: " << tutor.getNome() << ", CPF: " << tutor.getCPF() << endl;
    }
    arquivo.close();
}

bool Cadastro::adiciona(int tipo) {
    if (tipo == Tutor) {
        string nome;
        int CPF;

        cout << "Nome do Tutor: ";
        cin.ignore();
        getline(cin, nome);

        cout << "CPF do Tutor: ";
        cin >> CPF;

        Pessoa novoTutor(nome, CPF);
        grava(&novoTutor, sizeof(Pessoa));  // Grava o tutor usando o método genérico

        cout << "Tutor cadastrado com sucesso!" << endl;
        return true;

    } else if (tipo == Animal) {
        string nomeAnimal, especie;
        double peso;
        int idade, CPF;

        cout << "Nome do Animal: ";
        cin.ignore();
        getline(cin, nomeAnimal);

        cout << "Espécie (Cachorro/Felino): ";
        getline(cin, especie);

        cout << "Peso do Animal: ";
        cin >> peso;

        cout << "Idade do Animal: ";
        cin >> idade;

        cout << "CPF do Tutor do Animal: ";
        cin >> CPF;

        // Verifica se o tutor existe
        if (indice(CPF) == -1) {
            cout << "Tutor não encontrado. Cadastre o tutor primeiro." << endl;
            return false;
        }

        AnimalDomestico novoAnimal(nomeAnimal, peso, idade, CPF);
        grava(&novoAnimal, sizeof(AnimalDomestico));  // Grava o animal usando o método genérico

        cout << "Animal cadastrado com sucesso!" << endl;
        return true;
    }

    cout << "Tipo de cadastro inválido." << endl;
    return false;
}


bool Cadastro::adicionaTutor(const Pessoa& novoTutor) {
    // Verifica se o tutor já está cadastrado pelo CPF
    for (const auto& tutor : tutor) {
        if (tutor.getCPF() == novoTutor.getCPF()) {
            cout << "Tutor com este CPF já está cadastrado." << endl;
            return false;
        }
    }

    // Adiciona o novo tutor ao vetor
    tutor.push_back(novoTutor);

    // Grava no arquivo para persistência
    grava();

    cout << "Tutor cadastrado com sucesso!" << endl;
    return true;
}

bool Cadastro::adicionaAnimal(const AnimalDomestico& animal, int cpfTutor) {
    Pessoa* tutor = buscaTutor(cpfTutor);
    if (tutor != nullptr) {
        tutor->adicionaAnimal(animal); // Supondo que a classe Pessoa tenha um vetor de animais
        grava();  // Salva o novo estado no arquivo
        return true;
    } else {
        cout << "Tutor não encontrado. Cadastre o tutor primeiro." << endl;
        return false;
    }
}


void Cadastro::imprime(int CPF) {
    int pos = indice(CPF);
    if (pos != -1) {
        cout << "Nome: " << tutor.getNome() << ", CPF: " << tutor.getCPF() << endl;
    } else {
        cout << "Registro nao encontrado." << endl;
    }
}

void Cadastro::remove(int tipo) {
    cout << "Informe a informacao de quem voce quer REMOVER:" << endl;
   cout << "[1] - Tutor" << endl;
   cout << "[2] - Animal" << endl;
    if (tipo == 1) {
        int cpf;
        cout << "Digite o CPF do tutor: ";
        cin >> cpf;
        cin.ignore();  // Limpar o buffer

        if (removeTutor(cpf)) {
            cout << "Tutor REMOVIDO com sucesso." << endl;
        } else {
            cout << "Tutor não encontrado." << endl;
        }
    } else if (tipo == 2) {
        string nomeAnimal;
        cout << "Digite o nome do animal: ";
        cin.ignore();  // Limpar o buffer
        getline(cin, nomeAnimal);

        if (removeAnimal(nomeAnimal)) {
            cout << "Animal REMOVIDO com sucesso." << endl;
        } else {
            cout << "Animal não encontrado." << endl;
        }
    }
}

bool Cadastro::removeTutor(int CPF) {
    int pos = indice(CPF);
    if (pos == -1) return false;

    fstream arquivo(nomeArq, ios::in | ios::out | ios::binary);
    arquivo.seekg(pos * sizeof(Pessoa));
    arquivo.read(reinterpret_cast<char*>(&tutor), sizeof(Pessoa));

    tutor.setNome("REMOVIDO");  // Marca o registro como removido
    arquivo.seekp(pos * sizeof(Pessoa));
    arquivo.write(reinterpret_cast<char*>(&tutor), sizeof(Pessoa));

    arquivo.close();
    return true;
}

bool Cadastro::removeAnimal(const string& nomeAnimal) {
    int pos = indice(nomeAnimal);
    if (pos == -1) return false;

    AnimalDomestico animal; // Supondo que você tenha essa classe
    fstream arquivo(nomeArq, ios::in | ios::out | ios::binary);
    arquivo.seekg(pos * sizeof(AnimalDomestico));
    arquivo.read(reinterpret_cast<char*>(&animal), sizeof(AnimalDomestico));

    animal.setNome("REMOVIDO");  // Marca o animal como removido
    arquivo.seekp(pos * sizeof(AnimalDomestico));
    arquivo.write(reinterpret_cast<char*>(&animal), sizeof(AnimalDomestico));

    arquivo.close();
    return true;
}

void Cadastro::atualiza(int tipo) {

   cout << "Informe a informacao de quem voce quer atualizar:" << endl;
   cout << "[1] - Tutor" << endl;
   cout << "[2] - Animal" << endl;
    if (tipo == 1) {
        int cpf;
        cout << "Digite o CPF do tutor: ";
        cin >> cpf;
        cin.ignore();  // Limpar o buffer

        if (atualizaTutor(cpf)) {
            cout << "Tutor atualizado com sucesso." << endl;
        } else {
            cout << "Tutor não encontrado." << endl;
        }
    } else if (tipo == 2) {
        string nomeAnimal;
        cout << "Digite o nome do animal: ";
        cin.ignore();  // Limpar o buffer
        getline(cin, nomeAnimal);

        if (atualizaAnimal(nomeAnimal)) {
            cout << "Animal atualizado com sucesso." << endl;
        } else {
            cout << "Animal não encontrado." << endl;
        }
    }
}

bool Cadastro::atualizaTutor(int CPF) {
    int pos = indice(CPF);
    if (pos == -1) {
      return false;
    }
    

    char novoNome[41];
    cout << "Novo nome do tutor: ";
    cin.ignore();  // Limpar buffer do cin
    cin.getline(novoNome, 41);

    tutor.setNome(novoNome);

    fstream arquivo(nomeArq, ios::in | ios::out | ios::binary);
    arquivo.seekp(pos * sizeof(Cadastro));  // Considerar o tamanho da classe Cadastro
    arquivo.write(reinterpret_cast<char*>(this), sizeof(Cadastro));
    arquivo.close();

    return true;
}

bool Cadastro::atualizaAnimal(const string& nomeAnimal) {
    int pos = indice(nomeAnimal);

    if (pos == -1) {
      return false;
      }

    AnimalDomestico animal; // Supondo que você tenha essa classe
    cout << "Novo nome do animal: ";
    string novoNome;
    getline(cin, novoNome);
    animal.setNome(novoNome);

    fstream arquivo(nomeArq, ios::in | ios::out | ios::binary);
    arquivo.seekp(pos * sizeof(Cadastro));
    arquivo.write(reinterpret_cast<char*>(&animal), sizeof(AnimalDomestico));
    arquivo.close();

    return true;
}