#include <iostream>
#include "Dijkstra’s Algorithm.h"
#include <vector>
#include <algorithm>

using namespace std;


// function to add an edge between two nodes
std::vector<std::vector<int>> add_edge(std::vector<std::vector<int>> adj_matrix, int nodeOne, int nodeTwo, int weight)
{
    adj_matrix[nodeOne][nodeTwo] = weight;
    adj_matrix[nodeTwo][nodeOne] = weight;

    return adj_matrix;
}

//function to print the adjacency matrix

void print_matrix(std::vector<std::vector<int>> adj_list){
    for (int i = 0; i < adj_list.size(); i++){
        for(int j = 0; j < adj_list.size(); j++){
            cout << " " << adj_list[i][j] << " ";
        }
        cout << endl;
    }
}

void print_path(std::vector<int> path){
    for (int i = 0; i < path.size() - 1; i++){
        cout << path[i] << " -> ";
    }
    cout << path[path.size()-1];
}


void algorithm(int startNode, int targetNode, const vector<vector<int>>graph) {
    //current shortest distance, currently max
    vector<int> dist(graph.size(), INT_MAX);
    //stores the path
    vector<int> prev(graph.size(), -1);
    //keep track of what nodes have been visited
    vector<bool> visited(graph.size(), false);

    //distance from start node to start node is 0
    dist[startNode] = 0;

    //itterate through each node
    for (int step = 0; step < graph.size(); step++) {
        //current best node doesn't exist yet
        int currentBestNode = -1;

        //smallest distance, max for now
        int smallestDistance = INT_MAX;

        //go through each node
        for (int i = 0; i < graph.size(); i++) {
            //if the node has not been visited and moving to this node has a shorter distance
            if (!visited[i] && dist[i] < smallestDistance) {
                //update the trackers
                smallestDistance = dist[i];
                currentBestNode = i;
            }
        }

        //if the next node is the best, get out of the loop
        if (currentBestNode == -1 || currentBestNode == targetNode) break;

        //mark the best node as visted
        visited[currentBestNode] = true;

        //go through each node
        for (int v = 0; v < graph.size(); v++) {
            //if a path exists between the new node and the current node and the current node has not been visited
            if (graph[currentBestNode][v] != 0 && !visited[v]) {
                //explore alternate path
                int alt = dist[currentBestNode] + graph[currentBestNode][v];
                //if the new path is better, take it
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = currentBestNode;
                }
            }
        }
    }

    // reconstruct path
    vector<int> path;
    for (int v = targetNode; v != -1; v = prev[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    print_path(path);
}
