#include <vector>
using namespace std;

class Graph {
private:
    // choosing to use an adjacency matrix because I like using vectors and arrays
    vector<vector<int>> adj_matrix;

public:
    // constructor
    Graph(int vertices);

    // function to add an edge between two nodes
    void add_edge(int nodeOne, int nodeTwo, int weight);

    // function to print the adjacency matrix
    void printAdjacencyMatrix();
};

