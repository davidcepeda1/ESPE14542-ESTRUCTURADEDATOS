#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

char *ingresar(char *msj) {
    char *dato = (char *)malloc(25 * sizeof(char));
    char c;
    int i = 0;
    printf("%s : ", msj);
    while ((c = getch()) != 13) {
        if (c >= '0' && c <= '9') {
            dato[i++] = c;
            printf("%c", c);
        }
    }
    dato[i] = '\0';
    return dato;
}

int main(int argc, char** argv) {
    char cad[25], *dato;
    int valor;
    strcpy(cad, "Ingrese el valor entero");
    dato = ingresar(cad);
    valor = atoi(dato);
    printf("\nValor ingresado ---> %d", valor);
    free(dato); // Don't forget to free the allocated memory
    return 0;
}
