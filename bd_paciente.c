#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bd_paciente.h"

void carregar_banco(BancoPacientes *banco, const char *arquivo_csv) {
    FILE *arquivo = fopen(arquivo_csv, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s\n", arquivo_csv);
        exit(1);
    }

    banco->total_pacientes = 0;
    char linha[256];
    fgets(linha, sizeof(linha), arquivo); 

    while (fgets(linha, sizeof(linha), arquivo) && banco->total_pacientes < MAX_PACIENTES) {
        Paciente *p = &banco->pacientes[banco->total_pacientes];
        sscanf(linha, "%d,%19[^,],%99[^,],%d,%10s", &p->id, p->cpf, p->nome, &p->idade, p->data_cadastro);
        banco->total_pacientes++;
    }

    fclose(arquivo);
}

void imprimir_lista_pacientes(BancoPacientes *banco) {
    printf("\nID\tCPF\t\tNome\t\tIdade\tData_Cadastro\n");
    for (int i = 0; i < banco->total_pacientes; i++) {
        Paciente p = banco->pacientes[i];
        printf("%d\t%s\t%s\t%d\t%s\n", p.id, p.cpf, p.nome, p.idade, p.data_cadastro);
    }
}

void consultar_paciente(BancoPacientes *banco) {
    int opcao;
    char busca[100];
    int i, encontrados;

    printf("\nEscolha o modo de consulta:\n");
    printf("1 - Por nome\n");
    printf("2 - Por CPF\n");
    printf("3 - Retornar ao menu\n");
    scanf("%d", &opcao);
    getchar();

    if (opcao == 1 || opcao == 2) {
        printf("Digite o %s: ", (opcao == 1) ? "nome" : "CPF");
        fgets(busca, sizeof(busca), stdin);
        busca[strcspn(busca, "\n")] = '\0';

        printf("\nResultados encontrados:\n");
        printf("ID\tCPF\t\tNome\t\tIdade\tData_Cadastro\n");
        encontrados = 0;

        for (i = 0; i < banco->total_pacientes; i++) {
            Paciente p = banco->pacientes[i];
            if ((opcao == 1 && strncmp(p.nome, busca, strlen(busca)) == 0) ||
                (opcao == 2 && strncmp(p.cpf, busca, strlen(busca)) == 0)) {
                printf("%d\t%s\t%s\t%d\t%s\n", p.id, p.cpf, p.nome, p.idade, p.data_cadastro);
                encontrados++;
            }
        }

        if (!encontrados) {
            printf("Nenhum paciente encontrado.\n");
        }
    }
}
