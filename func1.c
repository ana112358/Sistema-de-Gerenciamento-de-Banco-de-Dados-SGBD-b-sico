#include "tabela.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define _XOPEN_SOURCE 500 // Esta declaração permite o uso do strdup

void criarTabela(tabela **tabelas, int *numTabelas) {
    char nomeTabela[50];
    int qtdColunas;
     
    for(int h=0;h<30;++h) {
        printf("-");
    }
    printf("\n");

    printf("Digite o nome da nova tabela: ");
    scanf(" %[^\n]", nomeTabela);
   
    for(int d=0;d<30;++d){
        printf("-");
    }
    printf("\n");

    printf("Digite o numero de colunas da tabela '%s': ", nomeTabela);
    scanf("%d", &qtdColunas);

    *tabelas = (tabela *)realloc(*tabelas, (*numTabelas + 1) * sizeof(tabela));

    if (*tabelas == NULL) {
        printf("Erro ao alocar memoria para nova tabela.\n");
        return;
    }

    strcpy((*tabelas)[*numTabelas].nome, nomeTabela);
    (*tabelas)[*numTabelas].numColunas = qtdColunas;

    (*tabelas)[*numTabelas].colunas = (coluna *)malloc(qtdColunas * sizeof(coluna));

    if ((*tabelas)[*numTabelas].colunas == NULL) {
        printf("Erro ao alocar memoria para as colunas da tabela '%s'.\n", nomeTabela);
        return;
    }
    for(int h=0;h<30;++h){
        printf("-");
    }
    printf("\n");

    printf("Detalhes da coluna %d:\n", 1);
    printf("Nome da coluna de identificacao (ID): ");
    scanf(" %[^\n]", (*tabelas)[*numTabelas].colunas[0].nome);
    strcpy((*tabelas)[*numTabelas].colunas[0].tipo, "int");

    for(int h=0;h<30;++h){
        printf("-");
    }
    printf("\n");

    for (int i = 1; i < qtdColunas; ++i) {
        printf("Detalhes da coluna %d:\n", i + 1);
        printf("Nome da coluna: ");
        scanf(" %[^\n]", (*tabelas)[*numTabelas].colunas[i].nome);
       
        for (int j = 0; j < i; ++j) {
            if (strcmp((*tabelas)[*numTabelas].colunas[i].nome, (*tabelas)[*numTabelas].colunas[j].nome) == 0) {
                for(int h=0;h<30;++h){
                    printf("-");
                
                }
                printf("\n");
                printf("Nome invalido (ja existente).\n");
                printf("Insira outro nome para a coluna ou digite 0 para retornar ao menu: ");
                scanf(" %[^\n]", (*tabelas)[*numTabelas].colunas[i].nome);

                j = -1;
            }
        }

        printf("Tipo da coluna (char, int, float, double, string): ");
        scanf("%s", (*tabelas)[*numTabelas].colunas[i].tipo);

        for(int h=0;h<30;++h){
            printf("-");
        }
        printf("\n");
    }
    (*tabelas)[*numTabelas].numLinhas=0;
    (*numTabelas)++;
    

    // Atribuindo 0 ao valor de linhas iniciais da tabela


    // Adicionando o nome da tabela ao arquivo de listagem
    FILE *arquivo_lista = fopen("lista_tabelas.txt", "a+");
    if (arquivo_lista == NULL) {
        printf("Erro ao abrir o arquivo de lista de tabelas.\n");
        return;
    }
    fprintf(arquivo_lista, "%s\n", nomeTabela);
    fclose(arquivo_lista);
    

    // Criar arquivo contendo a Tabela
    char nome_arquivo[50];
    strcpy(nome_arquivo, nomeTabela); // Copia o nome da tabela para a variável do arquivo
    strcat(nome_arquivo, ".txt");


    FILE *tabela_criada = fopen(nome_arquivo, "w");
    if (tabela_criada == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(tabela_criada, " ");
    for (int i=0; i<qtdColunas;++i){
        fprintf(tabela_criada, "%20s", (*tabelas)[*numTabelas - 1].colunas[i].nome);
        if (i != qtdColunas) {
            fprintf(tabela_criada, " | ");
        }
    }
    fprintf(tabela_criada, "\n");

    fprintf(tabela_criada, " ");
    for (int j = 0; j < qtdColunas; j++) {
        fprintf(tabela_criada, "%20s", (*tabelas)[*numTabelas - 1].colunas[j].tipo);
        if (j!= qtdColunas) {
            fprintf(tabela_criada, " | ");
        }
    }
    fprintf(tabela_criada, "\n");

    fclose(tabela_criada);
    printf("\nDigite 0 para voltar ao menu principal do SGBD.\n");
    int saida;
    do {
        saida = 1;
        scanf("%d", &saida);
    } while (saida != 0);
    system("cls");
}

void inserirLinha() {
    char nomeTabela[50];

    printf("Digite a tabela que voce deseja inserir a linha: ");
    scanf(" %[^\n]", nomeTabela);

    char nomeArquivo[50] = "";
    strcpy(nomeArquivo, nomeTabela);
    strcat(nomeArquivo, ".txt");

    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "a+");

    if (arquivo == NULL) {
        printf("Arquivo '%s' nao encontrado.\n", nomeArquivo);
        return;
    }

    char linha1[600];
    int numLinhas = 0;
    int numColunas = 0;

    // Lê a primeira linha para determinar o número de colunas
    if (fgets(linha1, sizeof(linha1), arquivo) != NULL) {
        numLinhas++;
        for (int i = 0; linha1[i] != '\0'; i++) {
            if (linha1[i] == '|') {
                numColunas++;
            }
        }
    }

    while (fgets(linha1, sizeof(linha1), arquivo) != NULL) {
         numLinhas++;
    }
    
    fclose(arquivo); // Fecha e reabre para ler novamente

    arquivo = fopen(nomeArquivo, "r"); // Reabre o arquivo para leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }


    char nomeColunas[numColunas][50]; // Array de strings para armazenar os nomes das colunas

    // Lê os nomes das colunas e armazena em nomeColunas
    if (fgets(linha1, sizeof(linha1), arquivo) != NULL) {
        char *separador;
        separador = strtok(linha1, "|"); // Divide a linha usando o caractere '|'
        int indice = 0;

        while (separador != NULL && indice < numColunas) {

            //retirando os espaços da nossa variável

            int j = 0;
            for (int i = 0; separador[i] != '\0'; i++) {
                if (!isspace((unsigned char)separador[i])) {
                    separador[j++] = separador[i];
                }
            }
            separador[j] = '\0'; 

            strcpy(nomeColunas[indice], separador);
            separador = strtok(NULL, "|");
            indice++;
        }
    }
    fclose(arquivo);

    // Preciso fazer um ponteiro que armazena os dados das colunas chave(que é o ) já existentes
    
    FILE *arquivo2;

    // Aloca memória para armazenar os primeiros 23 caracteres de cada linha do arquivo
    char **chave = (char **)malloc(numLinhas * sizeof(char *));
    char **chaveSemEspaco = (char **)malloc(numLinhas * sizeof(char *));
    for (int i = 0; i < numLinhas; i++) {
        chave[i] = (char *)malloc(24 * sizeof(char)); // 23 caracteres + 1 para o caractere nulo
        chaveSemEspaco[i] = (char *)malloc( sizeof(char)); 
    }

    arquivo2 = fopen(nomeArquivo, "r");

    char parteLinha[100]; // Tamanho arbitrário para armazenar a linha completa

    if (arquivo2 == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int k = 0;
    // Lê os primeiros 23 caracteres de cada linha do arquivo
    while (fgets(parteLinha, sizeof(parteLinha), arquivo2) != NULL && k < numLinhas) {
        strncpy(chave[k], parteLinha, 23); // Copia os primeiros 23 caracteres
        chave[k][23] = '\0'; // Adiciona o caractere nulo ao final da string
        k++;
    }

    fclose(arquivo2);
    int ind=0;

    for (int l = 0; l < numLinhas; l++) {
        for (int a = 0; a < 23; a++) {
            if (chave[l][a]!=' ' && chave[l][a]!='|') {
                if(ind!=0){
                     chaveSemEspaco[l] = (char *)realloc(chaveSemEspaco[l], (ind)*sizeof(char));
                }
                chaveSemEspaco[l][ind]=chave[l][a];
                ++ind;
            } 
        }
    }

     //imprimir as chaves sem espaço

    for (int l = 0; l < numLinhas; l++) {
        char *temp = (char *)malloc(24 * sizeof(char)); // Inicializa um buffer temporário
        int ind = 0;

        for (int a = 0; a < 23; a++) {
            if (chave[l][a] != ' ' && chave[l][a] != '|') {
                temp[ind++] = chave[l][a];
            }
        }

        temp[ind] = '\0'; // Adiciona o caractere nulo no final do buffer
        chaveSemEspaco[l] = strdup(temp); // Usa strdup para alocar exatamente o espaço necessário
        free(temp); // Libera o buffer temporário
    }

    char **dadosLinha;

    dadosLinha = (char **)malloc(numColunas * sizeof(char *)); // Aloca um array de ponteiros para strings

    for (int i = 0; i < numColunas; i++) {
        dadosLinha[i] = (char *)malloc(24 * sizeof(char)); // Aloca espaço para cada string de 23 caracteres + 1 para o caractere nulo
    }

    printf("Digite os dados referentes as colunas\n");

    for(int y=0; y<numColunas; ++y) {
        //entrada de dados
        if(y==0) {
            //verificar chave repetida
            printf("%s:",nomeColunas[y]);
            scanf(" %[^\n]",dadosLinha[y]);

            for (int t = 0; t < numLinhas; t++) {
                if (strcmp(chaveSemEspaco[t], dadosLinha[y]) == 0) {
                    printf("\nChave invalida (ja existe)!\n");
                    printf("Digite novamente ou digite 0 para voltar ao menu!\n\n");
                    printf("%s:", nomeColunas[y]);
                    scanf(" %[^\n]", dadosLinha[y]);
                    if (strcmp(dadosLinha[y], "0") == 0) {
                        system("cls");
                        return;
                    }
                    t=-1;
                }
            }

        } else {
            printf("%s:",nomeColunas[y]);
            scanf(" %[^\n]",dadosLinha[y]);
        }
    }


    FILE *tabela_criada = fopen(nomeArquivo, "a+");
    if (tabela_criada == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return ;
    }

    // adicionar linha no arquivo
    // Supondo que você tenha uma matriz de strings dadosLinha e numColunas como o número de colunas
        fprintf(tabela_criada, " ");
    for (int j = 0; j < numColunas; j++) {
        fprintf(tabela_criada, "%20s", dadosLinha[j]);
        if (j != numColunas) { // Ajuste aqui para evitar adicionar " | " após a última coluna
            fprintf(tabela_criada, " | ");
        }
    }
    fprintf(tabela_criada, "\n"); // Quebra de linha após adicionar uma linha de dados

    fclose(tabela_criada);   
    printf("\nDigite 0 para voltar ao menu principal do SGBD.\n");
    int saida;
    do {
        saida = 1;
        scanf("%d", &saida);
    } while (saida != 0);
    system("cls");
}