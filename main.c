#include <stdio.h> 
#include <string.h> // Biblioteca do strtok, strcpy.
#include "funcoes.h" // Nossa biblioteca.
#include <locale.h> // Biblioteca de linguagem, para aceitar caracteres ASCII PT-BR

int main() {
    setlocale(LC_ALL, "Portuguese"); // Setando a linguagem do código para Português, com os acentos e "ç".

    // Ler os dados dos alunos do arquivo
    lerDadosDeArquivo();

    // Exibir o menu
    exibirMenu();

    return 0;
}