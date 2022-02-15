//Andrea Catalina Fernández Mena A01197705

#ifndef DoubleLinkedList2_h
#define DoubleLinkedList2_h

#include "NodoD.h"

template<class T>
class DoubleLinkedList2 {
private:
    NodeDouble<T>* head;
    NodeDouble<T>* tail;
    int size;
public:
    DoubleLinkedList2(); 
    void operator=(initializer_list<T> list); 
    void operator=(DoubleLinkedList2<T> list);
    T& operator[](int index); 
    void addFirst(T data); 
    void addLast(T data); 
    bool deleteData(T data); 
    bool deleteAt(int index); 
    T getData(int index); 
    void updateAt(int index, T newData); 
    void updateData(T data, T newData); 
    void insertAt(int index, T newData); 
    int findData(T data); 
    void clear(); 
    void print(); 
    void printReverse(); 
    bool isEmpty();
    int getSize(); 
};

template<class T>
DoubleLinkedList2<T>::DoubleLinkedList2() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<class T>
void DoubleLinkedList2<T>::addFirst(T data) {
    // Revisamos la lista esta vacia
    if (isEmpty()) {
        head = new NodeDouble<T>(data);
        tail = head;
    } else {
        //Se desarrolla el nuevo NodeDouble 
        head->prev = new NodeDouble<T>(data, head, nullptr);
        head = head->prev;
    }
    // Counter
    size++;
}

template<class T>
void DoubleLinkedList2<T>::addLast(T data) {
    // Lista Vacía 
    if (isEmpty()) {
        tail = new NodeDouble<T>(data);
        head = tail;
    } else {
        // Creamos el nuevo NodeDouble
        tail->next = new NodeDouble<T>(data, nullptr, tail);
        tail = tail->next;
    }
    // incrementamos el tamaño
    size++;
}

template<class T>
T DoubleLinkedList2<T>::getData(int index) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un NodeDouble auxiliar
        NodeDouble<T>* aux;
        // Buscar el elemento cuando el indice sea menor a la mitad
        if (index < size / 2) {
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = head;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = 0;
            // Recorremos la lista hasta llegar al NodeDouble que se desea obtener
            while (auxIndex < index) {
                // Avanzamos al siguiente NodeDouble
                aux = aux->next;
                // Incrementamos el índice auxiliar
                auxIndex++;
            }
        } else { // Buscamos de atras hacia adelante
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = tail;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = size - 1;
            // Recorremos la lista hasta llegar al NodeDouble que se desea obtener
            while (auxIndex > index) {
                // Avanzamos al siguiente NodeDouble
                aux = aux->prev;
                // Decrementamos el índice auxiliar
                auxIndex--;
            }
        }
        return aux->data;
    } else {
        throw out_of_range("Índice fuera de rango");
    }
}

template<class T>
T& DoubleLinkedList2<T>::operator[](int index) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un NodeDouble auxiliar
        NodeDouble<T>* aux;
        // Buscar el elemento cuando el indice sea menor a la mitad
        if (index < size / 2) {
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = head;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = 0;
            // Recorremos la lista hasta llegar al NodeDouble que se desea obtener
            while (auxIndex < index) {
                // Avanzamos al siguiente NodeDouble
                aux = aux->next;
                // Incrementamos el índice auxiliar
                auxIndex++;
            }
        } else { // Buscamos de atras hacia adelante
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = tail;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = size - 1;
            // Recorremos la lista hasta llegar al NodeDouble que se desea obtener
            while (auxIndex > index) {
                // Avanzamos al siguiente NodeDouble
                aux = aux->prev;
                // Decrementamos el índice auxiliar
                auxIndex--;
            }
        }
        return aux->data;
    } else {
        throw out_of_range("Índice fuera de rango");
    }
}

/*template<class T>
void DoubleLinkedList2<T>::operator=(initializer_list<T> list) {
    if (isEmpty()) {
        for (T data : list) {
            addLast(data);
        }
    } else {
        throw runtime_error("Error: DoublyLinkedList no esta vacia");   
    }
}*/

template<class T>
void DoubleLinkedList2<T>::operator=(DoubleLinkedList2<T> list) {
    clear();
    if (!list.isEmpty()) {
        // creamos un apuntador auxliar para recorrer la lista que apunte a list
        NodeDouble<T>* aux = list.head;
        // Recorremos la lista hasta llegar al final
        while (aux != nullptr) {
            // Agregamos el elemento al final
            addLast(aux->data);
            // Avanzamos al siguiente NodeDouble
            aux = aux->next;
        }
        // actualizamos el tamaño de la lista
        size = list.size;
    } 
}

