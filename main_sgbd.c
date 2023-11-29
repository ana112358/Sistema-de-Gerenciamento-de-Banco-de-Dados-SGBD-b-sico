#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definições das estruturas de dados

// Estrutura de uma Coluna
typedef struct {
    char nome[50]; // Nome da coluna
    char tipo[20]; // Tipo da coluna (char, int, float, double, string)
    int chavePrimaria; // É chave primária (1 para sim, 0 para não)
} Coluna;

// Estrutura da Tabela
typedef struct {
    char nome[50];
    int numColunas;
    Coluna *colunas; // ponteiro 
} Tabela;

// Funções para o SGBD

void criarTabela(){

}

void listarTabelas(){
    
}

void inserirLinha(){
    
}

void listarDadosTabela(){
    
}

void pesquisarValorTabela(){
    
}

void apagarTupla(){
    
}

void apagarTabela(){
    
}

int main(){
    Tabela *tabelas = NULL // ponteiro para tabela
    int opcao = -1;
    
    while (opcao != 8){
        printf("Sistema de Gerenciamento de Banco de Dados (SGBD)\n");
        printf("\nMenu:\n");
        printf("1. Criar tabela\n");
        printf("2. Listar tabelas\n");
        printf("3. Inserir linha\n");
        printf("4. Listar dados de tabela\n");
        printf("5. Pesquisar valor em tabela\n");
        printf("6. Apagar tupla\n");
        printf("7. Apagar tabela\n");
        printf("8. Sair\n");
        printf("Digite a opção escolhida: ");
        scanf("%d", &opcao);
 
        switch(opcao){
            case 1:
                criarTabela();
                break;
            case 2:
                listarTabelas();
                break;
            case 3:
                inserirLinha();
                break;
            case 4:
                listarDadosTabela();
                break;
            case 5:
                pesquisarValorTabela();
                break;
            case 6:
                apagarTupla();
                break;
            case 7:
                apagarTabela();
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    }

    // Liberar memória alocada para tabelas
    if (tabelas != NULL) {
        for (int i = 0; i < numTabelas; ++i) {
            free(tabelas[i].colunas);
        }
        free(tabelas);
    }

    printf("TESTE: Saiu do loop!!!\n"); // PRINT DE TESTE PARA VER SE ESTÁ SAINDO DO LOOP, APAGAR DEPOIS.

    return 0;
}
