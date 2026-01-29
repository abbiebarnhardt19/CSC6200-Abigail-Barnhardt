#include "Dijkstra’s Algorithm.h"
#include <iostream>
using namespace std;

int main() {

    // initialize an empty matrix with dimensions equaling the number or vertices
    int numVertices = 4;
    std::vector<std::vector<int>> testGraph(numVertices, std::vector<int>(numVertices));

    // add edges with weights
    testGraph = add_edge(testGraph, 0, 1, 6);
    testGraph = add_edge(testGraph, 0, 2, 2);
    testGraph = add_edge(testGraph, 1, 3, 4);
    testGraph = add_edge(testGraph, 2, 3, 1);

    print_matrix(testGraph);
    algorithm(0, 1, testGraph);

    return 0;
}
