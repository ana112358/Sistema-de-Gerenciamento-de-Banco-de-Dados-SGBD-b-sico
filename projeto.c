#include "tabela.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    tabela *tabelas = NULL;
    int numTabelas = 0;
    int opcao = -1;

    while (opcao != 8) {
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
        printf("Digite a opcao escolhida: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criarTabela(&tabelas, &numTabelas);
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

    if (tabelas != NULL) {
        for (int i = 0; i < numTabelas; ++i) {
            free(tabelas[i].colunas);
        }
        free(tabelas);
    }

    return 0;
}
