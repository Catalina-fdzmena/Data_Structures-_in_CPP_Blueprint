#include <iostream>
using namespace std;

#include "DoubleLinkedList.h"


int main()
{
    // Prueba de constructor por default
    DoubleLinkedList<int> list;
    // prueba de operator = con initializer list
    list = {2,3,4,5,6,7};
    list.print();
    // Prueba de addFirst
    list.addFirst(1);
    list.addFirst(0);
    // Prueba de addLast
    list.addLast(8);
    list.addLast(9);
    // prueba de print
    list.print();
    // prueba de printReverse
    list.printReverse();
    // prueba de getData
    try {
        int data = list.getData(4);
        cout << "Data at position 4: " << data << endl;
    } catch (out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    // prueba de []
    try {
        int data = list[0];
        cout << "Data at position 0: " << data << endl;
    } catch (out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    // prueba de deleteAt
    if (list.deleteAt(9)) {
        cout << "Data at position 9 deleted" << endl;
    } else {
        cout << "Data at position 9 not found" << endl;
    }
    list.print();
    // prueba de deleteData
    if (list.deleteData(8)) {
        cout << "Data 8 deleted" << endl;
    } else {
        cout << "Data 8 not found" << endl;
    }
    list.print();
    // prueba de updateAt
    try {
        list.updateAt(5,50);
        cout << "Data at position 5: " << list[5] << endl;
    } catch (out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    list.print();
    // prueba de updateData
    try {
        list.updateAt(4,40);
        cout << "Data at position 4: " << list[4] << endl;
    } catch (out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    list.print();
    // prueba de insert
    list.insertAt(3,20);
    list.insertAt(0,-1);
    list.print();
    // prueba de findData
    try {
        int index = list.findData(20);
        cout << "Data 20 found at position " << index << endl;
    } catch (out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    // prueba de operator =
    DoubleLinkedList<int> list2;
    list2 = {1,2,3,4,5,6,7,8,9,10};
    list = list2;
    list.print();

    return 0;
}