//Andrea Catalina Fernández Mena A01197705
//Actividad Integradora 4

#ifndef Heap_h
#define Heap_h

#include <stack>

template<class T>
class Heap {
private:
    vector<T> heap;
    int size;
    void swap(int a, int b);
    void downSort(int pos);
public:
    Heap();
    Heap(vector<T> list);
    T pop();
    void push(T data);
    void print();
    bool isEmpty();
    int getSize();
    void sort(string order);
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
    while (pos * 2 + 1 < size) {
        int son1 = pos * 2 + 1;
        int son2 = pos * 2 + 2;
        int bigSon;
        if (son2 < size) {
            heap[son1] >= heap[son2] ? bigSon = son1 : bigSon = son2;
        } else {
            bigSon = son1;
        }
        if (heap[bigSon] > heap[pos]) {
            swap(pos, bigSon);
            pos = bigSon;
        } else {
            pos = size;
        }
    }
}

template<class T>
Heap<T>::Heap(vector<T> list) {
    if (list.size() > 0) {
        heap = list;
        size = list.size();
        int index = size / 2 - 1;
        while (index >= 0) {
            int pos = index;
            downSort(pos);
            index--;
        }
    }
}

template<class T>
T Heap<T>::pop() {
    T aux = heap[0];
    swap(0,size-1);
    heap.pop_back();
    size--;
    downSort(0);
    return aux;
}

template<class T>
void Heap<T>::push(T data) {
    heap.push_back(data);
    size++;
    int pos = size-1;
    while (pos != 0) {
        int parent = (pos - 1) / 2;
        if (heap[parent] < heap[pos]) {
            swap(parent,pos);
            pos = parent;
        } else {
            pos = 0;
        }
    }
}

template<class T>
void Heap<T>::sort(string order) {
    Heap<T> auxHeap(heap);
    if (order == "asc") {
        stack<T> auxStack;
        while (!auxHeap.isEmpty()) {
            auxStack.push(auxHeap.pop());
        }
        while (!auxStack.empty()) {
            cout << auxStack.top() << " ";
            auxStack.pop();
        }
        cout << endl;
    } else {
        heap.clear();
        while (!auxHeap.isEmpty()) {
            heap.push_back(auxHeap.pop());
        }
    }
}
template<class T>
int Heap<T>::getSize() {
    return size;
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