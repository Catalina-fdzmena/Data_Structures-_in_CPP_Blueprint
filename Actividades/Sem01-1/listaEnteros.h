//Andrea Catalina Fernández Mena 
//Actividad 1 Semana 1

#ifndef LISTAENTEROS_H
#define LISTAENTEROS_H
#include <iostream>
#include <vector>
#include "listaEnteros.h"
using namespace std;

class ListaEnteros
{
    private:
    vector<int>data;
    int size; //Size is being generated 
    int max; //Largest amount can be handdled by the listaEnteros

    public:
    ListaEnteros(); //Constructor por default
    void insert(int dataToInsert ); //Methods or behaviors to allow you add more items for the listaEnteros, also having a function inside of it 
    //That it works as a accumulador 
    void remove(); //Methods or behaviors to allow you to remove data from your code listaEnteros    /Void since the datatype isn't there yet
    int getData(int index); //Methods or behaviors to get index chosen visible
    int getSize(); //Methods or behaviors to know how many spaces have been occupied 
    void print(); //To show data from the listaEnteros 

};

//We generate the default constructor

ListaEnteros::ListaEnteros()
{
    max = 100; //We define a numerical value for the largest listaEnteros
    size = 0; //Sowing as well initial size as zero value
    data.resize(max); //We develop the vector called data through a merge with the max value that it can have
}

//We expand function of how you save a brand new value on your code
void ListaEnteros:: insert(int dataToInsert)
{
    if(size<max){   //Se compara que mientras el tamaño sea menor 
        data[size] = dataToInsert;
        size++;
    }
}

//Function so we can remove an element from the listaEnteros we are adding values
void ListaEnteros:: remove()
{
    if (size>0)
    {
    cout<<"The element removed is the following: "<<data[size-1]<<endl;
    size--;
    }else{
        cout<<"NO LIST ELEMENTS AVAILABLE "<<endl;
    }
}

//Function to returns index's value
//These function was not exactly declared on methods, however it gets created with help of the vector itself
int ListaEnteros:: getData(int index)
{
    if(index<size) //Validates index chosen is within the range 
    {
        return data[index];
    }else{
        cout<<"INDEX OUT OF RANGE"<<endl;
        return -1; //When a Method (set of isntructions)  is using integers if the value doesn't existe we return a -1 a best practices
    }
}

//Function that return listaEnteros's size 
int ListaEnteros::getSize(){
    return size;
}
//Function that prints the listaEnteros 

void ListaEnteros::print() {
    for (int i = 0; i < size; i++) {  
        cout << "[" << i << "] - " << data[i] << endl;
    }
}

#endif


// for i in range:
    