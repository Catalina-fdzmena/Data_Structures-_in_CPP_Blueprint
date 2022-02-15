//Andrea Catalina Fernández Mena A01197705
//Actividad Integradora 4

//Actividad Integradora 4
//Andrea Catalina Fernández Mena

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
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#include "Heap.h"
#include "IP.h"
#include "Edge.h"
#include "Graph.h"


int main(){
//En dicho main sólo nos dedicaremos a la lectura del documento ya que el resto de las organizaciones acerca de los grafos se realizarán en IP.h 
    ifstream archivoEntrada("bitacoraGrafos.txt");
    ofstream archivoSalida("bitacoraGrafos.out");
    
    vector<string> vertices;
    Graph<string> graph(vertices);

    string ipLeer, output;
    string mes, tiempo, ip_o, ip_d, mensaje, dia, ip;
    int n, m, ip_origen, ip_destino;

    cout << "leyendo archivo" << endl;
    getline(archivoEntrada, ipLeer);
    stringstream string1(ipLeer);
    string1 >> n >> m;
    
    for (int i = 0; i < n; i++) {
        getline(archivoEntrada, ipLeer);
        stringstream string2(ipLeer);
        string2 >> ip;
        vertices.push_back(ip);
    }
    
    for (int i=0; i < m; i++) {
        getline(archivoEntrada, ipLeer);
        stringstream string3(ipLeer);
        
        string3 >> mes >> dia >> tiempo >> ip_o >> ip_d >> mensaje;
        while (string3 >> output) {
            mensaje = mensaje + " " + output;
        }
        graph.insert(Edge<string> (ip_o, ip_d));

    }
    archivoEntrada.close();
    archivoSalida.close();
    
    cout << endl;
    cout << "Cantidad de IP: " << n;
    cout << "Cantidad de elementos: " << m;
    cout << endl;

    cout << endl;
    graph.ipAdyacencias();
    cout << endl;
    return 0;
}
