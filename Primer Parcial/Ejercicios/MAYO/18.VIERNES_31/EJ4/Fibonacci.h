#ifndef FIBONACCI_H
#define FIBONACCI_H

class Fibonacci {
public:
    Fibonacci();
    ~Fibonacci();
    long long calcular(int n);

private:
    long long* resultado;
};

#endif // FIBONACCI_H
