#ifndef TABELA_H
#define TABELA_H

#define _XOPEN_SOURCE 500 // Esta declaração permite o uso do strdup
#include <string.h> // Incluir a biblioteca string.h para usar a função strdup

typedef struct {
    int chave;
    char *dados;
    int numColunas;
} linha;

typedef struct {
    char nome[50];
    char tipo[20];
} coluna;

typedef struct {
    char nome[50];
    int numColunas;
    int numLinhas;
    coluna *colunas;
    linha *linhas;
} tabela;

// Protótipos de funções da parte 1 (func1.c)
void criarTabela(tabela **tabelas, int *numTabelas);
void inserirLinha();

// Protótipos de funções da parte 2 (func2.c)
void listarTabelas();
void listarDadosTabela();

// Protótipos de funções da parte 3 (func3.c)
//int similaridadeStrings(const char *str1, const char *str2);
void pesquisarValorTabela();
void apagarTupla();
void apagarTabela();

#endif