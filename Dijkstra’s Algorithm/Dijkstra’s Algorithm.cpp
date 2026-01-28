#include <iostream>
#include "Dijkstra’s Algorithm.h"
#include <vector>
using namespace std;

// constructor to initialize the graph
Graph::Graph(int vertices)
{
    adj_matrix = vector<vector<int>>(vertices, vector<int>(vertices, 0));
}

// function to add an edge between two nodes
void Graph::add_edge(int nodeOne, int nodeTwo, int weight)
{
    adj_matrix[nodeOne][nodeTwo] = weight;
    adj_matrix[nodeTwo][nodeOne] = weight; // undirected
}

// function to print the adjacency matrix
void Graph::printAdjacencyMatrix()
{
    cout << "Adjacency Matrix for the Graph:" << endl;

    int n = adj_matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
}
