//Actividad integradora 3 
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
#include "Heap.h"
#include "repeatedIP.h"

//Desarrollar Main
int main(){
//Lees txt 
   Heap<bitacoraInformacion> acomodarDatos;  //Heap para guardar las bitacoras

//=====================================================
// Lee el archivo crea las bitacoras y guarda los datos
    ifstream archivo;
    archivo.open("bitacoraHeap.txt");

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
            bitacoraInformacion auxiliar(mes, dia, hora, ip, mensaje);
            auxiliar.notificacionAccess = mensaje;
            acomodarDatos.push(auxiliar);
        }
    }
    archivo.close();


/*
//=====================================================
// Acomoda los datos
    cout << endl;
    cout << "Ordenamiento: ";
    insertionSort(acomodarDatos); */

//=====================================================
/*   

//En este caso no se solicita el rango como tal ya que debido a que no estamos buscando por fecha sino por IP el tipo de ordenamiento será distinto

// Busca los rangos
    bool buscar = true;
    while(buscar){
        vector<bitacoraInformacion> acomodarDatos(0); //Lista para guardar los datos del usuario

        for(int i = 0; i < 2; i++){ //Pedimos los datos 2 veces
            string mes, dia, hora, ip, mensaje;
            
            cout << "Elige un mes: ";
            cin >> mes;

            cout << "Elige un dia: ";
            cin >> dia;

            cout << "Elige una hora: ";
            cin >> hora;

            bitacoraInformacion aux(mes, dia, hora, "000.000.000", "mensaje");
            acomodarDatos.push_back(aux);
            cout << endl;
        }

        //Checa cual valor es el mayor
        if(acomodarDatos[0] > acomodarDatos[1]){
            bitacoraInformacion aux = acomodarDatos[1];
            acomodarDatos[1] = acomodarDatos[0];
            acomodarDatos[0] = aux;
        }

        imprimeRango(acomodarDatos, acomodarDatos[0], acomodarDatos[1]);

        string opcion;
        cout << endl;
        cout << endl;
        cout << "Quieres hacer otra busqueda? S/N: ";
        cin >> opcion;
        if(opcion == "n" || opcion == "N"){
            buscar = false;
        }

    }

*/
//=====================================================
// Manda la opción de imprimir los datos, lo cuál es este caso no se emplea ya que el ordanemiento es por IP utilizando heap para obtener los 5 datos más repetidos
/*

//No es necesario ya que se imprimirá realizando los 5 pops 
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
    cout << "Gracias" << endl; */

//Acomodas en un vector con los datos por medio de un vector utilizando estructura Heap 

//Lo mandas al Heap 

//Haces función sort utilizando el método Heap que ya ordena de mayor a menor 
acomodarDatos.sort("popularidad");
bitacoraInformacion aux, data;  //Auxiliares para comparación de tamaño 
int finalCounter = 1;  //Se elabora un contador para controlar valores repetidos
vector<repeatedIP> repeatedItems; //Se crea el vector de repetición para si almacenar los elementos y con el contador previamente hecho a su vez contabilizarlos
//Se crea un ciclo para que se puede desarrolar un pop de los valores cuando la lista no esté vacía

while(!acomodarDatos.isEmpty()){ //Mientras la lista no este vacía
    aux = acomodarDatos.pop(); //Se buscará en el vector que lee el archivo y se le hará pop a los strings dicho pop works along with Heap structure 
    //Con Heap siempre será de mayor a menor y el pop lo asumé por ser instrucción propia de la estructura jerárquica
    for(int i= 0; i<acomodarDatos.getSize(); i++){ //Mientras no sea cero
        data = acomodarDatos.pop(); //Se hace una pop
        if (data == aux){   //Si ambos valores auxiliares del pop al comparar si no es nulo y no es cero son iguales entonces 
            finalCounter++; //Se acumula un valor de repetición
        }else{
            repeatedIP backupIPS(aux.newOrderIP, finalCounter); 
            repeatedItems.push_back(backupIPS);
            finalCounter = 1;
        }
    }
}

//Hacer clase para almancenar las veces que se repite la ip 
Heap<repeatedIP> finalRanking(repeatedItems);
finalRanking.sort("popularidad");
cout << "IP's Size: "<<finalRanking.getSize()<<endl;
//Repetimos los 5 valores del ranking encontrados y los posicionamos en nuestra lista al imprimir a las 5 ip mas repetidas
cout <<finalRanking.pop()<<endl<<finalRanking.pop()<<endl<<finalRanking.pop()<<endl<<finalRanking.pop()<<endl<<finalRanking.pop()<<endl;

    return 0;
}

//Seguimos pendientes de descubrir porque el sort y el pop no está siendo detectados 

