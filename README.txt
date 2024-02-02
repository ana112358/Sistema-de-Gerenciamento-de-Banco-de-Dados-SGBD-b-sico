# Projeto: Sistema de Gerenciamento de Banco de Dados

## Funcionalidades Implementadas
1. Criar uma tabela
2. Listar todas as tabelas
3. Criar uma nova linha na tabela
4. Listar todos os dados de uma tabela
5. Pesquisar valor em uma tabela
6. Apagar uma tupla de uma tabela
7. Apagar uma tabela

## O que não foi feito
Na função Pesquisar valor em uma tabela não foi implementado com sucesso a opção de comparação de valores próximo ao valor informado (em caso de strings).
Porém, todas as demais opções dessa função foram implementadas corretamente.

## Melhorias para o projeto
Buscaria uma maneira de inserir os dados das linhas respeitando seus respectivos tipos, no lugar de colocá-los na forma de string;
Criar uma função para identificar o tipo do dado de acordo com a entrada do usuário;

## Como compilar o projeto
Foi criado um arquivo Makefile para facilitar a compilação, dessa forma basta o usuário usar o comando <make> ou <make all> no sistema operacional Linux para executar o programa. Uma vez compilado, o mesmo pode ser executado com o comando <./projeto>.

## Autores
- Antonio Walter Araújo Filho
- Ana Paula Oliveira de Lima

#### Contribuição dos integrantes no desenvolvimento do projeto.
- As funções "inserirLinha", "listarDadosTabela", "apagarTabela" foram desenvolvidas por Ana Paula;
- As funções "listarTabelas", "pesquisarValorTabela", "apagarTupla" foram desenvolvidas por Walter Araújo.

#### Vídeo com demonstração do projeto em funcionamento
https://drive.google.com/file/d/1L2P6uXQZQnhQ02c438GSsW-EocP8zMFm/view?usp=sharing