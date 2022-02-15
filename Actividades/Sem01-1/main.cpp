//Andrea Catalina Fernández Mena 
//Actividad 1 Semana 1

#include <iostream>
#include <vector>
using namespace std;
#include "listaEnteros.h"

int main()
{
    //We create a function on main that helps us to collect the numbers in question
    ListaEnteros listaEnteros;
    int number = -1;
    while (number != 0) {
        cout << "Add a value for the list: ";
        cin >> number;
        if (number != 0) {
            listaEnteros.insert(number);
        }
    }
   //Method we call in order to display with the strucction 

    listaEnteros.print();
    
    listaEnteros.remove();
    cout << "The third element of the list is equal to: " << listaEnteros.getData(2) << endl;
    cout << "This list contains " << listaEnteros.getSize() << " elements" << endl;

    listaEnteros.print();

    
    return 0;
}

