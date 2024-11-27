
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct {
    char nome[100];
    char cpf[15];
    int dia;
    int quantidadePessoas;
} Reserva;

#define MAX_RESERVAS 100
Reserva reservas[MAX_RESERVAS];
int totalReservas = 0;

void exibirMenu() {
    printf("\n======= Sistema de Reservas =======\n");
    printf("1 - Fazer Reserva\n");
    printf("2 - Listar Reservas\n");
    printf("3 - Total de Pessoas Por Dia\n");
    printf("4 - Sair\n");
    printf("Escolha uma opcao: ");
}

void fazerReserva() {
    if (totalReservas >= MAX_RESERVAS) {
        printf("Limite de reservas atingido.\n");
        return;
    }

    Reserva novaReserva;
    printf("Nome: ");
    fflush(stdin);
    fgets(novaReserva.nome, sizeof(novaReserva.nome), stdin);
    novaReserva.nome[strcspn(novaReserva.nome, "\n")] = '\0';

    printf("CPF: ");
    scanf("%14s", novaReserva.cpf);

    do {
        printf("Dia da reserva (1 - Quinta, 2 - Sexta, 3 - Sabado, 4 - Domingo): ");
        scanf("%d", &novaReserva.dia);
    } while (novaReserva.dia < 1 || novaReserva.dia > 4);

    printf("Quantidade de pessoas: ");
    scanf("%d", &novaReserva.quantidadePessoas);

    reservas[totalReservas++] = novaReserva;
    printf("Reserva cadastrada com sucesso!\n");
}

void listarReservas() {
    if (totalReservas == 0) {
        printf("Nenhuma reserva cadastrada.\n");
        return;
    }

    for (int i = 0; i < totalReservas; i++) {
        printf("\nNome: %s\n", reservas[i].nome);
        printf("CPF: %s\n", reservas[i].cpf);
        printf("Dia: %d\n", reservas[i].dia);
        printf("Numero de Pessoas: %d\n", reservas[i].quantidadePessoas);
        printf("==================================\n");
    }
}

void totalPessoasPorDia() {
    int dia, total = 0;
    printf("Informe o dia (1 - Quinta, 2 - Sexta, 3 - Sábado, 4 - Domingo): ");
    scanf("%d", &dia);

    for (int i = 0; i < totalReservas; i++) {
        if (reservas[i].dia == dia) {
            total += reservas[i].quantidadePessoas;
        }
    }
    printf("Total de pessoas para o dia %d: %d\n", dia, total);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                fazerReserva();
                break;
            case 2:
                listarReservas();
                break;
            case 3:
                totalPessoasPorDia();
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
        system("pause");
        system("cls");
    } while (opcao != 4);

    return 0;
}

// Fontes:
// https://linguagemc.com.br/primeiro-programa-em-linguagem-c/
// https://www.inf.pucrs.br/~pinho/LaproI/Structs/Structs.htm
// https://linguagemc.com.br/o-comando-switch-case-em-c/

