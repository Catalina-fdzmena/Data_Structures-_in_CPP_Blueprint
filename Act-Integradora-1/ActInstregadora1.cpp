//Actividad Integradora 1
//Andrea Catalina Fernández Mena A01197705 

#include <iostream>
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


//We develop a function in order to structure time it last to execute a function and measure it as a tracked from its beggining to end
void startTime(struct timeval &begin) {
    gettimeofday(&begin, 0);
}
//Function to structure time it takes to get everything excuted
void getTime(struct timeval begin, struct timeval end) {
    long seconds, microseconds;
    double elapsed;
    gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;
    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed);
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

//Función con template encargada de imprimir vectores 
template<class T>
void print(vector<T> list) {
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

template <class T>
void insertionSort(vector<T>& list) {
    // Tiempo inicial
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    //Se crea ciclo donde la condicion para seguir en bucle e ir contando es
    for (int i = 1; i < list.size(); i++) {
        //Una variable auxiliar guarda la posición de i para que esta se mantenga al momento de intercambiarse
        int j = i;
        //Si el valor auxilair es mayor a 0
        while (j > 0) {
            
            //Y se realiza un intercambio solo si el valor actual j es menor que el elemento anterior (j-1)
            if(list[j] < list[j-1]) {
                //Si lo es se realiza el intercambio 
                swap(list, j, j-1);
                //Se añade un valor al contador de intercambios 
                
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

// Orden: O(log2(n))
template<class T>
//Values get organiza by themselves with library algorithm on main
int binarySearch(vector<T> lista, T dato) {
    int left, right, mid;
    left = 0;
    right = lista.size() - 1;
    
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

void imprimeRango(vector<bitacoraInformacion> &lista, bitacoraInformacion izquierda, bitacoraInformacion derecha){
    int izq = binarySearch(lista, izquierda);
    int dere = binarySearch(lista, derecha);

    //Ajuste del rightIndex para que siempre de el previo, si es que no se encuentra el valor exacto
    if((derecha < lista[dere]) && (dere!= 0)){
        dere--;
    }
    //Ajuste del leftIndex para que siempre de el valor proximo, si es que no se encuentra el valor exacto
    if((lista[izq] < izquierda) && (izq < lista.size()-1)){
        izq++;
    }

    for(int i = izq; i <= dere; i++){
        cout << lista[i];
    }
   
}

int main()
{
    vector<bitacoraInformacion> acomodarDatos(0);  //Vector para guardar las bitacoras

//=====================================================
// Lee el archivo crea las bitacoras y guarda los datos
    ifstream archivo;
    archivo.open("bitacora-01.txt");

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
            for (int i=4;i<result.size();i++)
            {
                mensaje += result[i] + " ";
            }
            bitacoraInformacion aux(mes, dia, hora, ip, mensaje);
            aux.notificacionAccess = mensaje;
            acomodarDatos.push_back(aux);
        }
    }
    archivo.close();



//=====================================================
// Acomoda los datos
    cout << endl;
    cout << "Ordenamiento: ";
    insertionSort(acomodarDatos);

//=====================================================
// Busca los rangos
    bool buscar = true;
    while(buscar){
        vector<bitacoraInformacion> buscarLista(0); //Lista para guardar los datos del usuario

        for(int i = 0; i < 2; i++){ //Pedimos los datos 2 veces
            string mes, dia, hora, ip, mensaje;
            
            cout << "Elige un mes: ";
            cin >> mes;

            cout << "Elige un dia: ";
            cin >> dia;

            cout << "Elige una hora: ";
            cin >> hora;

            bitacoraInformacion aux(mes, dia, hora, "000.000.000", "mensaje");
            buscarLista.push_back(aux);
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

        for(int i = 0; i < acomodarDatos.size();i++){
            archivoFinal << acomodarDatos[i];
        }

        archivoFinal.close();
    }

    cout << endl;
    cout << endl;
    cout << "Gracias" << endl;

    


    
    
    return 0;
}