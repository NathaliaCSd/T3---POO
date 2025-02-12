<<<<<<< HEAD
#include <iostream>   
#include <fstream>    
#include "Cadastro.h" 

using namespace std; 

int main(void) {
   short opcao; 

   // Abre o arquivo "infos.dat" em modo leitura binária, se o arquivo não existir, ele será criado mais tarde
   fstream arquivo("infos.dat", ios_base::in | ios_base::binary); 

   // Verifica se a abertura do arquivo falhou (ou seja, se o arquivo não existe)
   if(arquivo.fail()) {   
      criarArquivo(); // Se o arquivo não existir, chama a função 'criarArquivo()' para criar o arquivo
   }

   do {
      // Exibe o menu e armazena a opção escolhida pelo usuário
      opcao = menu(); 

      // Executa uma ação de acordo com a opção selecionada
      switch(opcao) {  
         case 1: cadastrar();     break; // Se opção for 1, chama a função 'cadastrar()' para realizar cadastro
         case 2: pesquisarNome(); break; // Se opção for 2, chama a função 'pesquisarNome()' para pesquisar pelo nome
         case 3: pesquisarData(); break; // Se opção for 3, chama a função 'pesquisarData()' para pesquisar pela data
         case 4: remover();       break; // Se opção for 4, chama a função 'remover()' para remover um cadastro
         case 5: alterar();       break; // Se opção for 5, chama a função 'alterar()' para alterar um cadastro
      }
   } while (opcao); // Continua a exibir o menu enquanto a opção for diferente de zero (o usuário pode escolher sair com a opção 0)

   arquivo.close(); // Fecha o arquivo "infos.dat" após a execução do programa
   return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
=======

//main.cpp
#include <iostream>
#include "Cadastro.h"
#include "Gato.h"
#include "Peixe.h"

using namespace std;

void exibirMenu() {
    cout << "=== Sistema de Cadastro de Animais ===\n";
    cout << "1. Adicionar Animal\n";
    cout << "2. Listar Animais\n";
    cout << "3. Atualizar Animal\n";
    cout << "4. Remover Animal\n";
    cout << "5. Salvar em Arquivo\n";
    cout << "6. Carregar do Arquivo\n";
    cout << "7. Sair\n";
    cout << "Escolha uma opcao: ";
}

int main() {
    Cadastro cadastro;
    int opcao;
    do {
        exibirMenu();
        cin >> opcao;
        cin.ignore();
        switch (opcao) {
            case 1: {
                int codigo, idade;
                float peso;
                string nome;
                char sexo;
                
                cout << "Codigo de registro: ";
                cin >> codigo;
                cin.ignore();

                    //MUDADO A ORDEM DAS PERGUNTAS
                cout << "Tipo de animal (1 - Gato, 2 - Peixe): ";
                int tipoAnimal;
                cin >> tipoAnimal;
                cin.ignore();
                
                cout << "Nome do animal: ";
                getline(cin, nome);
                
                cout << "Idade: ";
                cin >> idade;
                
                cout << "Sexo (M/F): ";
                cin >> sexo;
                
                cout << "Peso: ";
                cin >> peso;
                cin.ignore();

                // Informações do tutor
                string nomeTutor, endereco, telefone;
                cout << "Nome do tutor: ";
                getline(cin, nomeTutor);
                cout << "Endereco do tutor: ";
                getline(cin, endereco);
                cout << "Telefone do tutor: ";
                getline(cin, telefone);

                Pessoa* tutor = new Pessoa(nomeTutor, endereco, telefone);


                if (tipoAnimal == 1) {
                    bool ronroneia, usaCaixa;
                    string raca, pelo;
                    cout << "Ronroneia com frequencia? (1 - Sim, 0 - Não): ";
                    cin >> ronroneia;
                    cout << "Usa caixa de areia? (1 - Sim, 0 - Não): ";
                    cin >> usaCaixa;
                    cout << "Raca: ";
                    cin.ignore();  // Limpar o buffer
                    getline(cin, raca);
                    cout << "Tipo de pelo: ";
                    getline(cin, pelo);

                    Gato* gato = new Gato(codigo, nome, idade, sexo, peso, ronroneia, usaCaixa, raca, pelo, tutor);
                    cadastro.adicionarAnimal(gato);
                    cout << "Gato adicionado com sucesso!\n";
                } else if (tipoAnimal == 2) {
                    string escamas, temperatura, especie;
                    cout << "Tipo de escamas: ";
                    cin.ignore();  // Limpar o buffer
                    getline(cin, escamas);
                    cout << "Temperatura da agua: ";
                    getline(cin, temperatura);
                    cout << "Especie: ";
                    getline(cin, especie);

                    Peixe* peixe = new Peixe(codigo, nome, idade, sexo, peso, escamas, temperatura, especie, tutor);
                    cadastro.adicionarAnimal(peixe);
                    cout << "Peixe adicionado com sucesso!\n";
                }
                break;
            }
            case 2:
                cadastro.listarAnimais();
                break;
            case 3: {
                int codigo;
                cout << "Digite o codigo do animal a ser atualizado: ";
                cin >> codigo;
                cadastro.atualizarAnimal(codigo);
                cout << "Dados atualizados com sucesso!\n";
                break;
            }
            case 4: {
                int codigo;
                cout << "Digite o codigo do animal a ser removido: ";
                cin >> codigo;
                cadastro.removerAnimal(codigo);
                break;
            }
            case 5:
                cadastro.salvarArquivo("animais.dat");
                break;
            case 6:
                cadastro.carregarArquivo("animais.dat");
                break;
            case 7:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opcao invalida!\n";
                break;
        }
    } while (opcao != 7);

    return 0;
}
>>>>>>> 154301e (Trocando por trabalho refeito)
