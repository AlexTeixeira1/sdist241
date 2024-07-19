#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <pid_destino> <sinal>\n", argv[0]);
        return 1;
    }

    int pid_destino = atoi(argv[1]);
    int sinal = atoi(argv[2]);

    // Verificar se o processo destino existe
    if (kill(pid_destino, 0) == -1) {
        printf("Erro: Processo %d não existe.\n", pid_destino);
        return 1;
    }

    // Enviar o sinal
    if (kill(pid_destino, sinal) == -1) {
        printf("Erro ao enviar o sinal %d para o processo %d.\n", sinal, pid_destino);
        return 1;
    }

    printf("Sinal %d enviado com sucesso para o processo %d.\n", sinal, pid_destino);
    return 0;
}