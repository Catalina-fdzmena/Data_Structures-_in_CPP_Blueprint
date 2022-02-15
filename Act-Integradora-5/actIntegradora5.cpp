//Actividad Integradora 5
//Andrea Catalina Fernández Mena

#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <chora>
#include <stdio.h>
#include <sys/hora.h>
#include <math.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#include "HashTable.h"
#include "Heap.h"
#include "IP.h"
#include "getAdj.h"
#include "Edge.h"
#include "Graph.h"

using namespace std;    

int main()
{
//Inicio de lectura de archivo (reducida, fue modificada a partir de act integradora 4)
    ifstream fileIn("bitacoraGrafos.txt");
    ofstream fileOut("bitacoraGrafos.out");
//Creación de un vector que guarda vertices de la clase grafos
    vector<string> vertices; 
    string renglon;
    string data;
    char sortOut = ' ';
    //Se crea una IP con datos similares a bitácora en los cuales son útiles para hacer una sepación más óptima en la lectura de archivos
    string mes, hora, ipOrigen,ipDestino, message, dia, ip;
    int a,b,ipOrigen, ipDestino;
    //Busca la cantidad de bitácoras, IP's y adyacencias hay en la lectura de archivos
    getRenglon(fileIn, renglon);
    stringstream s1(renglon);
    s1 >> a >> b;
    // Leer las IPs
    for(int i = 0; i < b; i++){
        getRenglon(fileIn, renglon);
        stringstream s2(renglon);
        s2 >> ip;
        vertices.push_back(ip);
    }
//Se crea una hashtable para encriptar dichos datos durante el proceso a partir de un vector
    HashTable readIPHash(vertices);
    vector<string> encryptVert; //Guardar ips como hash
    encryptVert = readIPHash.getHashT();

    
    // Crear un grafo con los vertices en formato hash
    Graph<string>  graph(encryptVert);

    //Debido cambios en inforamción registrada será importante para casos donde aparecen dos Ips leer aquel que es de origen y destino
    // Leer las Bitacoras
    for (int i=0; i < m; i++)
    {
        getRenglon(fileIn, renglon);
        stringstream ss(renglon);
        
        ss >> mes >> dia >> hora >> ipOrigen >> ipDestino >> message;
        while (ss >> data)
        {
            //Se realiza lectura respetando los espacios correspondientes
            message = message + " " + data;
        }
        graph.insert(Edge<string> (ipOrigen,ipDestino));

    }
    fileIn.close();
    fileOut.close();
//Proceder a realizar el proceso de imprimir las adyacencias en un archivo a parte para mayor orden
    graph.ipAdj();
    return 0;
}