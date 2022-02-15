//Andrea Catalina Fernández Mena A01197705 
//Actividad individual semana 08 -02

#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h

#include "NodeDouble.h"

template<class T>
class DoubleLinkedList {
private:
    NodeDouble<T>* head;
    NodeDouble<T>* tail;
    int size;
public:
    DoubleLinkedList(); //ok
    void operator=(initializer_list<T> list); // Ver luego
    void operator=(DoubleLinkedList<T> list);
    T& operator[](int index); //ok
    void addFirst(T data); //ok
    void addLast(T data); //ok
    bool deleteData(T data); //ok
    bool deleteAt(int index); //ok
    T getData(int index); //ok
    void updateAt(int index, T newData); //ok
    void updateData(T data, T newData); //ok
    void insertAt(int index, T newData); //ok
    int findData(T data); //ok
    void clear(); //ok
    void print(); //ok
    void printReverse(); //ok
    bool isEmpty(); //ok
    int getSize(); //ok
    /////////////////////////////////////////////////////////////////////////functions added
    void sort(int list, int n); //Ordena los datos de la lista (usa el algoritmo de ordenamiento que desees).
    void bubbleSortSwap(int *node1, int *node2)
    void duplicate(int index, T newData); //Duplica cada elemento de la lista.
    void removeDuplicates(T newData); //	Elimina todos los elementos duplicados en la lista.
};

template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<class T>
void DoubleLinkedList<T>::addFirst(T data) {
    // Validamos si la lista esta vacia
    if (isEmpty()) {
        head = new NodeDouble<T>(data);
        tail = head;
    } else {
        // Creamos el nuevo nodo
        head->prev = new NodeDouble<T>(data, head, nullptr);
        head = head->prev;
    }
    // incrementamos el tamaño
    size++;
}

template<class T>
void DoubleLinkedList<T>::addLast(T data) {
    // Validamos si la lista esta vacia
    if (isEmpty()) {
        tail = new NodeDouble<T>(data);
        head = tail;
    } else {
        // Creamos el nuevo nodo
        tail->next = new NodeDouble<T>(data, nullptr, tail);
        tail = tail->next;
    }
    // incrementamos el tamaño
    size++;
}

