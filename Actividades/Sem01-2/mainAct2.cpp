//Andrea Catalina Fernández Mena 
//Actividad 2 Semana 1

#include <iostream>
#include <vector>
using namespace std;
#include "listaTemplates.h"

int main()
{
    
    listaTemplates<string> listaTemplates;
    string num = "";  //  /In this case we specify that we will be working with strings as an example 
    while (num != "*") {
        cout << "Write any text (tap * when you finish): ";
        cin >> num;
        if (num != "*") {
            listaTemplates.insert(num);
        }
    }

    listaTemplates.print();  //We choose to print the list of valued added in question 
    
    listaTemplates.remove();   //We remove the last element of the list
    try {
        string aux; 
        aux = listaTemplates.getData(10);      //We use an auxiliar to make sure about 
        cout << "The third element of that list is : " << aux << endl;
    } catch(out_of_range& e) {
        cout << e.what() << endl;
    }
    cout << "This list contains " << listaTemplates.getSize() << " elements" << endl;

    listaTemplates.print();

    
    return 0;
}






