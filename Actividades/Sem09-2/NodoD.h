//Andrea Catalina Fernández Mena A01197705 
//Actividad individual semana 09 -02

#pragma once
//Tipo de dato struct 
//Struct sirve para guardar muchos elementos de distintos tipos de datos dentro de un mismo tipo de dato
//Usando templates para mayor facilidad de unificación de datos
//Utilizamos un apuntador
template <class T>
struct Nodo {
    T data;
    Nodo<T>* left;
    Nodo<T>* right;
    Nodo (T data);
    Nodo (T data, Nodo<T>* left, Nodo<T>* right);
};
//Constructor por default
template <class T>
Nodo<T>::Nodo(T data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}
//Constructor de ordenamineto de datos.
template <class T>
Nodo<T>::Nodo(T dat,Nodo<T>* left, Nodo<T>* right){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}