template<class T>
T DoubleLinkedList<T>::getData(int index) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un nodo auxiliar
        NodeDouble<T>* aux;
        // Buscar el elemento cuando el indice sea menor a la mitad
        if (index < size / 2) {
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = head;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = 0;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex < index) {
                // Avanzamos al siguiente nodo
                aux = aux->next;
                // Incrementamos el índice auxiliar
                auxIndex++;
            }
        } else { // Buscamos de atras hacia adelante
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = tail;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = size - 1;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex > index) {
                // Avanzamos al siguiente nodo
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
T& DoubleLinkedList<T>::operator[](int index) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un nodo auxiliar
        NodeDouble<T>* aux;
        // Buscar el elemento cuando el indice sea menor a la mitad
        if (index < size / 2) {
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = head;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = 0;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex < index) {
                // Avanzamos al siguiente nodo
                aux = aux->next;
                // Incrementamos el índice auxiliar
                auxIndex++;
            }
        } else { // Buscamos de atras hacia adelante
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = tail;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = size - 1;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex > index) {
                // Avanzamos al siguiente nodo
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
void DoubleLinkedList<T>::operator=(initializer_list<T> list) {
    if (isEmpty()) {
        for (T data : list) {
            addLast(data);
        }
    } else {
        throw runtime_error("Error: DoublyLinkedList no esta vacia");   
    }
}

template<class T>
void DoubleLinkedList<T>::operator=(DoubleLinkedList<T> list) {
    clear();
    if (!list.isEmpty()) {
        // creamos un apuntador auxliar para recorrer la lista que apunte a list
        NodeDouble<T>* aux = list.head;
        // Recorremos la lista hasta llegar al final
        while (aux != nullptr) {
            // Agregamos el elemento al final
            addLast(aux->data);
            // Avanzamos al siguiente nodo
            aux = aux->next;
        }
        // actualizamos el tamaño de la lista
        size = list.size;
    } 
}

template<class T>
int DoubleLinkedList<T>::findData(T data) {
    // creamos un nodo auxiliar que apunte a head
    NodeDouble<T>* aux = head;
    // creamos un índice auxiliar que empezará en 0
    int auxIndex = 0;
    // Recorremos la lista hasta llegar al ultimo nodo
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
bool DoubleLinkedList<T>::deleteAt(int index) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un nodo auxiliar
        NodeDouble<T>* aux;
        // Buscar el elemento cuando el indice sea menor a la mitad
        if (index < size / 2) {
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = head;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = 0;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex < index) {
                // Avanzamos al siguiente nodo
                aux = aux->next;
                // Incrementamos el índice auxiliar
                auxIndex++;
            }
        } else { // Buscamos de atras hacia adelante
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = tail;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = size - 1;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex > index) {
                // Avanzamos al siguiente nodo
                aux = aux->prev;
                // Decrementamos el índice auxiliar
                auxIndex--;
            }
        }
        // Borramos el nodo auxiliar
        // solo existe un nodo
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            if (aux == head) { // Borramos el primer nodo
                // asignamos head al siguiente nodo
                head = head->next;
                // asignamos el prev de head a nulo
                head->prev = nullptr;
            } else {
                if (aux == tail) { // Borramos el ultimo nodo
                    // asignamos tail al anterior nodo
                    tail = tail->prev;
                    // asignamos el next de tail a nulo
                    tail->next = nullptr;
                } else { // Borramos un nodo intermedio
                    // asignamos al next del prev de aux el valor de next de aux
                    aux->prev->next = aux->next;
                    // asignamos al prev del next de aux el valor de prev de aux
                    aux->next->prev = aux->prev;
                }
            }
        }
        // Borrar el nodo auxiliar
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
bool DoubleLinkedList<T>::deleteData(T data) {
    // Validamos que la lista no este vacía
    if (!isEmpty()) {
        // creamos un nodo auxiliar que apunte a head
        NodeDouble<T>* aux = head;
        // Recorremos la lista hasta llegar al ultimo nodo
        while(aux->data != data && aux != nullptr) {
            // Recorremos el apuntador aux
            aux = aux->next;
        }
        // Validamos que si lo encontramos
        if (aux != nullptr) {
            // Borramos el nodo auxiliar
            // solo existe un nodo
            if (head == tail) {
                head = nullptr;
                tail = nullptr;
            } else {
                if (aux == head) { // Borramos el primer nodo
                    // asignamos head al siguiente nodo
                    head = head->next;
                    // asignamos el prev de head a nulo
                    head->prev = nullptr;
                } else {
                    if (aux == tail) { // Borramos el ultimo nodo
                        // asignamos tail al anterior nodo
                        tail = tail->prev;
                        // asignamos el next de tail a nulo
                        tail->next = nullptr;
                    } else { // Borramos un nodo intermedio
                        // asignamos al next del prev de aux el valor de next de aux
                        aux->prev->next = aux->next;
                        // asignamos al prev del next de aux el valor de prev de aux
                        aux->next->prev = aux->prev;
                    }
                }
            }
            // Borrar el nodo auxiliar
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
void DoubleLinkedList<T>::updateAt(int index, T newData) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un nodo auxiliar
        NodeDouble<T>* aux;
        // Buscar el elemento cuando el indice sea menor a la mitad
        if (index < size / 2) {
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = head;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = 0;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex < index) {
                // Avanzamos al siguiente nodo
                aux = aux->next;
                // Incrementamos el índice auxiliar
                auxIndex++;
            }
        } else { // Buscamos de atras hacia adelante
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = tail;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = size - 1;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex > index) {
                // Avanzamos al siguiente nodo
                aux = aux->prev;
                // Decrementamos el índice auxiliar
                auxIndex--;
            }
        }
        // Actualizamos el nodo auxiliar
        aux->data = newData;
    } else {
        throw out_of_range("Índice fuera de rango");
    }
}

template<class T>
void DoubleLinkedList<T>::updateData(T data, T newData) {
    // Validamos que la lista no este vacia
    if (!isEmpty()) {
        // creamos un nodo auxiliar que apunte a head
        NodeDouble<T>* aux = head;
        // Recorremos la lista hasta llegar al ultimo nodo
        while(aux->data != data && aux != nullptr) {
            // Recorremos el apuntador aux
            aux = aux->next;
        }
        // Validamos que si lo encontramos
        if (aux != nullptr) {
            // actualizamos el nodo auxiliar
            aux->data = newData;
        } else {
            throw out_of_range("Dato no encontrado");
        }
    } else {
        throw out_of_range("Lista vacia");
    }
}

template<class T>
void DoubleLinkedList<T>::insertAt(int index, T newData) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un nodo auxiliar
        NodeDouble<T>* aux;
        // Buscar el elemento cuando el indice sea menor a la mitad
        if (index < size / 2) {
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = head;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = 0;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex < index) {
                // Avanzamos al siguiente nodo
                aux = aux->next;
                // Incrementamos el índice auxiliar
                auxIndex++;
            }
        } else { // Buscamos de atras hacia adelante
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = tail;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = size - 1;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex > index) {
                // Avanzamos al siguiente nodo
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
            // asignamos el next de aux prev igual al nuevo nodo
            aux->prev->next = new NodeDouble<T>(newData, aux, aux->prev);
            // asignamos el prev de aux al nuevo nodo
            aux->prev = aux->prev->next;
        }
        // incrementamos el tamaño de la lista
        size++;
    } else {
        throw out_of_range("Índice fuera de rango");
    }
}


