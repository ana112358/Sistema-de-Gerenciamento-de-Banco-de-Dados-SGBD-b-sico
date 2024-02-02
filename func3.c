#include "tabela.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Função para verificar a similaridade entre duas strings
/*int similaridadeStrings(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int minLen = len1 < len2 ? len1 : len2;

    int similaridade = 0;
    for (int i = 0; i < minLen; i++) {
        if (str1[i] == str2[i]) {
            similaridade++;
        }
    }

    return similaridade;
}*/

void pesquisarValorTabela() {
    char nomeTabela[50];
    printf("Digite o nome da tabela para pesquisar um valor: ");
    scanf(" %[^\n]", nomeTabela);

    char nomeArquivo[50] = "";
    strcpy(nomeArquivo, nomeTabela);
    strcat(nomeArquivo, ".txt");

    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo da tabela.\n");
        return;
    }

    char linha[500];

    int numLinhas = 0;
    int numColunas = 0;

    // Lê a primeira linha (cabeçalho) e exibe as colunas
    if (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *token = strtok(linha, "|");
        while (token != NULL) {
            // Remove espaços em branco e caracteres não visíveis do final da string
            int len = strlen(token);
            while (len > 0 && isspace(token[len - 1])) {
                token[len - 1] = '\0';
                len--;
            }

            if (strlen(token) > 0) { // Verifica se o token não está vazio
                numColunas++;
                printf("%d. %s\n", numColunas, token); // Mostra os nomes das colunas
            }

            token = strtok(NULL, "|");
        }
    } else {
        printf("Erro ao ler as colunas da tabela.\n");
        fclose(arquivo);
        return;
    }

    // Conta o número total de linhas
    while (fgets(linha, sizeof(linha), arquivo)) {
        numLinhas++;
    }

    // Reposiciona o ponteiro para o início do arquivo
    fseek(arquivo, 0, SEEK_SET);
    fgets(linha, sizeof(linha), arquivo); // Pula a linha do cabeçalho

    int colunaEscolhida;
    printf("Escolha a coluna (1 a %d): ", numColunas);
    scanf("%d", &colunaEscolhida);

    if (colunaEscolhida < 1 || colunaEscolhida > numColunas) {
        printf("Escolha de coluna inválida.\n");
        return;
    }

    char valorPesquisa[50];
    printf("Digite o valor para pesquisa: ");
    scanf(" %[^\n]", valorPesquisa);

    printf("Opções de pesquisa:\n");
    printf("1. Valores maior que %s\n", valorPesquisa);
    printf("2. Valores maior ou igual a %s\n", valorPesquisa);
    printf("3. Valores igual a %s\n", valorPesquisa);
    printf("4. Valores menor que %s\n", valorPesquisa);
    printf("5. Valores menor ou igual a %s\n", valorPesquisa);
    //printf("6. Valores próximo a %s (se aplicável apenas para strings)\n", valorPesquisa);

    int opcaoPesquisa;
    printf("Escolha a opção de pesquisa (1 a 5): ");
    scanf("%d", &opcaoPesquisa);

    // Lógica de pesquisa baseada na opção escolhida
    int correspondenciaEncontrada = 0;

    fgets(linha, sizeof(linha), arquivo); // pula linha

    while (fgets(linha, sizeof(linha), arquivo)) {
        char linhaatual[500];
        strcpy(linhaatual, linha);
        char *valorColuna = strtok(linha, "|");
        int colunaAtual = 0;
        while (valorColuna != NULL && colunaAtual < numColunas) {
            if (colunaAtual == colunaEscolhida - 1) {
                // Realiza a comparação com base na opção de pesquisa escolhida
                switch (opcaoPesquisa) {
                    case 1:
                        // Valores maior que o valor informado
                        if (atof(valorColuna) > atof(valorPesquisa)) {
                            printf("Registro encontrado: ");
                            printf("%s", linhaatual);
                            correspondenciaEncontrada++;
                        }
                        break;
                    case 2:
                        // Valores maior ou igual ao valor informado
                        if (atof(valorColuna) >= atof(valorPesquisa)) {
                            printf("Registro encontrado: ");
                            printf("%s", linhaatual);
                            correspondenciaEncontrada++;
                        }
                        break;
                    case 3:
                        // Valores igual ao valor informado
                        //if (strcmp(valorColuna, valorPesquisa) == 0) {
                        if (atof(valorColuna) == atof(valorPesquisa)) {
                            printf("Registro encontrado: ");
                            printf("%s", linhaatual);
                            correspondenciaEncontrada++;
                        }
                        break;
                    case 4:
                        // Valores menor que o valor informado
                        if (atof(valorColuna) < atof(valorPesquisa)) {
                            printf("Registro encontrado: ");
                            printf("%s", linhaatual);
                            correspondenciaEncontrada++;
                        }
                        break;
                    case 5:
                        // Valores menor ou igual ao valor informado
                        if (atof(valorColuna) <= atof(valorPesquisa)) {
                            printf("Registro encontrado: ");
                            printf("%s", linhaatual);
                            correspondenciaEncontrada++;
                        }
                        break;
                    /*case 6:
                        // Valores próximos a uma string (similaridade)
                        
                        if ( similaridadeStrings(valorColuna, valorPesquisa)>= 2) { // Ajuste esse valor conforme necessário
                            printf("Registro encontrado: ");
                            printf("%s", linhaatual);
                            correspondenciaEncontrada++;
                        }
                        break;*/
                }
            }
            valorColuna = strtok(NULL, "|");
            colunaAtual++;
        }
    }

    if (correspondenciaEncontrada == 0) {
        printf("Nenhum valor correspondente encontrado.\n");
    } else {
        printf("Total de valores encontrados: %d\n", correspondenciaEncontrada);
    }

    fclose(arquivo);

    // Janela de espera antes de voltar ao menu principal do banco de dados
    printf("\nDigite 0 para voltar ao menu principal do SGBD.\n");
    int saida;
    do {
        saida = 1;
        scanf("%d", &saida);
    } while (saida != 0);
    system("cls");
}

