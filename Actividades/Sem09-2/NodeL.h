//Andrea Catalina Fernández Mena A01197705 
//Actividad individual semana 09 -02

#pragma once 
template<class T>
struct NodeL {
    T data;
    NodeL<T> *next;
    NodeL(T data);
    NodeL(T data, NodeL<T> *next);
};

template<class T>
NodeL<T>::NodeL(T data) {
    this->data = data;
    this->next = NULL;
}

template<class T>
NodeL<T>::NodeL(T data, NodeL<T>* next) {
    this->data = data;
    this->next = next;
}