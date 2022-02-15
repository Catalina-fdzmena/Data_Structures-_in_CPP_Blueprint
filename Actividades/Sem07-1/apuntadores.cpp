#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int *p;

    p = &a; // p apunta a la dirección de memoria de a
    cout << "a = " << a << endl;
    cout << "*p = " << *p << endl;
    cout << "p = " << p << endl;
    cout << "&a = " << &a << endl;
    cout << "&p = " << &p << endl;

    a = 10;
    p = new int(20); // p apunta a la dirección de memoria de 20
    // p = &b; // p apunta a la dirección de memoria de b
    cout << "a = " << a << endl;
    cout << "*p = " << *p << endl;
    cout << "p = " << p << endl;
    cout << "&a = " << &a << endl;
    cout << "&p = " << &p << endl;
    
    delete p; // libera la memoria de 20
    cout << "a = " << a << endl;
    cout << "*p = " << *p << endl;
    cout << "p = " << p << endl;
    cout << "&a = " << &a << endl;
    cout << "&p = " << &p << endl;
    
    return 0;
}