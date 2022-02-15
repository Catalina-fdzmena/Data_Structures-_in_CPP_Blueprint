//Andrea Catalina Fernández Mena A01197705 
//Actividad individual semana 07 -03

#pragma once
//Estructura del Nodo sin la prpiedad de apuntadores de la información misma
template <class T>
struct Node
{
    T data;
    Node<T> *next;
    Node();
    Node(T data);
    Node(T data, Node<T> *next);
};

template <class T>
Node<T>::Node() {
    next = nullptr;
}

template <class T>
Node<T>::Node(T data) {
    this->data = data;
    this->next = nullptr;
}

template <class T>
Node<T>::Node(T data, Node<T> *next) {
    this->data = data;
    this->next = next;
}