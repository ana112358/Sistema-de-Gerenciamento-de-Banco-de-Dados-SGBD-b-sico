#include <stdio.h>

typedef struct{
    char nome[25];
    int* valores_tabela;
} tabela;

void CriarTabela(){

}

void ListarTabelas(){
    
}

void NovaLinha(){
    
}

void ListarDados(){
    
}

void PesquisarValor(){
    
}

void ApagarRegistro(){
    
}

void ApagarTabela(){
    
}

int main()
{
    printf("Sistema de Gerenciamento de Banco de Dados (SGBD)\n");
    printf("0 - Sair do Sistema\n");
    printf("1 - Criar Tabela\n");
    printf("2 - Listar Tabelas\n");
    printf("3 - Nova Linha\n");
    printf("4 - Listar Dados\n");
    printf("5 - Pesquisar Valor\n");
    printf("6 - Apagar Registro\n");
    printf("7 - Apagar Tabela\n");

    
    int entrada = -1;
    
    while (entrada != 0){
        printf("Digite a opção escolhida: ");
        scanf("%d", &entrada);
        
        
 
        switch(entrada){
            case 1:
                CriarTabela();
                
                
            case 2:
                ListarTabelas();
          
                
            case 3:
                NovaLinha();
              
                
            case 4:
                ListarDados();
              
                
            case 5:
                PesquisarValor();
               
                
            case 6:
                ApagarRegistro();

            
            case 7:
                ApagarTabela();
            
            case 0:
                break;
            
        }
    }
    

    return 0;
}
