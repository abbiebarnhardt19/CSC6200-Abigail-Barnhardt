#include "Dijkstra’s Algorithm.h"
#include <iostream>
using namespace std;

int main() {

    // initialize a graph with 4 vertices
    Graph testGraph(4);

    // add edges with weights
    testGraph.add_edge(0, 1, 6);
    testGraph.add_edge(0, 2, 2);
    testGraph.add_edge(1, 3, 4);
    testGraph.add_edge(2, 3, 1);

    // print the adjacency matrix representation of the graph
    testGraph.printAdjacencyMatrix();

    return 0;
}
