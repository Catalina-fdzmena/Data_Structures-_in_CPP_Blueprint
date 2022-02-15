//Actividad Integradora 5
//Andrea Catalina Fernández Mena A01197705

#ifndef Graph_h
#define Graph_h

#include "Edge.h"
#include "Heap.h"
#include <queue>
#include <vector>
#include <algorithm>


template <class T>
class Graph {
private:
    vector<T> vertices;
    int numVertices;
    vector < vector< Edge<T> > > adjList;
    Heap<IP> adjFound;
    int findVertex(T vertex);
    void dfsR(int vertexIndex, vector<bool> &status);
public:
    Graph();
    Graph(vector<T> vertices);
    void insert(Edge<T> edge);
    void remove(Edge<T> edge);
    void bfs(T vertex);
    void dfs(T vertex);
    void ipAdj();
    void print();
    
};

template<class T>
Graph<T>::Graph() {
    numVertices = 0;
}

template<class T>
Graph<T>::Graph(vector<T> vertices) {
    this->vertices = vertices;
    numVertices = vertices.size();
    // Inicializamos el vector adjList con vectores tipo Edge vacíos
    vector<Edge<T>> edge;
    for (int i=0;i<numVertices;i++) {
        adjList.push_back(edge);
    }
    // Creamos un vector con vectores tipo edge
    //vector < vector< Edge<T> > > adjListAux(numVertices, edge)
    //adjList = adjListAux;

}

template<class T>
int Graph<T>::findVertex(T vertex) {
    // buscamos el vértice en la lista de vertices
    auto it = find(vertices.begin(), vertices.end(), vertex);
    // Validamo si lo encontramos
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }
}

template<class T>
void Graph<T>::insert(Edge<T> edge) {
    // Buscamos el índice del vértice origen
    int indexSource = findVertex(edge.source);
    // Validamos si encontramos el vértice
    if (indexSource == -1) {
        vertices.push_back(edge.source);
        indexSource = numVertices;
        numVertices++;
        vector<Edge<T>> edgeAux;
        adjList.push_back(edgeAux);
    }
    // Buscamos el índice del vértice origen
    int indexTarget = findVertex(edge.target);
    // Validamos si encontramos el vértice
    if (indexTarget == -1) {
        vertices.push_back(edge.target);
        indexTarget = numVertices;
        numVertices++;
        vector<Edge<T>> edgeAux;
        adjList.push_back(edgeAux);
    }
    adjList[indexSource].push_back(edge);
}

template<class T>
void Graph<T>::bfs(T vertex) {
    // Buscamos el índice del vértice
    int vertexIndex = findVertex(vertex);
    // Validamos si el vértice existe
    if (vertexIndex >= 0) {
        // Creamos una lista de estados con todos los vértices
        vector<bool> status(numVertices, false);
        // Creamos una fila vacía de los vértices visitados
        queue<int> visited;
        // insertar a la fila el vértice inicial
        visited.push(vertexIndex);
        // actualizar el estado del vértice inicial
        status[vertexIndex] = true;
        // Recorremos la fila hasta que este vacía
        while (!visited.empty()) {
            // Recorremos todos los vértices adyacentes del vértice procesado
            // Actualizamos el vértice a procesar
            vertexIndex = visited.front();
            // for (int i=0; i<adjList[vertexIndex].size(); i++) {
            for (auto adj : adjList[vertexIndex]) {
                // buscamos los vértice adyacentes en la lista de vértices
                int adjIndex = findVertex(adj.target);
                // Validamos que el vértice adyacente exista
                // if (adjIndex >= 0) { // esta de más
                    // Revisamos el estado del vértice adyacente
                    if (!status[adjIndex]) {
                        // lo insertamos en la lista de vértices visitados
                        visited.push(adjIndex);
                        // Actualizamos el estado del vértice adyacente
                        status[adjIndex] = true;
                    }
                // }
            }
            // imprimimos el vértice procesado
            cout << vertices[visited.front()] << " ";
            // removemos el vértice procesado de la lista
            visited.pop(); 
        }
        cout << endl;
    }
}

template<class T>
void Graph<T>::dfsR(int vertexIndex, vector<bool> &status) {
    // Validamos estatus del vértice
    if (!status[vertexIndex]) {
        // imprimimos el vértice
        cout << vertices[vertexIndex] << " ";
        // Cambiamos su estado
        status[vertexIndex] = true;
        // Recorremos cada uno de los vértices adyacentes
        for (auto adj : adjList[vertexIndex]) {
            // Buscamos el índice del vértice adyacente
            int adjIndex = findVertex(adj.target);
            // Validamos el estado de vértice adyacente
            if (!status[adjIndex]) {
                // Llamamos a la función recusiva 
                dfsR(adjIndex, status);
            }
        }
    }
}

template<class T>
void Graph<T>::dfs(T vertex) {
    // Buscamos el índice del vértice
    int vertexIndex = findVertex(vertex);
    // Validamos si el vértice existe
    if (vertexIndex >= 0) {
        // Creamos una lista de estados con valores en falso
        vector<bool> status(numVertices, false);
        // Llamamos la función de recursividad
        dfsR(vertexIndex, status);
        // imprimos un salto de línea 
        cout << endl;
    }
}

template <class T>
void Graph<T>::ipAdj(){
    //Loop guardar la IP y sus adyacentes en el strcut IP
    for (int i = 0; i < numVertices; i++){
        IP IP(vertices[i], adjList[i].size());
        adjFound.push(IP);
    }

    //Ordenar direcciones IPs y sus adyacencentes encontrados en orden descendente 
    adjFound.sort("desc");

    // Desplegar IPs con adyacencias y almacenarlas en un txt
    cout << endl << endl << "En el siguiente archivo de tipo txt (resultados.txt) podrá ser posible encontrar las adyacencias así como la cantidad de incidencias correspondientes" << endl << endl << endl; //<< adjFound.pop() << endl;
    

    // Imprimir los resultados y guardarlos en el espacio txt correspondientes para mayor facilidad
    string texto2 = "resultados.txt";
    ofstream archivo2;
    archivo2.open(texto2,fstream::out);
    while (!adjFound.isEmpty() ){
        archivo2 << adjFound.pop();
        archivo2 << endl;
    }
    archivo2.close();
}



template<class T>
void Graph<T>::print() {
    for (int i=0; i<numVertices; i++) {
        cout << vertices[i] << " -> ";
        for (auto edge : adjList[i]) {
            cout << edge.target << " : " << edge.weight << " - ";
        }
        // otra forma
        // for (int j=0; j<adjList[i].size(); j++) {
        //     cout << adjList[i][j].target << " : " << adjList[i][j].weight;
        // }
        cout << endl;
    }
}

#endif
