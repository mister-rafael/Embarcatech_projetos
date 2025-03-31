#include <stdio.h>  


void imprimirMensagem(char *msg) {
    printf("Mensagem: %s\n", msg);
}

int main() {
    char texto[] = "Olá, mundo!";
    imprimirMensagem(texto);  // Passamos apenas o endereço
    return 0;
}