void apagarTupla() {
    char nomeTabela[50];
    int chave;

    printf("Digite o nome da tabela: ");
    scanf(" %[^\n]", nomeTabela);

    printf("Digite a chave da tupla a ser removida: ");
    scanf("%d", &chave);

    char nomeArquivo[50] = "";
    strcpy(nomeArquivo, nomeTabela);
    strcat(nomeArquivo, ".txt");

    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo da tabela.\n");
        return;
    }

    char linha[500]; // Tamanho arbitrário para uma linha de dados
    int linhaEncontrada = 0;
    FILE *tempArquivo = fopen("temp.txt", "w");
    if (tempArquivo == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    // Copia todas as linhas, exceto a que corresponde à chave informada, para um arquivo temporário
    while (fgets(linha, sizeof(linha), arquivo)) {
        int linhaChave;
        sscanf(linha, "%d|", &linhaChave);
        if (linhaChave != chave) {
            fprintf(tempArquivo, "%s", linha);
        } else {
            linhaEncontrada = 1;
        }
    }

    fclose(arquivo);
    fclose(tempArquivo);

    // Se a linha com a chave foi encontrada, substitui o arquivo original pelo temporário
    if (linhaEncontrada) {
        remove(nomeArquivo);
        rename("temp.txt", nomeArquivo);
        printf("Tupla removida com sucesso!\n");
    } else {
        printf("Chave não encontrada na tabela.\n");
        remove("temp.txt");
    }

    // Janela de espera antes de voltar ao menu principal do banco de dados
    printf("\nDigite 0 para voltar ao menu principal do SGBD.\n");
    int saida;
    do {
        saida = 1;
        scanf("%d", &saida);
    } while (saida != 0);
    system("clear");
}

void apagarTabela() {
    printf("\nDigite o nome da tabela para apagar: ");
   
    char nomeTabela[50];
    scanf(" %[^\n]", nomeTabela);
   
    char nomeArquivo[50];
    //Concatenando a
    strcpy(nomeArquivo, nomeTabela);
    strcat(nomeArquivo, ".txt");

    if (remove(nomeArquivo) == 0) {
        printf("Tabela '%s'  apagada!\n", nomeTabela);
    } else {
        printf("Arquivo não encontrado");
    }

    FILE *arquivo=fopen("lista_tabelas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo da tabela.\n");
        return;
    }

    char linha[200]; // Tamanho arbitrário para uma linha de dados
    FILE *auxArquivo = fopen("temporario.txt", "w");
    if (auxArquivo == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(arquivo);
        return ;
    }

    int linhaEncontrada = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strstr(linha, nomeTabela) == NULL) {
            fprintf(auxArquivo, "%s", linha);

        } else {
            linhaEncontrada = 1;
        }
    }

    fclose(arquivo);
    fclose(auxArquivo);

     if (linhaEncontrada) {
        remove("lista_tabelas.txt");
        rename("temporario.txt", "lista_tabelas.txt");
    } else {
        remove("temporario.txt");
    }
    printf("\nDigite 0 para voltar ao menu principal do SGBD.\n");
    int saida;
    do {
        saida = 1;
        scanf("%d", &saida);
    } while (saida != 0);
    system("cls");
}