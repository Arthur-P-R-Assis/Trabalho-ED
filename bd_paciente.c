#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bd_paciente.h"

// Função para carregar os pacientes do arquivo CSV para a memória
void carregar_banco(BancoPacientes *banco, const char *arquivo_csv) {
    FILE *arquivo = fopen(arquivo_csv, "r"); // abre o arquivo para leitura
    if (!arquivo) { // verifica se abriu certo
        printf("Erro ao abrir o arquivo %s\n", arquivo_csv);
        exit(1); // sai do programa se não abriu
    }

    banco->total_pacientes = 0; // inicializa a contagem de pacientes
    char linha[256];
    fgets(linha, sizeof(linha), arquivo); // pula o cabeçalho do arquivo

    // lê linha por linha do arquivo até o fim ou até o máximo de pacientes
    while (fgets(linha, sizeof(linha), arquivo) && banco->total_pacientes < MAX_PACIENTES) {
        Paciente *p = &banco->pacientes[banco->total_pacientes]; // pega o paciente atual
        // lê os dados da linha e salva no struct Paciente
        sscanf(linha, "%d,%19[^,],%99[^,],%d,%10s", &p->id, p->cpf, p->nome, &p->idade, p->data_cadastro);
        banco->total_pacientes++; // aumenta o total de pacientes
    }

    fclose(arquivo); // fecha o arquivo depois de ler tudo
}

// Função para imprimir a lista completa de pacientes
void imprimir_lista_pacientes(BancoPacientes *banco) {
    printf("\nID\tCPF\t\tNome\t\tIdade\tData_Cadastro\n");
    for (int i = 0; i < banco->total_pacientes; i++) {
        Paciente p = banco->pacientes[i];
        // imprime os dados do paciente na tela
        printf("%d\t%s\t%s\t%d\t%s\n", p.id, p.cpf, p.nome, p.idade, p.data_cadastro);
    }
}

// Função para consultar pacientes por nome ou CPF (busca por prefixo)
void consultar_paciente(BancoPacientes *banco) {
    int opcao;
    char busca[100];
    int i, encontrados;

    printf("\nEscolha o modo de consulta:\n");
    printf("1 - Por nome\n");
    printf("2 - Por CPF\n");
    printf("3 - Retornar ao menu\n");
    scanf("%d", &opcao);
    getchar(); // limpa o \n do buffer

    if (opcao == 1 || opcao == 2) {
        printf("Digite o %s: ", (opcao == 1) ? "nome" : "CPF");
        fgets(busca, sizeof(busca), stdin);
        busca[strcspn(busca, "\n")] = '\0'; // remove o \n do final da string

        printf("\nResultados encontrados:\n");
        printf("ID\tCPF\t\tNome\t\tIdade\tData_Cadastro\n");
        encontrados = 0; // contador de quantos achou

        for (i = 0; i < banco->total_pacientes; i++) {
            Paciente p = banco->pacientes[i];
            // compara os prefixos do nome ou CPF com o que foi digitado
            if ((opcao == 1 && strncmp(p.nome, busca, strlen(busca)) == 0) ||
                (opcao == 2 && strncmp(p.cpf, busca, strlen(busca)) == 0)) {
                printf("%d\t%s\t%s\t%d\t%s\n", p.id, p.cpf, p.nome, p.idade, p.data_cadastro);
                encontrados++;
            }
        }

        if (!encontrados) { // se não encontrou nenhum paciente
            printf("Nenhum paciente encontrado.\n");
        }
    }
}