template<class T>
int DoubleLinkedList2<T>::findData(T data) {
    // creamos un NodeDouble auxiliar que apunte a head
    NodeDouble<T>* aux = head;
    // creamos un índice auxiliar que empezará en 0
    int auxIndex = 0;
    // Recorremos la lista hasta llegar al ultimo NodeDouble
    while(aux != nullptr) {
        // Validamos si el elemento a buscar es el elemento donde apunta aux
        if (aux->data == data) {
            // regremos el índice
            return auxIndex;
        } else {
            // Recorremos el apuntador aux
            aux = aux->next;
            // incrementamos el índice auxiliar
            auxIndex++;
        }
    }
    // No encontramos el dato
    return -1;
}

template<class T>
bool DoubleLinkedList2<T>::deleteAt(int index) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un NodeDouble auxiliar
        NodeDouble<T>* aux;
        // Buscar el elemento cuando el indice sea menor a la mitad
        if (index < size / 2) {
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = head;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = 0;
            // Recorremos la lista hasta llegar al NodeDouble que se desea obtener
            while (auxIndex < index) {
                // Avanzamos al siguiente NodeDouble
                aux = aux->next;
                // Incrementamos el índice auxiliar
                auxIndex++;
            }
        } else { // Buscamos de atras hacia adelante
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = tail;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = size - 1;
            // Recorremos la lista hasta llegar al NodeDouble que se desea obtener
            while (auxIndex > index) {
                // Avanzamos al siguiente NodeDouble
                aux = aux->prev;
                // Decrementamos el índice auxiliar
                auxIndex--;
            }
        }
        // Borramos el NodeDouble auxiliar
        // solo existe un NodeDouble
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            if (aux == head) { // Borramos el primer NodeDouble
                // asignamos head al siguiente NodeDouble
                head = head->next;
                // asignamos el prev de head a nulo
                head->prev = nullptr;
            } else {
                if (aux == tail) { // Borramos el ultimo NodeDouble
                    // asignamos tail al anterior NodeDouble
                    tail = tail->prev;
                    // asignamos el next de tail a nulo
                    tail->next = nullptr;
                } else { // Borramos un NodeDouble intermedio
                    // asignamos al next del prev de aux el valor de next de aux
                    aux->prev->next = aux->next;
                    // asignamos al prev del next de aux el valor de prev de aux
                    aux->next->prev = aux->prev;
                }
            }
        }
        // Borrar el NodeDouble auxiliar
        delete aux;
        // decrementamos el tamaño de la lista
        size--;
        // regresamos true
        return true;
    } else {
        return false;
    }
}

