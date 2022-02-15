//Andrea Catalina Fernández Mena A01197705 
//Actividad individual semana 08 -02

#pragma once 

template<class T>
struct NodeDouble {
    T data;
    NodeDouble<T> *next;
    NodeDouble<T> *prev;
    NodeDouble(T data);
    NodeDouble(T data, NodeDouble<T> *next, NodeDouble<T>* prev);
};

template<class T>
NodeDouble<T>::NodeDouble(T data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

template<class T>
NodeDouble<T>::NodeDouble(T data, NodeDouble<T>* next, NodeDouble<T>* prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}