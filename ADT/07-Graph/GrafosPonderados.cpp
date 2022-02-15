#include <iostream>
using namespace std;
#include "GraphMWeighted.h"

int main()
{
    GraphMWeighted<int> grafo;

    int vertices[10] {0,1,2,3,4,5,6,7,0,0};

    grafo.insertVertices(vertices, 8);

    grafo.insert(0,4,1);
    grafo.insert(0,2,7);
    grafo.insert(1,2,7);
    grafo.insert(1,3,2);
    grafo.insert(1,5,3);
    grafo.insert(2,0,7);
    grafo.insert(2,1,7);
    grafo.insert(2,4,3);
    grafo.insert(3,1,2);
    grafo.insert(3,7,8);
    grafo.insert(4,0,1);
    grafo.insert(4,2,3);
    grafo.insert(5,1,3);
    grafo.insert(5,6,2);
    grafo.insert(5,7,6);
    grafo.insert(6,5,2);
    grafo.insert(7,3,8);
    grafo.insert(7,5,6);

    grafo.print();
    
    system("pause");
    return 0;
}