template<class T>
bool DoubleLinkedList2<T>::deleteData(T data) {
    // Validamos que la lista no este vacía
    if (!isEmpty()) {
        // creamos un NodeDouble auxiliar que apunte a head
        NodeDouble<T>* aux = head;
        // Recorremos la lista hasta llegar al ultimo NodeDouble
        while(aux->data != data && aux != nullptr) {
            // Recorremos el apuntador aux
            aux = aux->next;
        }
        // Validamos que si lo encontramos
        if (aux != nullptr) {
            // Borramos el NodeDouble auxiliar
            // solo existe un NodeDouble
            if (head == tail) {
                head = nullptr;
                tail = nullptr;
            } else {
                if (aux == head) { // Borramos el primer NodeDouble
                    // asignamos head al siguiente NodeDouble
                    head = head->next;
                    // asignamos el prev de head a nulo
                    head->prev = nullptr;
                } else {
                    if (aux == tail) { // Borramos el ultimo NodeDouble
                        // asignamos tail al anterior NodeDouble
                        tail = tail->prev;
                        // asignamos el next de tail a nulo
                        tail->next = nullptr;
                    } else { // Borramos un NodeDouble intermedio
                        // asignamos al next del prev de aux el valor de next de aux
                        aux->prev->next = aux->next;
                        // asignamos al prev del next de aux el valor de prev de aux
                        aux->next->prev = aux->prev;
                    }
                }
            }
            // Borrar el NodeDouble auxiliar
            delete aux;
            // decrementamos el tamaño de la lista
            size--;
            // regresamos true
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

template<class T>
void DoubleLinkedList2<T>::updateAt(int index, T newData) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un NodeDouble auxiliar
        NodeDouble<T>* aux;
        // Buscar el elemento cuando el indice sea menor a la mitad
        if (index < size / 2) {
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = head;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = 0;
            // Recorremos la lista hasta llegar al NodeDouble que se desea obtener
            while (auxIndex < index) {
                // Avanzamos al siguiente NodeDouble
                aux = aux->next;
                // Incrementamos el índice auxiliar
                auxIndex++;
            }
        } else { // Buscamos de atras hacia adelante
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = tail;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = size - 1;
            // Recorremos la lista hasta llegar al NodeDouble que se desea obtener
            while (auxIndex > index) {
                // Avanzamos al siguiente NodeDouble
                aux = aux->prev;
                // Decrementamos el índice auxiliar
                auxIndex--;
            }
        }
        // Actualizamos el NodeDouble auxiliar
        aux->data = newData;
    } else {
        throw out_of_range("Índice fuera de rango");
    }
}

template<class T>
void DoubleLinkedList2<T>::updateData(T data, T newData) {
    // Validamos que la lista no este vacia
    if (!isEmpty()) {
        // creamos un NodeDouble auxiliar que apunte a head
        NodeDouble<T>* aux = head;
        // Recorremos la lista hasta llegar al ultimo NodeDouble
        while(aux->data != data && aux != nullptr) {
            // Recorremos el apuntador aux
            aux = aux->next;
        }
        // Validamos que si lo encontramos
        if (aux != nullptr) {
            // actualizamos el NodeDouble auxiliar
            aux->data = newData;
        } else {
            throw out_of_range("Dato no encontrado");
        }
    } else {
        throw out_of_range("Lista vacia");
    }
}

template<class T>
void DoubleLinkedList2<T>::insertAt(int index, T newData) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un NodeDouble auxiliar
        NodeDouble<T>* aux;
        // Buscar el elemento cuando el indice sea menor a la mitad
        if (index < size / 2) {
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = head;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = 0;
            // Recorremos la lista hasta llegar al NodeDouble que se desea obtener
            while (auxIndex < index) {
                // Avanzamos al siguiente NodeDouble
                aux = aux->next;
                // Incrementamos el índice auxiliar
                auxIndex++;
            }
        } else { // Buscamos de atras hacia adelante
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = tail;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = size - 1;
            // Recorremos la lista hasta llegar al NodeDouble que se desea obtener
            while (auxIndex > index) {
                // Avanzamos al siguiente NodeDouble
                aux = aux->prev;
                // Decrementamos el índice auxiliar
                auxIndex--;
            }
        }
        // Validamos si vamos a insertar el elemento en la posición 0 o al principio de la lista
        if (aux == head) {
            head->prev = new NodeDouble<T>(newData, head, nullptr);
            head = head->prev;
        } else { // Insertamos un elemento después del primer elemewnto de la lista
            // asignamos el next de aux prev igual al nuevo NodeDouble
            aux->prev->next = new NodeDouble<T>(newData, aux, aux->prev);
            // asignamos el prev de aux al nuevo NodeDouble
            aux->prev = aux->prev->next;
        }
        // incrementamos el tamaño de la lista
        size++;
    } else {
        throw out_of_range("Índice fuera de rango");
    }
}


template<class T>
void DoubleLinkedList2<T>::clear() {
    if (!isEmpty()) {
        // creamos un apuntador auxiliar que apunte a head
        NodeDouble<T>* aux = head;
        // recorremos la lista hasta llegar al ultimo NodeDouble
        while (aux != nullptr) {
            // apuntamos head al siguiente elemento
            head = aux->next;
            // Borramos el espacio de memoria del NodeDouble
            delete aux;
            // Actualizamos el apuntador auxiliar
            aux = head;    
        }
        // Actualizamos el tamaño de la lista
        size = 0;
        tail = nullptr;
    }
}

template<class T>
void DoubleLinkedList2<T>::print() {
    // Validamos que la lista no este vacia
    if (!isEmpty()) {
        // creamos un apuntador auxiliar que apunte a head
        NodeDouble<T>* aux = head;
        // Recorremos la lista hasta llegar al ultimo NodeDouble
        while (aux != nullptr) {
            // Imprimimos el dato del NodeDouble
            cout << aux->data << " ";   
            // Avanzamos al siguiente NodeDouble
            aux = aux->next;
        }
        cout << endl;
    } else {
        cout << "Lista vacia" << endl;
    }
}

template<class T>
void DoubleLinkedList2<T>::printReverse() {
    // Validamos que la lista no este vacia
    if (!isEmpty()) {
        // creamos un apuntador auxiliar que apunte a tail
        NodeDouble<T>* aux = tail;
        // Recorremos la lista hasta llegar al primer NodeDouble  
        while (aux != nullptr) {    
            // Imprimimos el dato del NodeDouble
            cout << aux->data << " ";
            // Avanzamos al siguiente NodeDouble
            aux = aux->prev;        
        }
        cout << endl;
    } else {
        cout << "Lista vacia" << endl;
    }
}


template<class T>
bool DoubleLinkedList2<T>::isEmpty() {
    return size == 0;
}

template<class T>
int DoubleLinkedList2<T>::getSize() {
    return size;
}


#endif