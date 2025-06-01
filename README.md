EP1 - Sistema de Gerenciamento de Dados de Pacientes

Este projeto é um trabalho da disciplina de Estrutura de Dados.  
O programa é um sistema simples para gerenciar pacientes de uma clínica.  
Ele carrega os dados de um arquivo CSV, permite consultar pacientes pelo nome ou CPF (busca por prefixo) e também imprimir a lista completa de pacientes.

Arquivos do projeto:
- main.c: programa principal
- bd_paciente.c: funções para trabalhar com pacientes
- bd_paciente.h: cabeçalho com structs e protótipos
- bd_paciente.csv: arquivo com os dados de exemplo
- Makefile: para compilar o programa

Como compilar:
No terminal, digitar:
make

Como executar:
No terminal, digitar:
./healthsys

Estrutura do sistema:
- O programa usa um vetor de structs para armazenar os pacientes na memória.
- O TAD Paciente armazena os campos: id, cpf, nome, idade e data de cadastro.
- O TAD BancoPacientes é um vetor estático de pacientes com um campo para contar o total de pacientes.
- As funções principais são:
  - carregar_banco: lê o arquivo CSV e carrega os pacientes no vetor.
  - consultar_paciente: busca por nome ou CPF (prefixo) e mostra os dados.
  - imprimir_lista_pacientes: imprime a lista de todos os pacientes.

Decisões de implementação:
- O sistema usa um vetor estático simples de tamanho máximo 1000 (definido por MAX_PACIENTES).
- A busca é feita com strncmp para permitir busca por prefixo.
- As funções são organizadas em arquivos separados (bd_paciente.c e bd_paciente.h) para modularizar o código.
- O Makefile é usado para compilar o projeto no Windows usando mingw32-make.

Exemplo de dados no bd_paciente.csv:

ID,CPF,Nome,Idade,Data_Cadastro
1,123.456.789-09,João Silva,45,2024-12-01

2,987.654.321-00,Maria Oliveira,30,2024-12-02

Para consultar pacientes, o sistema pede o nome ou CPF e mostra os dados encontrados.  
Para imprimir a lista, mostra todos os pacientes do arquivo.
