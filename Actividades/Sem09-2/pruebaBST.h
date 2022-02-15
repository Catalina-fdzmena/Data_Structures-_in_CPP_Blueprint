//Andrea Catalina Fernández Mena A01197705 
//Actividad individual semana 09 -02

#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
    
    BST<int> bst;

    bst.add(21);
    bst.add(13);
    bst.add(33);
    bst.add(10);
    bst.add(18);
    bst.add(25);
    bst.add(40);
    bst.add(50);
    bst.add(60);
    bst.add(7);
    bst.add(6);
    bst.add(5);
    bst.print();

    
    bst.visit(1);
    bst.visit(2);
    bst.visit(3);
    bst.visit(4);

    cout << "La altura del arbol es: " << bst.height() << endl;

    cout << "ancestros de: 5" << endl;
    bst.ancestors(5);

    int level = bst.whatLevelAmI(5);
    if (level > 0) {
        cout << "el 5 esta en el nivel: " << level << endl;
    } else {
        cout << "no se encontró el 5" << endl;
    }
    // bst.find(55) ? cout << "Si lo encontré" << endl : cout << "NO LO ENCONTRÉ" << endl;

    // cout << endl;
    // bst.remove(5);
    // bst.print();
    // bst.remove(10);
    // bst.print();
    // bst.remove(15);
    // bst.print();
    // bst.add(28);
    // bst.add(27);

    // bst.print();
    // bst.remove(30);
    // bst.print();
    // bst.remove(20);
    // bst.print();
    // bst.remove(28);
    // bst.print();
    // bst.remove(35);
    // bst.remove(25);
    // bst.remove(33);
    // bst.print();

    return 0;
}