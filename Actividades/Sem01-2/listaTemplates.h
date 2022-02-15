#ifndef listaTemplates_h
#define listaTemplates_h
#include <iostream>
#include <vector>
#include "listaTemplates.h"
using namespace std;

template <class T> //We create a Template T in order to make sure it can be accepted any type of data as long as it is the same type 
class listaTemplates
{
    private:
    vector<T>data;
    int size; //Size is being generated 
    int max; //Largest amount can be handdled by the listaTemplates

    public:
    listaTemplates(); //Constructor por default
    void insert(T dataToInsert ); //Method (set of isntructions)  to allow you add more items for the listaTemplates, also having a Method (set of isntructions)  inside of it 
    //That it works as a accumulador 
    void remove(); //Method (set of isntructions)  to allow you to remove data from your code listaTemplates    /Void since the datatype isn't there yet
    T getData(int index); //Method (set of isntructions)  to get index chosen visible
    int getSize(); //Method (set of isntructions)  to know how many spaces have been occupied 
    void print(); //To show data from the listaTemplates 

};

//We generate the default constructor
template <class T>  //En cada método declarado se incializa el uso de un template y de igual forma se llama dentro de la clase 
listaTemplates<T>:: listaTemplates()
{
    max = 100; //We define a numerical value for the largest listaTemplates
    size = 0; //Sowing as well initial size as zero value
    data.resize(max); //We develop the vector called data through a merge with the max value that it can have
}


//We expand Method (set of isntructions)  of how you save a brand new value on your code
template <class T>
void listaTemplates<T>:: insert(T dataToInsert)
{
    if(size<max){   //Se compara que mientras el tamaño sea menor 
        data[size] = dataToInsert;
        size++;
    }
}

//Method (set of isntructions)  so we can remove an element from the listaTemplates we are adding values
template <class T>
void listaTemplates<T>:: remove()
{
    if (size>0)
    {
    cout<<"The element removed is the following: "<<data[size-1]<<endl;
    size--;
    }else{
        cout<<"NO LIST ELEMENTS AVAILABLE "<<endl;
    }
}

//Method (set of isntructions) to returns index's value
//These Method (set of isntructions)  was not exactly declared on methods, however it gets created with help of the vector itself
template <class T>
T listaTemplates<T>::getData(int index)
{
    if(index<size) //Validates index chosen is within the range 
    {
        return data[index];
    }else{
        throw out_of_range("INDEX OUT OF RANGE");
        // We don't use return -1 anymore since we don't know what type of data is going to be used so we use catch instead;

         //When a Method (set of isntructions)  is using integers if the value doesn't existe we return a -1 a best practices
    }
}

//Method (set of isntructions)  that return listaTemplates's size 
//For the case of void data type is not necessary to replace it with the T template, however, if it is any numerical value, it get replce with the T template contant
template <class T>
int listaTemplates<T>::getSize(){
    return size;
}
//Method (set of isntructions)  that prints the listaTemplates 
template <class T>
void listaTemplates<T>::print() {
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "] - " << data[i] << endl;
    }
}

#endif /* listaTemplates_h */