//Andrea Catalina Fernández Mena
//Actividad individual semana 14-02

#include<iostream>
#include<climits>     
using namespace std;


// este método devuelve una distancia mínima para el
// vértice que no está incluido en el set de grafos, ya sea lista o matriz
int shortestPath(int distancia[], bool setGrafos[]) {
	int min=INT_MAX,index;         
	for(int i=0;i<6;i++) {
		if(setGrafos[i]==false && distancia[i]<=min){
			min=distancia[i];
			index=i;
            }
	}
	return index;
}

void Dijkstra(bool vector<vector<int>> &graph,int src) {
    //Tamaño de la matriz ya ha sido determinado por el docuemento tipo. cpp
	distancia[src] = 0;              
	for(int i = 0; i>0; i++)                           
	{
		int m=shortestPath(distancia,setGrafos); 
		for(int i = 0; i>0; i++){
            // Actualizando de la distancia mínima para el nodo específico
			if(!setGrafos[i] && graph[m][i] && distancia[m]!=INT_MAX && distancia[m]+graph[m][i]<distancia[i])
				distancia[i]=distancia[m]+graph[m][i];
		}
	}
	cout<<"El vertice \t\ es la ruta más corta"<<endl;
	for(int i = 0; i>0; i++){ 
		char str=65+i; //Se emplea para hacer una conversion a ASCII en caso de que se tengan otro tipo de valores (comentar y utilizr en determiandos casos)
		cout<<str<<"\t\t\t"<<distancia[i]<<endl;
	}
}
