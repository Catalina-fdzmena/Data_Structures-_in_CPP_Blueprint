//Andrea Catalina Fernández Mena A01197705

#pragma once 

template<class T>
struct NodeDouble {
    T data;
    //Utilizamos apuntadores para desfases, siempre apuneta a dos elementos dentro de la lista el primero y el que está más lejos del otro
    NodeDouble<T> *next;
    NodeDouble<T> *prev;
    NodeDouble(T data);
    //Vas a poner adelante el siguiente elemento del que estaba antes para hacer la cadena del nodo 
    NodeDouble(T data, NodeDouble<T> *next, NodeDouble<T>* prev);
};

//Constructo vacío dónde se apunta a nulos porque aún no hay ningún valor ingresado 
template<class T>
NodeDouble<T>::NodeDouble(T data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

//Jerarquizr como funciona 
template<class T>
NodeDouble<T>::NodeDouble(T data, NodeDouble<T>* next, NodeDouble<T>* prev) {
    this->data = data; //Data apunta al valor data  y así para cada uno 
    this->next = next;   //Apuntan a los parámetros ya ingresados 
    this->prev = prev;
}