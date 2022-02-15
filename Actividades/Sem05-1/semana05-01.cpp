#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <stdio.h>
#include <sys/time.h>
using namespace std;
#include"Fraccion.h"

//We develop a function in order to structure time it last to execute a function and measure it as a tracked from its beggining to end
void startTime(struct timeval &begin) {
    gettimeofday(&begin, 0);
}

//Function to structure time it takes to get everything excuted
void getTime(struct timeval begin, struct timeval end) {
    long seconds, microseconds;
    double elapsed;
    gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;  //Para definir un segundo 
    microseconds = end.tv_usec - begin.tv_usec;  //Definir una microfunsión para microseconds
    elapsed = seconds + microseconds*1e-6;   //Función para colindar el movimiento de segundos y microsegundos (se podría hacer para un minuto)
    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed);  //We print and combine what we want to measure in secondstime
}

template<class T>  //Función para explicar el comportamiento de intercambio de valores en caso de que la condición SE CUMPLA
void swap(vector<T>& list, int i, int j) {
    //El primer valor definido como i se guarda en una variable auxiliar 
    T aux = list[i];
    //Entonces el cambio se hace igualando que el valor del espacio i sea el mismo que j
    list[i] = list[j];
    //En j colocamos el primer valor haciendo de esta manera que ahora j se posicione en i e i en j 
    list[j] = aux;
}

