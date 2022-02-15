//Andrea Catalina Fernández Mena A01197705
#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <sys/time.h>
#include <math.h>
using namespace std; 
#include "Bitacora.h"
#include "DoubleLinkedList2.h"
#include "Queue.h"

//Resultado final

/*Orden del procedimiento 
Bitácora.h lo traduzco (Key para crear una jerarquía)
NodeDouble es el esqueleto de DLL 
La double liniked list va estructurar los datos uno por uno a manera de NodeDouble 
Luego en el .cpp Quick sort LOS ORDENA 
Y stack/queue los almancena como si fuera el DoubleLinkedList2 (PERO YA SIN USAR DoubleLinkedList2)  
*/


//Implementamos el uso de quick sort para ordenar el NodeDouble

//PRIMER INTENTO DE QUICK SORT 
//Inicializamos el swap
/*template<class T>
void swap (T* a, T* b) {
	T *temp;
	temp = a;
	a = b; 
	b = temp;
}

template<class T>
NodeDouble<T>* Particion(NodeDouble<T> *head, NodeDouble<T> *tail) {
	
	T pivot = tail->data;
	
	NodeDouble<T> *j = head->getPrev();
	
	for (NodeDouble<T> *i = head; i != tail; i = i->next) {
		//si el key en el inidice actual es menor al del medio
		if (i->data.ip <= pivot.ip){
			if(j == nullptr){
				j = head;
			} else {
				j = j->next;
			}
			//swap  con el incial
			swap(&(j->data), &(i->data));
        }
	}
	cout << "Se ejecuta despues del FOR" << endl;
	if(j == nullptr){
		j = head;
	} else {
		j = j->next;
	}
	//swap con el de la mitad
	cout << "Se ejecuta antes del segundo swap" << endl;
	swap(&(j->data), &(tail->data));
	return j;
}

//Se emplea quick sort para el ordenamiento del nodo 
template<class T>
void quickSort(NodeDouble<T> *head, NodeDouble<T> *tail){
	cout << "Se ejecuta al inicio de quickSort" << endl;
	if (tail != nullptr && head != tail && head != tail->next){
		cout << "Se ejecuta dentro del if de quickSort" << endl;
		NodeDouble<T> *p = Particion(head, tail);
		cout << "Se ejecuta despues de particion" << endl;
    	quickSort(head, p->previous);
    	cout << "Se ejecuta despues de primera recursion" << endl;
    	quickSort(p->next, tail);
    }
}
*/

//QUICK SORT CORREGIDO
//Se emplea quick sort para el ordenamiento del nodo 
void quickSort(DoubleLinkedList2<bitacoraInformacion>& list, int start, int end) {
    // Se realiza una comparación de los indices si el final es más grande que el inicial entones hacemos el quicksort
    //Y se realiza la partición a partir del pivote
    if(end > start) {
        // Dichos valores se almacenarán dentro con el uso de fila
        //Dichos valores será organizarán del valor menor 
        Queue<bitacoraInformacion> listAux;
        
        //Se crea variable para almacenar el indice actual 
        int index = start;
        //Se crea variable para almacenar el pivote
        bitacoraInformacion pivotValue = list[index];
        // Se crea un for para comparar todos los elementos de la lista con el pivote
        for (int i = start + 1; i <= end; i++) {
            
            // Se realiza comparación para ver si el elemento de la lista es menor al pivote, en caso de ser así se envia a un auxiliar mientras se realiza el nuevo ciclo
            if(list[i] < pivotValue) {
                // Se gurda elemento en list temporal y se incremente el indicide de posición
                listAux.push(list[i]);
                index++;
            }
        }
        //Variable guarda el indice de pivote
        int pivotIndex = index;
        //Pivote se alamacena en la lista auxiliar en la posición pivotIndex
        listAux.push(pivotValue);
        index++;

        //Como una segudna vuelta,todos los elementos de la lista se recorren y comparan con el pivote
        for (int i = start + 1; i <= end; i++) {
            //Si el valor es mayor que el pivote, lo agregamos a la fila
            if(list[i] >= pivotValue) {
                listAux.push(list[i]);
                index++;
            }
        }

    //Una vez ordenados los valores es posible añadirlos de manera organizada en la fila 
        for(int i = start; i <= end; i++){
            list[i] = listAux.pop();
        }
        //Lista ordenada a la derecha
        quickSort(list, pivotIndex + 1, end);
        //Lista ordenada a la izquierda
        quickSort(list, start, pivotIndex - 1);
    }
}
//Para el ordenamiento de la doubly Link List utilizaremos QUEUe para su ordenamiento

//Implementamos el uso de queue dentro de la double linked list 
/////////////////////////////////////////////////////////////////////////////////////////////////
//Se movió a archivo .h 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DESARROLLO DEL MAIN PARA EJECUCIÓN DEL ARCHIVO 

