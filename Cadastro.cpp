#include "Cadastro.h" 

// Função que busca o índice de um tutor com base no CPF.
// Retorna o índice do tutor se encontrado, caso contrário, retorna -1.
int Cadastro::indice(int CPF) {
    long unsigned int tam = tutor.size();  // Obtém o tamanho do vetor de tutores.
    long unsigned int pos = 0;

    // Busca linear pelo CPF do tutor no vetor.
    while (pos < tam && tutor[pos]->getCPF() != CPF) {
        pos++;
    }

    if (pos < tam) {
        return pos;  // Tutor encontrado.
    } else {
        return -1;  // Tutor não encontrado.
    }
}

// Função para gravar dados binários em um arquivo.
void Cadastro::grava(void* dados, size_t tamanho) {
    ofstream arquivo(nomeArq, ios::app | ios::binary);  // Abre o arquivo para anexar dados binários.
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo para gravação." << endl;
        return;
    }
    arquivo.write(reinterpret_cast<char*>(dados), tamanho);  // Escreve os dados no arquivo.
    arquivo.close();  // Fecha o arquivo.
}

// Função para recuperar os tutores do arquivo e imprimir suas informações.
void Cadastro::recupera() {
    ifstream arquivo(nomeArq, ios::in | ios::binary);  // Abre o arquivo para leitura binária.
    while (arquivo.read(reinterpret_cast<char*>(&tutor), sizeof(Pessoa))) {
        // Lê e imprime as informações de cada tutor.
        cout << "Nome: " << tutor.getNome() << ", CPF: " << tutor.getCPF() << endl;
    }
    arquivo.close();
}

// Função para adicionar um tutor ou animal ao cadastro dependendo do tipo informado.
bool Cadastro::adiciona(int tipo) {
    if (tipo == Tutor) {
        // Adiciona um tutor ao cadastro.
        string nome;
        int CPF;

        cout << "Nome do Tutor: ";
        cin.ignore();
        getline(cin, nome);

        cout << "CPF do Tutor: ";
        cin >> CPF;

        Pessoa novoTutor(nome, CPF);
        grava(&novoTutor, sizeof(Pessoa));  // Grava o tutor no arquivo.

        cout << "Tutor cadastrado com sucesso!" << endl;
        return true;
    } else if (tipo == Animal) {
        // Adiciona um animal ao cadastro.
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

        // Verifica se o tutor existe.
        if (indice(CPF) == -1) {
            cout << "Tutor não encontrado. Cadastre o tutor primeiro." << endl;
            return false;
        }

        AnimalDomestico novoAnimal(nomeAnimal, peso, idade, CPF);
        grava(&novoAnimal, sizeof(AnimalDomestico));  // Grava o animal no arquivo.

        cout << "Animal cadastrado com sucesso!" << endl;
        return true;
    }

    cout << "Tipo de cadastro inválido." << endl;
    return false;
}

// Função para adicionar um tutor ao vetor de tutores e ao arquivo.
bool Cadastro::adicionaTutor(const Pessoa& novoTutor) {
    // Verifica se o tutor já está cadastrado pelo CPF.
    for (const auto& tutor : tutor) {
        if (tutor.getCPF() == novoTutor.getCPF()) {
            cout << "Tutor com este CPF já está cadastrado." << endl;
            return false;
        }
    }

    // Adiciona o novo tutor ao vetor e grava no arquivo.
    tutor.push_back(novoTutor);
    grava();  // Grava os dados atualizados.

    cout << "Tutor cadastrado com sucesso!" << endl;
    return true;
}

// Função para adicionar um animal ao vetor de animais do tutor e ao arquivo.
bool Cadastro::adicionaAnimal(const AnimalDomestico& animal, int cpfTutor) {
    Pessoa* tutor = buscaTutor(cpfTutor);
    if (tutor != nullptr) {
        tutor->adicionaAnimal(animal);  // Adiciona o animal ao vetor de animais do tutor.
        grava();  // Grava as alterações no arquivo.
        return true;
    } else {
        cout << "Tutor não encontrado. Cadastre o tutor primeiro." << endl;
        return false;
    }
}

// Função para imprimir as informações de um tutor pelo CPF.
void Cadastro::imprime(int CPF) {
    int pos = indice(CPF);
    if (pos != -1) {
        cout << "Nome: " << tutor.getNome() << ", CPF: " << tutor.getCPF() << endl;
    } else {
        cout << "Registro nao encontrado." << endl;
    }
}

