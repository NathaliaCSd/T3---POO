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
