#include <iostream>

using namespace std;

class Frac{
    private:
        int a;
        int b;
    public:
    Frac() : a(0), b(0){}
    void in();
    void out();

    Frac& operator --();

    Frac operator --(int);
};