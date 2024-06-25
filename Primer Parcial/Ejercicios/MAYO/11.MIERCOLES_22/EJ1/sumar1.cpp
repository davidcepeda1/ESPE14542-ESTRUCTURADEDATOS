#include <iostream>
#include <cstdlib>
#include <time.h>
#define MAX 3

using namespace std;

int main() {
    int** mat1 = (int**)malloc(MAX * sizeof(int*));
    int** mat2 = (int**)malloc(MAX * sizeof(int*));
    int** matR = (int**)malloc(MAX * sizeof(int*));
    for (int i = 0; i < MAX; ++i) {
        mat1[i] = (int*)malloc(MAX * sizeof(int));
        mat2[i] = (int*)malloc(MAX * sizeof(int));
        matR[i] = (int*)malloc(MAX * sizeof(int));
    }

    srand(time(NULL));
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            mat1[i][j] = rand() % 1000;
            mat2[i][j] = rand() % 1000;
            matR[i][j] = 0;
        }
    }

    cout << "\nLa matriz 1 es:\n";
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            printf("%d", mat1[i][j]);
            printf("%*s", j + 5, "");
        }
        cout << "\n";
    }

    cout << "\nLa matriz 2 es:\n";
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            printf("%d", mat2[i][j]);
            printf("%*s", j + 5, "");
        }
        cout << "\n";
    }

    // Lambda recursiva para sumar matrices
    auto sumaRecursivaMatrices = [&](int f, int c, auto& self) -> void {
        if (f < 0 || c < 0) return;
        matR[f][c] = mat1[f][c] + mat2[f][c];
        if (c > 0) self(f, c - 1, self); // Llamada recursiva a la izquierda
        if (c == 0 && f > 0) self(f - 1, MAX - 1, self); // Llamada recursiva a la fila anterior
    };

    // Iniciar la suma desde la última celda
    cout << "Suma de Matrices es: ";
    sumaRecursivaMatrices(MAX - 1, MAX - 1, sumaRecursivaMatrices);
    cout << "\nLa matriz R es:\n";
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            printf("%d", matR[i][j]);
            printf("%*s", j + 5, "");
        }
        cout << "\n";
    }

    // Liberar memoria
    for (int i = 0; i < MAX; ++i) {
        free(mat1[i]);
        free(mat2[i]);
        free(matR[i]);
    }
    free(mat1);
    free(mat2);
    free(matR);

    return 0;
}
