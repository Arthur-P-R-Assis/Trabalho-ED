#ifndef BD_PACIENTE_H
#define BD_PACIENTE_H

#define MAX_PACIENTES 1000
#define TAM_NOME 100
#define TAM_CPF 20
#define TAM_DATA 11

typedef struct {
    int id;
    char cpf[TAM_CPF];
    char nome[TAM_NOME];
    int idade;
    char data_cadastro[TAM_DATA];
} Paciente;

typedef struct {
    Paciente pacientes[MAX_PACIENTES];
    int total_pacientes;
} BancoPacientes;

void carregar_banco(BancoPacientes *banco, const char *arquivo);
void imprimir_lista_pacientes(BancoPacientes *banco);
void consultar_paciente(BancoPacientes *banco);

#endif
