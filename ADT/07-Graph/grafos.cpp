#include <iostream>
using namespace std;
#include "GraphM.h"

int main()
{
    GraphM<char> grafo;

    char vertices[10];
    vertices[0] = 'a';
    vertices[1] = 'b';
    vertices[2] = 'c';
    vertices[3] = 'd';
    vertices[4] = 'e';
    vertices[5] = 'f';
    vertices[6] = 'g';
    vertices[7] = 'h';

    grafo.insertVertices(vertices,8);

    grafo.insert('a','e');
    grafo.insert('b','c');
    grafo.insert('b','d');
    grafo.insert('b','g');
    grafo.insert('c','e');
    grafo.insert('d','h');
    grafo.insert('f','d');
    grafo.insert('g','e');

    grafo.print();  

    grafo.remove('g','e');

    grafo.print();  
    
    return 0;
}