#ifndef TORRESHANOI_H
#define TORRESHANOI_H

class TorresHanoi {
public:
    TorresHanoi(int numDiscos); // Constructor
    void resolver(); // Método para resolver el problema de Torres de Hanoi

private:
    int numDiscos; // Número de discos
    void moverDisco(int n, char origen, char destino, char auxiliar); // Función auxiliar recursiva
};

#endif // TORRESHANOI_H
