#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t sinal_recebido = 0;

void signal_handler(int sig) {
    sinal_recebido = sig;
    printf("Sinal %d recebido.\n", sig);

    // Um dos sinais termina a execução do programa
    if (sig == SIGINT) {
        printf("Finalizando o programa.\n");
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    // Definir os signal handlers
    signal(SIGINT, signal_handler);
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    // Verificar se o usuário solicitou busy wait ou blocking wait
    int modo_espera = 0;
    if (argc == 2 && strcmp(argv[1], "blocking") == 0) {
        modo_espera = 1;
    }

    printf("Programa aguardando sinais. PID: %d\n", getpid());

    // Esperar pelos sinais
    while (1) {
        if (modo_espera == 0) {
            // Busy wait
            while (sinal_recebido == 0) {
                // Fica em loop até receber um sinal
            }
        } else {
            // Blocking wait
            pause();
        }

        // Processar o sinal recebido
        switch (sinal_recebido) {
            case SIGINT:
                printf("Sinal de interrupção (SIGINT) recebido.\n");
                break;
            case SIGUSR1:
                printf("Sinal de usuário 1 (SIGUSR1) recebido.\n");
                break;
            case SIGUSR2:
                printf("Sinal de usuário 2 (SIGUSR2) recebido.\n");
                break;
        }

        sinal_recebido = 0;
    }

    return 0;
}