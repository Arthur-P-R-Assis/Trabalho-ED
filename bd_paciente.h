#ifndef BD_PACIENTE_H
#define BD_PACIENTE_H

// define o tamanho máximo do vetor de pacientes e os tamanhos das strings
#define MAX_PACIENTES 1000
#define TAM_NOME 100
#define TAM_CPF 20
#define TAM_DATA 11

// struct que guarda os dados de um paciente
typedef struct {
    int id;
    char cpf[TAM_CPF];
    char nome[TAM_NOME];
    int idade;
    char data_cadastro[TAM_DATA];
} Paciente;

// struct que guarda o vetor de pacientes e o total
typedef struct {
    Paciente pacientes[MAX_PACIENTES];
    int total_pacientes;
} BancoPacientes;

// funções que o programa usa
void carregar_banco(BancoPacientes *banco, const char *arquivo);
void imprimir_lista_pacientes(BancoPacientes *banco);
void consultar_paciente(BancoPacientes *banco);

#endif
