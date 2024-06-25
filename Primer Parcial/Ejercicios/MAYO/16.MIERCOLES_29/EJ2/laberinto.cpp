#include "laberinto.h"
#include <iostream>

Maze::Maze(int **maze, int rows, int cols) {
    this->maze = maze;
    this->rows = rows;
    this->cols = cols;
}

Maze::~Maze() {
    // Liberar memoria dinámica usada por maze
    for (int i = 0; i < rows; ++i) {
        delete[] maze[i];
    }
    delete[] maze;
}

bool Maze::solve(int startX, int startY, int endX, int endY) {
    // Validar coordenadas de inicio y fin
    if (startX < 0 || startY < 0 || startX >= rows || startY >= cols ||
        endX < 0 || endY < 0 || endX >= rows || endY >= cols) {
        std::cerr << "Coordenadas de inicio o fin fuera del rango del laberinto." << std::endl;
        return false;
    }

    // Llamar a la función recursiva para resolver el laberinto
    return solveRecursive(startX, startY, endX, endY);
}

bool Maze::solveRecursive(int x, int y, int endX, int endY) {
    // Caso base: si llegamos a la posición de salida
    if (x == endX && y == endY) {
        return true;
    }

    // Verificar si es seguro moverse a la posición (x, y)
    if (isSafe(x, y)) {
        // Marcar la posición actual como visitada (si es necesario)
        // Aquí podrías tener lógica adicional según la representación del laberinto

        // Moverse en todas las direcciones posibles (arriba, abajo, izquierda, derecha)
        // Debes implementar la lógica para cada movimiento

        // Por ejemplo, intentar moverse hacia abajo
        if (x + 1 < rows && solveRecursive(x + 1, y, endX, endY)) {
            return true;
        }
        // Intentar moverse hacia arriba
        if (x - 1 >= 0 && solveRecursive(x - 1, y, endX, endY)) {
            return true;
        }
        // Intentar moverse hacia la derecha
        if (y + 1 < cols && solveRecursive(x, y + 1, endX, endY)) {
            return true;
        }
        // Intentar moverse hacia la izquierda
        if (y - 1 >= 0 && solveRecursive(x, y - 1, endX, endY)) {
            return true;
        }
    }

    // Si ninguna de las opciones anteriores lleva a la solución, marcar este camino como no válido
    return false;
}

bool Maze::isSafe(int x, int y) {
    // Verificar si es seguro moverse a la posición (x, y) en el laberinto
    // Aquí puedes implementar la lógica según la representación del laberinto
    // Por ejemplo, verificar si la posición no está bloqueada (pared) o ya ha sido visitada
    // Dependiendo de cómo representes el laberinto (con números, caracteres, etc.)

    // Ejemplo básico: asumiendo que 0 representa espacio libre y 1 representa pared
    if (maze[x][y] == 0) {
        return true;
    }
    return false;
}
