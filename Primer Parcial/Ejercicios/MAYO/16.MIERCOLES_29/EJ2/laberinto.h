#ifndef MAZE_H
#define MAZE_H

class Maze {
public:
    Maze(int **maze, int rows, int cols);
    ~Maze();

    bool solve(int startX, int startY, int endX, int endY);

private:
    int **maze;
    int rows;
    int cols;

    bool isSafe(int x, int y);
    bool solveRecursive(int x, int y, int endX, int endY);
};

#endif // MAZE_H
