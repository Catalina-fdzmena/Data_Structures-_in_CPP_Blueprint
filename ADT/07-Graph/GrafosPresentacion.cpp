#include <iostream>
#include <vector>
using namespace std;

#include "Graph.h"
#include "Edge.h"

int main()
{
    vector<char> vertices = {'A','B','C','D','E','F','G','H','I','J'};
    Graph<char> graph(vertices);
    
    graph.insert(Edge<char>('A','B',0));
    graph.insert(Edge<char>('A','E',0));
    graph.insert(Edge<char>('A','H',0));
    graph.insert(Edge<char>('B','A',0));
    graph.insert(Edge<char>('B','C',0));
    graph.insert(Edge<char>('B','E',0));
    graph.insert(Edge<char>('C','B',0));
    graph.insert(Edge<char>('C','D',0));
    graph.insert(Edge<char>('C','E',0));
    graph.insert(Edge<char>('C','F',0));
    graph.insert(Edge<char>('D','C',0));
    graph.insert(Edge<char>('E','A',0));
    graph.insert(Edge<char>('E','B',0));
    graph.insert(Edge<char>('E','C',0));
    graph.insert(Edge<char>('E','G',0));
    graph.insert(Edge<char>('E','H',0));
    graph.insert(Edge<char>('F','C',0));
    graph.insert(Edge<char>('F','J',0));
    graph.insert(Edge<char>('G','E',0));
    graph.insert(Edge<char>('G','J',0));
    graph.insert(Edge<char>('H','A',0));
    graph.insert(Edge<char>('H','E',0));
    graph.insert(Edge<char>('H','I',0));
    graph.insert(Edge<char>('H','J',0));
    graph.insert(Edge<char>('I','H',0));
    graph.insert(Edge<char>('J','F',0));
    graph.insert(Edge<char>('J','G',0));
    graph.insert(Edge<char>('J','H',0));

    graph.print();
    graph.bfs('A');
    // graph.dfs('A');
    
    return 0;
}