template<class T>
void DoubleLinkedList<T>::clear() {
    if (!isEmpty()) {
        // creamos un apuntador auxiliar que apunte a head
        NodeDouble<T>* aux = head;
        // recorremos la lista hasta llegar al ultimo nodo
        while (aux != nullptr) {
            // apuntamos head al siguiente elemento
            head = aux->next;
            // Borramos el espacio de memoria del nodo
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
void DoubleLinkedList<T>::print() {
    // Validamos que la lista no este vacia
    if (!isEmpty()) {
        // creamos un apuntador auxiliar que apunte a head
        NodeDouble<T>* aux = head;
        // Recorremos la lista hasta llegar al ultimo nodo
        while (aux != nullptr) {
            // Imprimimos el dato del nodo
            cout << aux->data << " ";   
            // Avanzamos al siguiente nodo
            aux = aux->next;
        }
        cout << endl;
    } else {
        cout << "Lista vacia" << endl;
    }
}

template<class T>
void DoubleLinkedList<T>::printReverse() {
    // Validamos que la lista no este vacia
    if (!isEmpty()) {
        // creamos un apuntador auxiliar que apunte a tail
        NodeDouble<T>* aux = tail;
        // Recorremos la lista hasta llegar al primer nodo  
        while (aux != nullptr) {    
            // Imprimimos el dato del nodo
            cout << aux->data << " ";
            // Avanzamos al siguiente nodo
            aux = aux->prev;        
        }
        cout << endl;
    } else {
        cout << "Lista vacia" << endl;
    }
}


template<class T>
bool DoubleLinkedList<T>::isEmpty() {
    return size == 0;
}

template<class T>
int DoubleLinkedList<T>::getSize() {
    return size;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions added for this activity 

//Ordena los datos de la lista (usa el algoritmo de ordenamiento que desees).
//Se implementará buble sort para el ordenamiento de los datos
//Método para realizar swap 
template<class T>
void DoubleLinkedList<T>::bubbleSortSwap(int *node1, int *node2)
{
    int temp = *node1;
    *node1 = *node2;
    *node2 = temp;
}
template<class T>
void DoubleLinkedList<T>::sort(int list, int n) {
    int i, j;
    for (i = 0; i < n-1; i++)    
     
    // Ciclo for para asegurarnos que los últimos elementos i esten posicionados
    for (j = 0; j < n-i-1; j++)
        if (list[j] > list[j+1])
            bubbleSortSwap(&list[j], &list[j+1]);
}
//----------------------------------------------------------------------------------------------------------------
//Duplica cada elemento de la lista.
template<class T>
void DoubleLinkedList<T>::duplicate(int index, T newData) {
    if(head==NULL){ //Si el valor que la doubly linked list está vacío
        head=newNodeDouble}else if(strcmp((head)->name, newNodeDouble->name) >= 0){
        (head)->prev=newNodeDouble; //Vaores se copian en un nuevo nodo 
        newNodeDouble->next = head; //Se hace un next y se repite el mism proceso 
        head = newNodeDouble;
        }else{
            //Nodo específico anr¿tes del punto de inserción
            newActualNode = head
            //Desarrollamos un ciclo while 
        while (newActualNode->next != NULL && strcmp(newActualNode->next->name, newNodeDouble->name) <= 0)
        {
            newActualNode = newActualNode->next;
        }
        newNodeDouble->next = newActualNode->next;
        newActualNode->next->prev = newNodeDouble;
        newActualNode->next=newNodeDouble;
        newNodeDouble->prev=newActualNode;
    }
}

//----------------------------------------------------------------------------------------------------------------

//Elimina todos los elementos duplicados en la lista.
template<class T>
void DoubleLinkedList<T>::removeDuplicates(T newData) {
    if(tail==NULL){ //Si el útilmo valor que la doubly linked list está vacío
        tail=throwbackNodeD}else if(strcmp((tail)->name, throwbackNodeD->name) >= 0){
        (tail)->next=throwbackNodeD; //Vaores se copian en un nodo que represewnta los valores previos
        throwbackNodeD->prev = tail; //Se hace un prev para revertir lo anterior y reacomoda todo en un espacio óptimo
        tail = throwbackNodeD;
        }else{
            //Nodo específico después del punto de inserción
            previousNode = tail
            //Desarrollamos un ciclo while en donde nos encargamos por medio de apuntadores de hacer que dicho nodo regrese a tener la formo que rtenía previo al duplicado
        while (previousNode->prev != NULL && strcmp(previousNode->prev->name, throwbackNodeD->name) <= 0)
        {
            previousNode = previousNode->prev;
        }
        throwbackNodeD->prev = previousNode->next;
        previousNode->prev->next = throwbackNodeD;
        previousNode->prev=throwbackNodeD;
        throwbackNodeD->next=previousNode;
    }
}

#endif