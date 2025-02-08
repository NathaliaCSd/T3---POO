#include <iostream>   
#include <fstream>    
#include "Cadastro.h" 
using namespace std;

int main(void) {
   short opcao;                                                   // ARMAZENA A OPCAO DO MENU

   fstream arquivo("infos.dat", ios_base::in | ios_base::binary); // ABERTURA DO ARQUIVO EM MODO LEITURA BIN�RIA:

   if(arquivo.fail())                                             // SE O ARQUIVO N�O EXISTIR
      criarArquivo();                                             // CRIA O ARQUIVO

   do {
      opcao = menu();                                             // menu() RETORNA UMA OPCAO TRATADA VALIDA
      switch(opcao) {                                             // CHAMA A SUB-ROTINA CORRESPONDENTE:
         case 1: cadastrar();     break;
         case 2: pesquisarNome(); break;
         case 3: pesquisarData(); break;
         case 4: remover();       break;
         case 5: alterar();       break;
      }
   } while (opcao);                                               // ENQUANTO A OPCAO FOR DIFERENTE DE ZERO

   arquivo.close();                                               // FECHA O ARQUIVO
   return 0;
}