//Desarrollamos función para que el vector se pueda imprimir, de igual forma el ciclo for nos permite limitar la impresión al 
//tamaño del vector para evitar que quede un bucle infinito
template<class T>
void print(vector<T> list) {
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

//Creamos otra función siempre usando un template, para asegurarnos que se pueda ingresar cualquier tipo de dato
template <class T>
//Ejecutamos el algorimo de intercambio swap sort 
void swapSort(vector<T>& list, int &nSwaps, int &nComparisons) {
    // Tiempo inicial
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    for (int i = 0; i < list.size()-1; i++) {
        for (int j = i+1; j < list.size(); j++) {
            nComparisons++;
            if(list[i] > list[j]) {
                swap(list, i, j);
                nSwaps++;
            }
        }
    }
    // Tiempo final
    gettimeofday(&end, 0);
    getTime(begin, end);
}

//Creamos otra función siempre usando un template, para asegurarnos que se pueda ingresar cualquier tipo de dato
template <class T>
//Ejecutamos el algorimo de intercambio bubble sort la cuál tiene una similitud enorme con el sawp sort
void bubbleSort(vector<T>& list, int &nSwaps, int &nComparisons) {
    // Tiempo inicial
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    int aux = list.size()-1;
    bool swapped = true;
    while (aux > 0 && swapped) {
        // Inicializamos la variable booleana a false esto para que sea un default modificable una vez que comencemos a programar
        swapped = false;
        for (int i = 0; i < aux; i++) {
            nComparisons++;
            if(list[i] > list[i+1]) {
                swap(list, i, i+1);
                nSwaps++;
                swapped = true;
            }
        }
        // Decrementamos el contador auxiliar
        aux--;
    }
    // Tiempo final, contador de acciones tomadas en bubble sort 
    gettimeofday(&end, 0);
    getTime(begin, end);
}

template <class T>
void selectionSort(vector<T>& list, int &nSwaps, int &nComparisons) {
    // Comienza a calcularse el tiempo inicial
    struct timeval begin, end;
    //Función para comenzar el conteo 
    gettimeofday(&begin, 0);
    //For ciclo parecido al while con mayor presición respecto a la recursión que el mismo toma 
    //Definimos que mientras el valor sea menor al de la lista se continue acumulando 
    //Se recorre la lista del inicio hasta el penultimo elemento
    for (int i = 0; i < list.size()-1; i++) {
        //Se crea una variable auxiliar para ordenar mientras se cuarga el valor previo 
        int min = i;
        //Se crea una segunda variable para hacer una logica de doble desfasamiento hasta el final del siguiente elemento
        for (int j = i+1; j < list.size(); j++) {
            //Se agrega un valor al número de comparaciones realizadas 
            nComparisons++;
            // para el ordenaimeinto de cuál irá primero si min o j sea utiliza un if para comparar su valores 
            if(list[min] > list[j]) {
                // Cambiamos el valor de min
                min = j;
            }
        }
        //Si el valor min no es la posición i mencionada entonces se hace un intercambio de valores
        if(min != i) {
            //Por medio del uso de la función swap creada antes se realiza la organización misma de dichas acciones
            swap(list, i, min);
            //Se le añade un valor al número de intercambios
            nSwaps++;
        }
    }
    // Tiempo final
    gettimeofday(&end, 0);
    getTime(begin, end);
}

template <class T>
void insertionSort(vector<T>& list, int &nSwaps, int &nComparisons) {
    // Tiempo inicial
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    //Se crea ciclo donde la condicion para seguir en bucle e ir contando es
    for (int i = 1; i < list.size(); i++) {
        //Una variable auxiliar guarda la posición de i para que esta se mantenga al momento de intercambiarse
        int j = i;
        //Si el valor auxilair es mayor a 0
        while (j > 0) {
            //Se agrega un valor al número de comparaciones 
            nComparisons++;
            //Y se realiza un intercambio solo si el valor actual j es menor que el elemento anterior (j-1)
            if(list[j] < list[j-1]) {
                //Si lo es se realiza el intercambio 
                swap(list, j, j-1);
                //Se añade un valor al contador de intercambios 
                nSwaps++;
                //Se le reduce un valor a j-- haciendo referencia a su recursividad 
                j--;
            } else {
                //en dado caso de que no sea menor eso quiere decir que dicho valor será 0
                j = 0;
            }
        }
    }
    // Tiempo final
    gettimeofday(&end, 0);
    getTime(begin, end);
}   




//Función para mergesort 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Desarrollamos una función para explicar la separación del merge la cual va desde el medio y considerando el primer elemento de las
//Pequeñas listas que generan división
template <class T>
void merge(vector<T>& list, int start, int mid, int end, int &nComparisons) {
    // Creamos un vector auxiliar para guardar los elementos de la lista del lado izquierdo
    vector<T> left;
    // Creamos un vector auxiliar para guardar los elementos de la lista del lado derecho
    vector<T> right;
    // Creamos una variable auxiliar para guardar el tamaño de la lista del lado izquierdo
    int leftSize = mid - start + 1;
    // Creamos una variable auxiliar para guardar el tamaño de la lista del lado derecho
    int rightSize = end - mid;
    // Recorremos la lista del lado izquierdo para guardar los elementos en la lista auxiliar
    for (int i = 0; i < leftSize; i++) {
        // Guardamos el elemento en la lista auxiliar
        left.push_back(list[start + i]);
    }
    // Recorremos la lista del lado derecho para guardar los elementos en la lista auxiliar
    for (int i = 0; i < rightSize; i++) {
        // Guardamos el elemento en la lista auxiliar
        right.push_back(list[mid + 1 + i]);
    }
    // crear una variable auxiliar para guardar la posición de la lista original
    int pos = start;
    // crear una variable auxiliar para guardar la posición de la lista auxiliar izquierda
    int leftPos = 0;
    // crear una variable auxiliar para guardar la posición de la lista auxiliar derecha
    int rightPos = 0;
    // Comparar los elementos de la lista auxiliar izquierda con la lista auxiliar derecha
    while (leftPos < leftSize && rightPos < rightSize) {
        // Incrementamos el contador de comparaciones
        nComparisons++;
        // Compara el elemento leftPos con el elemento rightPos
        if (left[leftPos] < right[rightPos]) {
            // Guardamos el elemento de la lista auxiliar izquierda en la posicion pos de la lista original
            list[pos] = left[leftPos];
            // Incrementamos la posición de la lista auxiliar izquierda
            leftPos++;
        } else {
            // Guardamos el elemento de la lista auxiliar derecha en la posicion pos de la lista original
            list[pos] = right[rightPos];
            // Incrementamos la posición de la lista auxiliar derecha
            rightPos++;
        }
        // Incrementamos la posición de la lista original
        pos++;
    }
    // Recorremos la lista auxiliar izquierda para guardar los elementos restantes en la lista original
    while (leftPos < leftSize) {
        // Guardamos el elemento de la lista auxiliar izquierda en la posicion pos de la lista original
        list[pos] = left[leftPos];
        // Incrementamos la posición de la lista auxiliar izquierda
        leftPos++;
        // Incrementamos la posición de la lista original
        pos++;
    }
    // Recorremos la lista auxiliar derecha para guardar los elementos restantes en la lista original
    while (rightPos < rightSize) {
        // Guardamos el elemento de la lista auxiliar derecha en la posicion pos de la lista original
        list[pos] = right[rightPos];
        // Incrementamos la posición de la lista auxiliar derecha
        rightPos++;
        // Incrementamos la posición de la lista original
        pos++;
    }
}

template <class T>
void mergeSort(vector<T>& list, int start, int end, int &nComparisons) {
    // Mientras el indice final sea mayor que el inicial
    if (end > start) {
        // Calculamos el indice medio
        int mid = (start + end) / 2;
        // Ordenamos la lista desde el inicio hasta el indice medio
        mergeSort(list, start, mid, nComparisons);
        // Ordenamos la lista desde el indice medio hasta el final
        mergeSort(list, mid+1, end, nComparisons);
        // Unimos las dos listas
        merge(list, start, mid, end, nComparisons);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Función para quicksort 

// QuickSort
template <class T>
void quickSort(vector<T>& list, int start, int end, int &nComparisons) {
    // Mientras el indice final sea mayor que el inicial
    if (end > start) {
        // Creamos una lista auxiliar con los datos de la lista original
        vector<T> auxList = list;
        // Creamos una variable auxiliar para guardar el indice actual
        int index = start;
        // Creamos una variable auxiliar para guardar el valor del pivote
        T pivot = list[start];
        // Recorremos la lista original desde start + 1 hasta end
        for (int i = start + 1; i <= end; i++) {
            // Incrementamos el contador de comparaciones
            nComparisons++;
            // Comparamos si el elemento actual es menor que el pivote
            if (list[i] < pivot) {
                // Guardamos el elemento actual en la posicion index de la lista auxiliar
                auxList[index] = list[i];
                // Incrementamos la posicion de la lista auxiliar (index)
                index++;
            }
        }
        // Guardamos el pivote en la posicion index de la lista auxiliar
        auxList[index] = pivot;
        // Creamos una variable auxiliar para guardar el indice del pivote
        int pivotIndex = index;
        // Incrementamos la posicion de la lista auxiliar (index)
        index++;
        // Recorremos la lista original desde start + 1 hasta end
        for (int i = start + 1; i <= end; i++) {
            // incrementamos el contador de comparaciones
            nComparisons++;
            // Comparamos si el elemento actual es mayor o igual que el pivote
            if (list[i] >= pivot) {
                // Guardamos el elemento actual en la posicion index de la lista auxiliar
                auxList[index] = list[i];
                // Incrementamos la posicion de la lista auxiliar (index)
                index++;
            }
        }
        // Asignamos la lista auxiliar a la lista original
        list = auxList;
        // Ordenamos la lista original desde start hasta el indice del pivote - 1
        quickSort(list, start, pivotIndex - 1, nComparisons);
        // Ordenamos la lista original desde el indice del pivote + 1 hasta end
        quickSort(list, pivotIndex + 1, end, nComparisons);
    }
}

template<class T>
void sortAlgorithm(vector<T> &list, string algorithm) {
    int nSwaps = 0;
    int nComparisons = 0;
    cout << "Ordenamiento por " << algorithm << endl;
    // cout << "Lista original: ";
    // print(list);
    if (algorithm ==  "Intercambio") {
        swapSort(list, nSwaps, nComparisons);
    } else {
        if (algorithm ==  "Burbuja") {
            bubbleSort(list, nSwaps, nComparisons);
        } else {
            if (algorithm == "Selección Directa") {
                selectionSort(list, nSwaps, nComparisons);
            } else {
                if (algorithm == "Inserción") {
                    insertionSort(list, nSwaps, nComparisons);
                } else {
                    if (algorithm == "Merge Sort") {
                        // Tiempo inicial
                        struct timeval begin, end;
                        gettimeofday(&begin, 0);
                        mergeSort(list, 0, list.size()-1, nComparisons);
                        // Tiempo final
                        gettimeofday(&end, 0);
                        getTime(begin, end);
                    } else {
                        if (algorithm == "Quick Sort") {
                            // Tiempo inicial
                            struct timeval begin, end;
                            gettimeofday(&begin, 0);
                            quickSort(list, 0, list.size()-1, nComparisons);
                            // Tiempo final
                            gettimeofday(&end, 0);
                            getTime(begin, end);
                        }
                    }
                }
            }
        }
    }
    // cout << "Lista ordenada: ";
    // print(list);
    cout << "Número de intercambios: " << nSwaps << endl;
    cout << "Número de comparaciones: " << nComparisons << endl;
}



void createListInt(vector<int> &lista, int cantidad) {
    lista.clear();
    for (int i=0; i<cantidad; i++) {
        lista.push_back(rand() % 100000 + 1);
    }
}

void createListChar(vector<char> &lista, int cantidad) {
    lista.clear();
    int r;
    for (int i=0; i<cantidad; i++) {
        r = rand() % 26;
        lista.push_back('a' + r);
    }
}

void createListFrac(vector<Fraccion> &lista, int cantidad) {
    lista.clear();
    int numerador, denominador;
    for (int i=0;i<cantidad;i++) {
        cout << "Teclea el numerador: " << endl;
        cin >> numerador;
        cout << "Teclea el denominador: " << endl;
        cin >> denominador;
        lista.push_back(Fraccion(numerador,denominador));
    }
}

void createListString(vector<string> &lista, int cantidad) {
    lista.clear();
    string valor;
    for (int i=0;i<cantidad;i++) {
        cout << "Teclea una palabra: " << endl;
        cin >> valor;
        lista.push_back(valor);
    }
}

int main()
{
    srand(time(NULL));
    // vector<int> list = {40,50,32,45,19,2,10,23,44,28};
    vector<int> listIntOrig;
    vector<int> listInt;
    vector<Fraccion> listFracOrig;
    vector<Fraccion> listFrac;
    vector<char> listCharOrig;
    vector<char> listChar;
    vector<string> listStringOrig;
    vector<string> listString;
    int qty = 10;
    char listType = 'i';
    char opc = 'a';

    while (opc != 'z') {
                cout << endl;
        cout << "Menu" << endl;
        cout << "a) Selecciona tipo de dato para crear la lista" << endl;
        cout << "b) Orden por Intercambio" << endl;
        cout << "c) Orden por Burbuja" << endl;
        cout << "d) Orden por Selección Directa" << endl;
        cout << "e) Orden por Inserción" << endl;
        cout << "f) Merge Sort" << endl;
        cout << "g) Quick Sort" << endl;
        cout << "z) salir" << endl;
        cout << endl << "Teclea una opción: " << endl;
        cin >> opc;

        switch (opc) {
        case 'a':
            cout << "Teclea el tipo de datos deseado (e) entero, (f) fraccion, (c) char, (s) string " << endl;
            cin >> listType;
            switch (listType) {
            case 'e':
                cout << "Teclea la cantidad de números enteros que deseas en la lista" << endl;
                cin >> qty;
                createListInt(listIntOrig,qty);
                listInt = listIntOrig;
                // print(listInt);
                break;
            case 'f':
                qty = 6;
                createListFrac(listFracOrig,qty);
                listFrac = listFracOrig;
                print(listFrac);
                break;
            case 'c':
                qty = 20;
                createListChar(listCharOrig,qty);
                listChar = listCharOrig;
                print(listChar);
                break;
            case 's':
                qty = 7;
                createListString(listStringOrig,qty);
                listString = listStringOrig;
                print(listString);
                break;
            default:
                cout << "Teclea la cantidad de números enteros que deseas en la lista" << endl;
                cin >> qty;
                createListInt(listIntOrig,qty);
                listInt = listIntOrig;
                print(listInt);
                break;
            }
            break;
        case 'b':
            switch (listType) {
            case 'e':
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Intercambio");
                break;
            case 'f':
                listFrac = listFracOrig;
                sortAlgorithm(listFrac, "Intercambio");
                break;
            case 'c':
                listChar = listCharOrig;
                sortAlgorithm(listChar, "Intercambio");
                break;
            case 's':
                listString = listStringOrig;
                sortAlgorithm(listString, "Intercambio");
                break;
            default:
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Intercambio");
                break;
            }
            break;
        case 'c':
            switch (listType) {
            case 'e':
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Burbuja");
                break;
            case 'f':
                listFrac = listFracOrig;
                sortAlgorithm(listFrac, "Burbuja");
                break;
            case 'c':
                listChar = listCharOrig;
                sortAlgorithm(listChar, "Burbuja");
                break;
            case 's':
                listString = listStringOrig;
                sortAlgorithm(listString, "Burbuja");
                break;
            default:
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Burbuja");
                break;
            }
            break;
        case 'd':
            switch (listType) {
            case 'e':
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Selección Directa");
                break;
            case 'f':
                listFrac = listFracOrig;
                sortAlgorithm(listFrac, "Selección Directa");
                break;
            case 'c':
                listChar = listCharOrig;
                sortAlgorithm(listChar, "Selección Directa");
                break;
            case 's':
                listString = listStringOrig;
                sortAlgorithm(listString, "Selección Directa");
                break;
            default:
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Selección Directa");
                break;
            }
            break;    
        case 'e':
            switch (listType) {
            case 'e':
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Inserción");
                break;
            case 'f':
                listFrac = listFracOrig;
                sortAlgorithm(listFrac, "Inserción");
                break;
            case 'c':
                listChar = listCharOrig;
                sortAlgorithm(listChar, "Inserción");
                break;
            case 's':
                listString = listStringOrig;
                sortAlgorithm(listString, "Inserción");
                break;
            default:
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Inserción");
                break;
            }
            break;    
        case 'f':
            switch (listType) {
            case 'e':
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Merge Sort");
                break;
            case 'f':
                listFrac = listFracOrig;
                sortAlgorithm(listFrac, "Merge Sort");
                break;
            case 'c':
                listChar = listCharOrig;
                sortAlgorithm(listChar, "Merge Sort");
                break;
            case 's':
                listString = listStringOrig;
                sortAlgorithm(listString, "Merge Sort");
                break;
            default:
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Merge Sort");
                break;
            }
            break;    
        case 'g':
            switch (listType) {
            case 'e':
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Quick Sort");
                break;
            case 'f':
                listFrac = listFracOrig;
                sortAlgorithm(listFrac, "Quick Sort");
                break;
            case 'c':
                listChar = listCharOrig;
                sortAlgorithm(listChar, "Quick Sort");
                break;
            case 's':
                listString = listStringOrig;
                sortAlgorithm(listString, "Quick Sort");
                break;
            default:
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Quick Sort");
                break;
            }
            break;    
        case 'z':
            cout << endl << "Gracias" << endl;
            break;
        default:
            break;
        }
    }

    return 0;
}