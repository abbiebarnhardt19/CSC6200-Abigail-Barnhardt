#include <vector>

// function to add an edge between two nodes
std::vector<std::vector<int>> add_edge(std::vector<std::vector<int>> adj_list, int nodeOne, int nodeTwo, int weight);

//function to display the adjacency matrix
void print_matrix(std::vector<std::vector<int>> adj_list);

//Dijkstra's algorithm
void algorithm(int startNode, int targetNode, std::vector<std::vector<int>> graph);

//function to print a formated version of the path
void print_path(std::vector<int>);
