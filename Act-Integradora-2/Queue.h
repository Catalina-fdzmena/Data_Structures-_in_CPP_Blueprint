//Andrea Catalina Fernández Mena A01197705

#ifndef Queue_h
#define Queue_h

#include "NodoD.h"

template<class T>
class Queue{
private:
    NodeDouble<T>* head;
    NodeDouble<T>* tail;
    int size;
public:
    Queue();
    void push(T Data);
    T pop();
    T front();
    T back();
    int getSize();
    void clear();
    void print();
    bool isEmpty();
};

template<class T>
Queue<T>::Queue() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<class T>
void Queue<T>::push(T data) {
    NodeDouble<T>* aux = new NodeDouble<T>(data);
    if (isEmpty()) {
        head = aux;
        tail = aux;
    } else {
        tail->next = aux;
        tail = aux;
    }
    size++;
}

template<class T>
T Queue<T>::pop() {
    if (!isEmpty()) {
        NodeDouble<T>* aux = head;
        T data = aux->data;
        head = aux->next;
        delete aux;
        size--;
        if (head == nullptr) {
            tail = nullptr;
        }
        return data;
    } else {
        throw runtime_error("La cola de orden se encuentra vacía ");
    }
}

template<class T>
T Queue<T>::front() {
    if (!isEmpty()) {
        return head->data;
    }
    throw runtime_error("La cola de orden se encuentra vacía ");
}

template<class T>
T Queue<T>::back() {
    if (!isEmpty()) {
        return tail->data;
    }
    throw runtime_error("La cola de orden se encuentra vacía ");
}

template<class T>
int Queue<T>::getSize() {
    return size;
}

template<class T>
void Queue<T>::clear() {
    while (head != NULL) {
        NodeDouble<T>* aux = head;
        head = aux->next;
        delete aux;
    }
    size = 0;
    tail = NULL;
}

template<class T>
void Queue<T>::print() {
    NodeDouble<T>* aux = head;
    while (aux != NULL) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}


template<class T>
bool Queue<T>::isEmpty() {
    return size == 0;
}
#endif