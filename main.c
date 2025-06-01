#include <stdio.h>
#include "bd_paciente.h"

// Função do menu principal
void menu(BancoPacientes *banco) {
    char opcao;
    char auxiliar;

    auxiliar = 0; // variável para controlar o loop

    // loop do menu até o usuário escolher sair
    while (auxiliar != 'S' && auxiliar != 's') {
        printf("\nHealthSys - Sistema de Pacientes\n");
        printf("1 - Consultar paciente\n");
        printf("2 - Imprimir lista de pacientes\n");
        printf("S - Sair\n");
        printf("Escolha: ");
        scanf(" %c", &opcao);

        auxiliar = opcao; // guarda a escolha do usuário

        if (opcao == '1') {
            consultar_paciente(banco); // chama a função de consultar
        } 
        else if (opcao == '2') {
            imprimir_lista_pacientes(banco); // chama a função de imprimir lista
        } 
        else if (opcao == 'S' || opcao == 's') {
            printf("Saindo...\n");
            break; // sai do loop
        } 
        else {
            printf("Opção inválida\n");
        }
    }
}

int main() {
    BancoPacientes banco; // declara a variável para guardar os pacientes
    carregar_banco(&banco, "bd_paciente.csv"); // carrega os pacientes do arquivo
    menu(&banco); // chama o menu principal
    return 0; // finaliza o programa
}