// Função para remover um tutor ou um animal do cadastro.
void Cadastro::remove(int tipo) {
    cout << "Informe a informacao de quem voce quer REMOVER:" << endl;
    cout << "[1] - Tutor" << endl;
    cout << "[2] - Animal" << endl;

    if (tipo == 1) {
        // Remove um tutor do cadastro.
        int cpf;
        cout << "Digite o CPF do tutor: ";
        cin >> cpf;
        cin.ignore();  // Limpa o buffer do cin.

        if (removeTutor(cpf)) {
            cout << "Tutor REMOVIDO com sucesso." << endl;
        } else {
            cout << "Tutor não encontrado." << endl;
        }
    } else if (tipo == 2) {
        // Remove um animal do cadastro.
        string nomeAnimal;
        cout << "Digite o nome do animal: ";
        cin.ignore();  // Limpa o buffer.
        getline(cin, nomeAnimal);

        if (removeAnimal(nomeAnimal)) {
            cout << "Animal REMOVIDO com sucesso." << endl;
        } else {
            cout << "Animal não encontrado." << endl;
        }
    }
}

// Função para remover um tutor do arquivo.
bool Cadastro::removeTutor(int CPF) {
    int pos = indice(CPF);
    if (pos == -1) return false;

    fstream arquivo(nomeArq, ios::in | ios::out | ios::binary);
    arquivo.seekg(pos * sizeof(Pessoa));  // Posiciona no local do tutor.
    arquivo.read(reinterpret_cast<char*>(&tutor), sizeof(Pessoa));

    tutor.setNome("REMOVIDO");  // Marca o nome do tutor como "REMOVIDO".
    arquivo.seekp(pos * sizeof(Pessoa));  // Vai para a posição do tutor.
    arquivo.write(reinterpret_cast<char*>(&tutor), sizeof(Pessoa));

    arquivo.close();
    return true;
}

// Função para remover um animal do arquivo.
bool Cadastro::removeAnimal(const string& nomeAnimal) {
    int pos = indice(nomeAnimal);
    if (pos == -1) return false;

    AnimalDomestico animal;
    fstream arquivo(nomeArq, ios::in | ios::out | ios::binary);
    arquivo.seekg(pos * sizeof(AnimalDomestico));
    arquivo.read(reinterpret_cast<char*>(&animal), sizeof(AnimalDomestico));

    animal.setNome("REMOVIDO");  // Marca o animal como "REMOVIDO".
    arquivo.seekp(pos * sizeof(AnimalDomestico));
    arquivo.write(reinterpret_cast<char*>(&animal), sizeof(AnimalDomestico));

    arquivo.close();
    return true;
}

// Função para atualizar informações de um tutor ou animal no cadastro.
void Cadastro::atualiza(int tipo) {
    cout << "Informe a informacao de quem voce quer atualizar:" << endl;
    cout << "[1] - Tutor" << endl;
    cout << "[2] - Animal" << endl;

    if (tipo == 1) {
        // Atualiza informações de um tutor.
        int cpf;
        cout << "Digite o CPF do tutor: ";
        cin >> cpf;
        cin.ignore();  // Limpa o buffer do cin.

        if (atualizaTutor(cpf)) {
            cout << "Tutor atualizado com sucesso." << endl;
        } else {
            cout << "Tutor não encontrado." << endl;
        }
    } else if (tipo == 2) {
        // Atualiza informações de um animal.
        string nomeAnimal;
        cout << "Digite o nome do animal: ";
        cin.ignore();  // Limpa o buffer.
        getline(cin, nomeAnimal);

        if (atualizaAnimal(nomeAnimal)) {
            cout << "Animal atualizado com sucesso." << endl;
        } else {
            cout << "Animal não encontrado." << endl;
        }
    }
}

// Função para atualizar as informações de um tutor.
bool Cadastro::atualizaTutor(int CPF) {
    int pos = indice(CPF);
    if (pos == -1) {
        return false;
    }

    char novoNome[41];
    cout << "Novo nome do tutor: ";
    cin.ignore();
    cin.getline(novoNome, 41);

    tutor.setNome(novoNome);

    fstream arquivo(nomeArq, ios::in | ios::out | ios::binary);
    arquivo.seekp(pos * sizeof(Cadastro));  // Considera o tamanho da classe Cadastro.
    arquivo.write(reinterpret_cast<char*>(this), sizeof(Cadastro));
    arquivo.close();

    return true;
}

// Função para atualizar as informações de um animal.
bool Cadastro::atualizaAnimal(const string& nomeAnimal) {
    int pos = indice(nomeAnimal);

    if (pos == -1) {
        return false;
    }

    AnimalDomestico animal;
    cout << "Novo nome do animal: ";
    string novoNome;
    getline(cin, novoNome);
    animal.setNome(novoNome);

    fstream arquivo(nomeArq, ios::in | ios::out | ios::binary);
    arquivo.seekp(pos * sizeof(Cadastro));  // Considera o tamanho da classe Cadastro.
    arquivo.write(reinterpret_cast<char*>(&animal), sizeof(AnimalDomestico));
    arquivo.close();

    return true;
}
