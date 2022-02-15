//Andrea Catalina Fernández Mena A01197705
//Actividad Integradora 4

#ifndef Graph_h
#define Graph_h

#include <queue>

template <class T>
class Graph {
private:
    vector<T> vertices;
    int numVertices;
    Heap<IP> adyacencias;
    vector < vector< Edge<T> > > adjList;
    int findVertex(T vertex);
    void dfsR(int vertexIndex, vector<bool> &status);
public:
    Graph();
    Graph(vector<T> vertices);
    void insert(Edge<T> edge);
    void remove(Edge<T> edge);
    void print();
    void bfs(T vertex);
    void dfs(T vertex);
    void ipAdyacencias();
};

template<class T>
Graph<T>::Graph() {
    numVertices = 0;
}

template<class T>
Graph<T>::Graph(vector<T> vertices) {
    this->vertices = vertices;
    numVertices = vertices.size();
    vector<Edge<T>> edge;
    for (int i=0;i<numVertices;i++) {
        adjList.push_back(edge);
    }
}

template<class T>
int Graph<T>::findVertex(T vertex) {
    auto it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }
}

template<class T>
void Graph<T>::insert(Edge<T> edge) {
    int indexSource = findVertex(edge.source);
    if (indexSource == -1) {
        vertices.push_back(edge.source);
        indexSource = numVertices;
        numVertices++;
        vector<Edge<T>> edgeAux;
        adjList.push_back(edgeAux);
    }
    int indexTarget = findVertex(edge.target);
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
void Graph<T>::print() {
    for (int i=0; i<numVertices; i++) {
        cout << vertices[i] << " -> ";
        for (auto edge : adjList[i]) {
            cout << edge.target << " - ";
        }
        cout << endl;
    }
}

template <class T>
void Graph<T>::bfs(T vertex){
    int vertexIndex = findVertex(vertex);
    if (vertexIndex >= 0){
        vector<bool> status(numVertices, false);
        queue<int> visited;
        visited.push(vertexIndex);
        status[vertexIndex] = true;
        while (!visited.empty()){
            vertexIndex = visited.front();
            for (auto adj : adjList[vertexIndex]){
                int adjIndex = findVertex(adj.target);
                if (adjIndex >= 0){
                    if (!status[adjIndex]) {
                        visited.push(adjIndex);
                        status[adjIndex] = true;
                    }
                }
            }
            cout << vertices[visited.front()] << " ";
            visited.pop();
        }
        cout << endl;
    }
}

template <class T>
void Graph<T>::dfs(T vertex){
    int vertexIndex = findVertex(vertex);
    if (vertexIndex >= 0) {
        vector<bool> status(numVertices,false);
        dfsR(vertexIndex,status);
        cout << endl;
    }
}

template <class T>
void Graph<T>::dfsR(int vertexIndex, vector<bool> &status){
    if (!status[vertexIndex]){
        cout << vertices[vertexIndex] << " ";
        status[vertexIndex] = true;
        for (auto adj : adjList[vertexIndex]){
            int adjIndex = findVertex(adj.target);
            if (!status[adjIndex]){
                dfsR(adjIndex,status);
            }
        }
    }
}

template <class T>
void Graph<T>::ipAdyacencias(){
    for (int i = 0; i < numVertices; i++) {
        IP IP(vertices[i], adjList[i].size());
        adyacencias.push(IP);
    }

    adyacencias.sort("desc");

    cout << "IP con mas adyacencias: " << endl;
    cout << adyacencias.pop() << endl << adyacencias.pop() << endl << adyacencias.pop() << endl;

    string texto = "Adjecencies.txt";
    ofstream archivo;
    archivo.open(texto,fstream::out);
    while (!adyacencias.isEmpty() ){
        archivo << adyacencias.pop();
        archivo << endl;
    }
    archivo.close();
}
#endif