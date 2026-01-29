#include <vector>


// function to add an edge between two nodes
std::vector<std::vector<int>> add_edge(std::vector<std::vector<int>> adj_list, int nodeOne, int nodeTwo, int weight);

//function to display the adjacency matrix
void print_matrix(std::vector<std::vector<int>> adj_list);


void algorithm(int startNode, int targetNode, std::vector<std::vector<int>> graph);

void print_path(std::vector<int>);
