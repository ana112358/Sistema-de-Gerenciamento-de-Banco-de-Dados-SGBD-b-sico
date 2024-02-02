#include "tabela.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void listarTabelas() {
    FILE *arquivo_lista = fopen("lista_tabelas.txt", "r");

    if (arquivo_lista == NULL) {
        printf("Erro ao abrir o arquivo de tabelas.\n");
        return;
    }

    char linha[100]; // Tamanho arbitrário para ler linhas do arquivo
    printf("\nTabelas existentes:\n\n");
    while (fgets(linha, sizeof(linha), arquivo_lista)) {
        
            printf("Nome da tabela: %s", linha);
        
    }
    printf("\n");

    fclose(arquivo_lista);

    // Janela de espera antes de voltar ao menu principal do banco de dados
    printf("Digite 0 para voltar ao menu principal do SGBD.\n");
    int saida;
    do {
        saida = 1;
        scanf("%d", &saida);
    } while (saida != 0);
    system("cls");
}

void listarDadosTabela() {
    for(int h=0;h<30;++h){
        printf("-");
    }
    printf("\n");

    char nomeTabelaEscolhida[50];
    printf("Digite o nome da tabela que deseja visualizar: ");
    scanf(" %[^\n]", nomeTabelaEscolhida);

    char nomeArquivo[50] = "";
    strcpy(nomeArquivo, nomeTabelaEscolhida); // Copia o nome da tabela para a variável do arquivo
    strcat(nomeArquivo, ".txt");

    FILE *arquivo_tabela = fopen(nomeArquivo, "r");
    if (arquivo_tabela == NULL) {
        printf("Erro ao abrir o arquivo da tabela.\n");
        return;
    }

    // Exibir dados da tabela
    printf("\nDados da tabela '%s':\n", nomeTabelaEscolhida);
    char conteudo_linha[100]; // Tamanho arbitrário para ler linhas do arquivo
    while (fgets(conteudo_linha, sizeof(conteudo_linha), arquivo_tabela)) {
        printf("%s", conteudo_linha);
    }

    fclose(arquivo_tabela);

    printf("\n");
    for(int h=0;h<30;++h){
        printf("-");
    }

    // Janela de espera antes de voltar ao menu principal do banco de dados
    printf("\nDigite 0 para voltar ao menu principal do SGBD.\n");
    int saida;
    do {
        saida = 1;
        scanf("%d", &saida);
    } while (saida != 0);
    system("cls");
}