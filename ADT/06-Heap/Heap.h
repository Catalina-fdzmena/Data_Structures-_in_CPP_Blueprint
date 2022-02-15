//Actividad Integradora 3
//Andrea Catalina Fernández Mena
#ifndef Heap_h
#define Heap_h

#include <stack>

template<class T>
class Heap {
private:
    vector<T> heap;
    int size;
    void swap(int a, int b); //Función 
    void downSort(int pos);
public:
    Heap();
    Heap(vector<T> list);
    T pop();
    void push(T data);
    void print();
    bool isEmpty();
    int getSize();
    void sort(string order); // Va a imprimir los datos del heap de forma ordenada de acuerdo al parámetro order
};

template<class T>
Heap<T>::Heap() {
    size = 0;
}

template<class T>
void Heap<T>::swap(int a, int b) {
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template<class T>
void Heap<T>::downSort(int pos) {
    // Recorremos los hijos hasta que ya no tenga hijos o no tengamos que intercambiar nada
    while (pos * 2 + 1 < size) {
        // Buscamos los hijos
        int son1 = pos * 2 + 1;
        int son2 = pos * 2 + 2;
        int bigSon;
        if (son2 < size) {
            // Comparamos cual de los dos hijos es mayor
            heap[son1] >= heap[son2] ? bigSon = son1 : bigSon = son2;
        } else {
            bigSon = son1;
        }
        // Comparamos el valor de bigSon con el el valor de pos
        if (heap[bigSon] > heap[pos]) {
            // Intercambiomo bigson con pos
            swap(pos, bigSon);
            // Cambiamos el valor de pos por el de bigSon
            pos = bigSon;
        } else {
            // Me salgo del ciclo
            pos = size;
        }
    }
}

template<class T>
Heap<T>::Heap(vector<T> list) {
    // Validamo si la lista que recibimos esta vacía
    if (list.size() > 0) {
        // Asignamos el valor de la lista al vector heap
        heap = list;
        // asignamos el valor de size al tamaño de la lista
        size = list.size();
        // Calculamos el primero de los nodos padre
        int index = size / 2 - 1;
        // DownSort - Ordenamiento hacia abajo
        // Recorremos desde el último de los padres hasta el primer
        while (index >= 0) {
            int pos = index;
            // Llamamos al downSort
            downSort(pos);
            // decrementamos el valor de index
            index--;
        }
    }
}

template<class T>
T Heap<T>::pop() {
    // Guardamos el valor del primer elemento del heap en una variable auxiliar
    T aux = heap[0];
    // Intercambiamos la primer posición con la última posición
    swap(0,size-1);
    // eliminamos el último elemento del heap
    heap.pop_back();
    // decrementamos el tamaño del heap
    size--;
    // downSort
    downSort(0);
    // Regresamos el valor del elemento con mayor prioridad del heap
    return aux;
}

template<class T>
void Heap<T>::push(T data) {
    // insertar el nuevo elemento como última hoja del heap
    heap.push_back(data);
    // incrementamos el tamaño del heap
    size++;
    // definimos una variable pos con la posición del elemento insertado
    int pos = size-1;
    // Hacemos el upsort
    while (pos != 0) {
        // Obtenemos la posición del padre
        int parent = (pos - 1) / 2;
        // comparamos el valor de pos con el valor de parent
        if (heap[parent] < heap[pos]) {
            // Intercambiamos pos con parent
            swap(parent,pos);
            // Cambiamos el valor de pos al de parent
            pos = parent;
        } else {
            // Nos salimos del ciclo
            pos = 0;
        }
    }
}

template<class T>
void Heap<T>::sort(string order) {
    Heap<T> auxHeap(heap);
    if (order == "asc") {
        // Ordenar de forma ascendente
        stack<T> auxStack;
        // Recorremos el heap auxiliar y hacemos pop de cada uno de los elementos
        while (!auxHeap.isEmpty()) {
            auxStack.push(auxHeap.pop());
        }
        while (!auxStack.empty()) {
            cout << auxStack.top() << " ";
            auxStack.pop();
        }
        cout << endl;
    } else {
        // Ordenar de forma descendente
        // Recorremos el heap auxiliar y hacemos pop de cada uno de los elementos
        while (!auxHeap.isEmpty()) {
            cout << auxHeap.pop() << " ";
        }
        cout << endl;
    }
}

template<class T> 
void Heap<T>::print() {
    for (auto el : heap) {
        cout << el << " ";
    }
    cout << endl;
}

template<class T>
bool Heap<T>::isEmpty() {
    return size == 0;
}



#endif