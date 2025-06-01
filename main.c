#include <stdio.h>
#include "bd_paciente.h"

void menu(BancoPacientes *banco) {
    char opcao;
    char auxiliar;

    auxiliar =0;

    while (auxiliar != 'S' && auxiliar != 's'){
        printf("\nHealthSys - Sistema de Pacientes\n");
        printf("1 - Consultar paciente\n");
        printf("2 - Imprimir lista de pacientes\n");
        printf("S - Sair\n");
        printf("Escolha: ");
        scanf(" %c", &opcao);

        auxiliar = opcao;

        if (opcao == '1') {
            consultar_paciente(banco);
        } 
        
        else if (opcao == '2') {
            imprimir_lista_pacientes(banco);
        } 

        else if (opcao == 'S' || opcao == 's') {
            printf("Saindo...\n");
            break;
        } 
        
        else {
            printf("Opção inválida\n");
        }
    }
}

int main() {
    BancoPacientes banco;
    carregar_banco(&banco, "bd_paciente.csv");
    menu(&banco);
    return 0;
}
