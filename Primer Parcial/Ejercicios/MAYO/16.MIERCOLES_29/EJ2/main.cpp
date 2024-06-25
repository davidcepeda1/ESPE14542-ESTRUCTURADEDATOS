#include "laberinto.h"
#include <iostream>

int main() {
    // Crear un laberinto como una matriz dinámica
    int rows = 5;
    int cols = 5;

    int **maze = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        maze[i] = new int[cols];
        // Inicializar el laberinto según sea necesario
        for (int j = 0; j < cols; ++j) {
            // Ejemplo: 0 representa espacio libre, 1 representa pared
            maze[i][j] = 0;
        }
    }

    // Definir las coordenadas de inicio y fin
    int startX = 0;
    int startY = 0;
    int endX = rows - 1;
    int endY = cols - 1;

    Maze mazeSolver(maze, rows, cols);
    bool solved = mazeSolver.solve(startX, startY, endX, endY);

    if (solved) {
        std::cout << "Se encontró una solución al laberinto." << std::endl;
    } else {
        std::cout << "No se encontró una solución al laberinto." << std::endl;
    }

    // Liberar memoria dinámica del laberinto
    for (int i = 0; i < rows; ++i) {
        delete[] maze[i];
    }
    delete[] maze;

    return 0;
}