//Aplicar binary search los utilizamos para encontrar posición de DoubleLinkedList2 
// Orden: O(log2(n))
template<class T>
//Values get organiza by themselves with library algorithm on main
int binarySearch(DoubleLinkedList2<T> lista, T dato) {
    int left, right, mid;
    left = 0;
    right = lista.getSize() - 1;
    
    while(left <= right){
        mid = (left + right) / 2;
        if(lista[mid] == dato){
            return mid;
        }
        else if(dato < lista[mid]){
            right = mid - 1;
        }
        else if(lista[mid] < dato){
            left = mid + 1;
        }
    }
    return mid;
}

void imprimeRango(DoubleLinkedList2<bitacoraInformacion> &lista, bitacoraInformacion izquierda, bitacoraInformacion derecha){
    int izq = binarySearch(lista, izquierda);
    int dere = binarySearch(lista, derecha);

    //Ajuste del rightIndex para que siempre de el previo, si es que no se encuentra el valor exacto
    if((derecha < lista[dere]) && (dere!= 0)){
        dere--;
    }
    //Ajuste del leftIndex para que siempre de el valor proximo, si es que no se encuentra el valor exacto
    if((lista[izq] < izquierda) && (izq < lista.getSize()-1)){
        izq++;
    }

    for(int i = izq; i <= dere; i++){
        cout << lista[i];
    }
   
}
//Estructura de main actividad pasada  ACTIVIDAD INTEGRADORA 1 
//ES NECESARIO SUSTITUIR EL DoubleLinkedList2 CON QUEUE

int main()
{
    DoubleLinkedList2<bitacoraInformacion> acomodarDatos;  //Proeder a alamacenar guardar las bitacoras

//=====================================================
// Lee el archivo crea las bitacoras y guarda los datos
    ifstream archivo;
    archivo.open("bitacora-1.txt");

    if (archivo.is_open())
    {
        //Variables de la bitacora
        string linea;
        while (getline(archivo, linea))
        {
            
            istringstream line(linea);
            vector<string> result;
            for (string word; line>>word;)
            {
                result.push_back(word);
            }
            string mes, dia, hora, ip;
            mes = result[0];
            dia = result[1];
            hora = result[2];
            ip = result[3];

            string mensaje;
            for (int i=4;i<result.size();i++) //Vector no es necesario usar getters
            {
                mensaje += result[i] + " ";
            }
            bitacoraInformacion aux(mes, dia, hora, ip, mensaje);
            aux.notificacionAccess = mensaje;
            acomodarDatos.addFirst(aux); 
        }
    }
    archivo.close();



//=====================================================
// Acomoda los datos
    cout << endl;
    cout << "Ordenamiento: ";
    quickSort(acomodarDatos,0,acomodarDatos.getSize()-1);  //Para ordenar valolres del primero hasta el último

//=====================================================
// Busca los rangos
    bool buscar = true;
    while(buscar){
        DoubleLinkedList2<bitacoraInformacion> buscarLista; //Lista para guardar los datos del usuario

        for(int i = 0; i < 2; i++){ //Pedimos los datos 2 veces
            string mes, dia, hora, ip, mensaje;
            
            cout << "Elige un mes: ";
            cin >> mes;

            cout << "Elige un dia: ";
            cin >> dia;

            cout << "Elige una hora: ";
            cin >> hora;

            bitacoraInformacion aux(mes, dia, hora, "000.000.000", "mensaje");
            buscarLista.addFirst(aux);
            cout << endl;
        }

        //Checa cual valor es el mayor
        if(buscarLista[0] > buscarLista[1]){
            bitacoraInformacion aux = buscarLista[1];
            buscarLista[1] = buscarLista[0];
            buscarLista[0] = aux;
        }

        imprimeRango(acomodarDatos, buscarLista[0], buscarLista[1]);
        string opcion;
        cout << endl;
        cout << endl;
        cout << "Quieres hacer otra busqueda? S/N: ";
        cin >> opcion;
        if(opcion == "n" || opcion == "N"){
            buscar = false;
        }

    }


//=====================================================
// Manda la opción de imprimir los datos
    string imprimir;
    cout << endl;
    cout << "Quieres imprimir la lista ordenada? (S/N)" << endl;
    cin >> imprimir;

    //Checa si el usuario quiere imprimir los datos en un nuevo archivo de texto
    if(imprimir == "s" || imprimir == "S"){
        //Crea el archivo con los datos acomodados
        ofstream archivoFinal;
        archivoFinal.open("BitacoraFinal.txt"); //Nombre del nuevo archivo

        for(int i = 0; i < acomodarDatos.getSize();i++){ //Getter para valor privado

            archivoFinal << acomodarDatos[i];
        }

        archivoFinal.close();
    }

    cout << endl;
    cout << endl;
    cout << "Gracias" << endl;

    


    
    
    return 0;
}


