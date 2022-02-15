#include <iostream>
using namespace std;

// Dígitos d2, d4 y d6
int selDigitos(int a) {
    int d2, d4, d6, d2d4d6;
    // 12345678 d2 = 2
    d2 = a / 1000000 % 10;
    d4 = a / 10000 % 10;
    d6 = a / 100 % 10;
    d2d4d6 = d2 * 100 + d4 * 10 + d6;
    cout << d2 << " " << d4 << " " << d6 << endl;
    return d2d4d6;
}

int residual(int a) {
    return a % 1009; // 1009 es el primer número primo después del 1000
}

int cuadratica(long long int a) {
    long long int c = a * a;
    int d7, d8, d9, d7d8d9;
    // 12345678 d2 = 2
    d7 = c / 10000000000 % 10;
    d8 = c / 1000000000 % 10;
    d9 = c / 100000000 % 10;
    d7d8d9 = d7 * 100 + d8 * 10 + d9;
    return d7d8d9;
}

int folding(int a) {
    int d1,d2,d3,d4,d5,d6,d7,d8;
    d1 = a / 10000000;
    d2 = a / 1000000 % 10;
    d3 = a / 100000 % 10;
    d4 = a / 10000 % 10;
    d5 = a / 1000 % 10;
    d6 = a / 100 % 10;
    d7 = a / 10 % 10;
    d8 = a / 1 % 10;
    return d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8;
}

int main()
{
    srand(time(NULL));
    for (int i=0; i<5; i++) {
    
        int a = rand() % 100000000 + 1;
        cout << "número: " << a << endl;
        // selección de dígitos
        cout << "Selección de dígitos" << endl;
        cout << selDigitos(a) << endl;
        // residual
        cout << "Residual" << endl;
        cout << residual(a) << endl;
        // Cuadrática
        cout << "Cuadrática" << endl;
        cout << cuadratica(a) << endl;
        // Folding
        cout << "Folding" << endl;
        cout << folding(a) << endl;

    }


    return 0;
}
