//Andrea Catalina Fernández Mena A01197705 
//Actividad individual semana 07 -03
#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"

template <class T>
class LinkedList {
private:
    Node<T>* head;
    int size;
public:
    LinkedList();
    // ~LinkedList(); // destructor
    void addLast(T data);
    void addFirst(T data);
    T getData(int index);
    bool deleteData(T data);
    bool deleteAt(int index);
    void updateData(T data, T newData);
    void updateAt(int index, T newData);
    int getSize();
    void print();
    bool isEmpty();

};

template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

template <class T>
void LinkedList<T>::addLast(T data) {
    // Validamos si la lista esta vacia
    if (isEmpty()) {
        // Asignamos el nuevo nodo al head
        head = new Node<T>(data);
    } else {
        // Creamos una apuntador auxiliar para recorrer la lista que apunte a head
        Node<T>* aux = head;
        // Recorremos la lista hasta llegar al ultimo nodo
        while (aux->next != nullptr) {
            // Avanzamos al siguiente nodo
            aux = aux->next;
        }
        // Creamos un nuevo nodo con el dato que se desea agregar
        aux->next = new Node<T>(data);
    }
    // Incrementamos el tamaño de la lista
    size++;
}

template <class T>
void LinkedList<T>::addFirst(T data) {
    // Creamos un nuevo nodo con el dato que se desea agregar
    head = new Node<T>(data, head);
    // Incrementamos el tamaño de la lista
    size++;
}

template <class T>
T LinkedList<T>::getData(int index) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
        Node<T>* aux = head;
        // Creamos un índice auxliar que empezará en 0
        int auxIndex = 0;
        // Recorremos la lista hasta llegar al nodo que se desea obtener
        while (auxIndex < index) {
            // Avanzamos al siguiente nodo
            aux = aux->next;
            // Incrementamos el índice auxiliar
            auxIndex++;
        }
        return aux->data;
    } else {
        throw out_of_range("Índice fuera de rango");
    }
}

template<class T>
bool LinkedList<T>::deleteData(T data) {
    // Validamos que la lista no este vacia
    if (!isEmpty()) {
        // Creamos un apuntador auxiliar (prev) que apunte a head
        Node<T>* prev = head;
        // Creamos un apuntador auxiliar (aux) que apunte a head -> next
        Node<T>* aux = head->next;
        // Validamos si el elemento a borrar es el primer elemento de la lista
        if (head->data == data) {
            // apuntamos head a head->next
            head = head->next;
            // liberamos el espacio del primer elemento de la lista de memoria
            delete prev;
            // decrementamos el tamaño de la lista
            size--;
            // regremos true
            return true;
        } else {
            // Recorremos la lista hasta llegar al ultimo nodo
            while (aux != nullptr) {
                // Validamos si el elemento a borrar es el elemento donde apunta aux
                if (aux->data == data) {
                    // apuntamos prev->next a aux->next
                    prev->next = aux->next;
                    // liberamos el espacio del primer elemento de la lista de memoria
                    delete aux;
                    // decrementamos el tamaño de la lista
                    size--;
                    // regremos true
                    return true;
                } else {
                    // Recorremos los apuntadores prev y aux
                    prev = aux;
                    aux = aux->next;
                }
            }
            // No encontramos el dato
            return false;
        }
    } else {
        // La lista esta vacía
        return false;
    }
}

template<class T>
bool LinkedList<T>::deleteAt(int index) {
    // Validamos que el índice a borra se encuentré en la lista
    if (index >= 0 && index < size) {
        // Creamos un índice auxiliar que empezará en 0
        int auxIndex = 0;
        // Creamos un apuntador auxiliar (prev) que apunte a head
        Node<T>* prev = head;
        // Creamos un apuntador auxiliar (aux) que apunte a head -> next
        Node<T>* aux = head->next;
        // Validamos si el elemento a borrar es el primer elemento de la lista
        if (index == 0) {
            // apuntamos head a head->next
            head = head->next;
            // liberamos el espacio del primer elemento de la lista de memoria
            delete prev;
            // decrementamos el tamaño de la lista
            size--;
            // regremos true
            return true;
        } else {
            // incrementamos el índice auxiliar
            auxIndex++;
            // Recorremos la lista hasta llegar al índice buscado
            while (auxIndex <= index) {
                // Validamos si el elemento a borrar es el elemento donde apunta aux
                if (auxIndex == index) {
                    // apuntamos prev->next a aux->next
                    prev->next = aux->next;
                    // liberamos el espacio del primer elemento de la lista de memoria
                    delete aux;
                    // decrementamos el tamaño de la lista
                    size--;
                    // regremos true
                    return true;
                } else {
                    // Recorremos los apuntadores prev y aux
                    prev = aux;
                    aux = aux->next;
                    // incrementamos el índice auxiliar
                    auxIndex++;
                }
            }  
        }
        // No encontramos el dato
        return false;
    } else {
        // El índice no es valido
        return false;
    }
}

template<class T>
void LinkedList<T>::updateData(T data, T newData) {
    // Validamos que la lista no este vacia
    if (!isEmpty()) {
        // Creamos un apuntador auxiliar (aux) que apunte a head
        Node<T>* aux = head;
        // Recorremos la lista hasta llegar al ultimo nodo
        while (aux != nullptr) {
            // Validamos si el elemento a actualizar es el elemento donde apunta aux
            if (aux->data == data) {
                // Actualizamos el dato del nodo
                aux->data = newData;
                // no salimos de la función
                return;
            } else {
                // Recorremos el apuntador aux
                aux = aux->next;
            }
        }
        throw invalid_argument("No se encontró el dato");
    } else {
        throw invalid_argument("La lista está vacía");
    }
}

template <class T>
void LinkedList<T>::updateAt(int index, T newData) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
        Node<T>* aux = head;
        // Creamos un índice auxliar que empezará en 0
        int auxIndex = 0;
        // Recorremos la lista hasta llegar al nodo que se desea obtener
        while (auxIndex < index) {
            // Avanzamos al siguiente nodo
            aux = aux->next;
            // Incrementamos el índice auxiliar
            auxIndex++;
        }
        // Actualizamos el dato del nodo
        aux->data = newData;
        return;
    } else {
        throw out_of_range("Índice fuera de rango");
    }
}



template <class T>
void LinkedList<T>::print() {
    Node<T>* aux = head;
    // Recorremos la lista hasta llegar al ultimo nodo
    while (aux != nullptr) {
        cout << aux->data << " ";
        // Avanzamos al siguiente nodo
        aux = aux->next;
    }
    cout << endl;
}

template <class T>
bool LinkedList<T>::isEmpty() {
    return size == 0;
}

#endif /* LinkedList_h */