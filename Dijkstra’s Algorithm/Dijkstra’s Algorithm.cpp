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
    //go through each row
    for (int i = 0; i < adj_list.size(); i++){
        //go through each column
        for(int j = 0; j < adj_list.size(); j++){
            //print the elements on the same line
            cout << " " << adj_list[i][j] << " ";
        }
        //line break for new row
        cout << endl;
    }
}

//function to print the shortest path
void print_path(std::vector<int> path){
    //go through each item in the path except the last item
    for (int i = 0; i < path.size() - 1; i++){
        //print the item and add ->
        cout << path[i] << " -> ";
    }
    //print the last item, no arrow
    cout << path[path.size()-1] << endl;
}

//dijkstra's algorithm, takes in start and target nodes and the adjacency matrix
void algorithm(int startNode, int targetNode, const vector<vector<int>>graph) {
    //current shortest distance, currently max
    vector<int> distances(graph.size(), INT_MAX);

    //stores the predecessor for each node on the path
    vector<int> predecessor(graph.size(), -1);
    
    //keep track of what nodes have been visited
    vector<bool> visited(graph.size(), false);

    //distance from start node to start node is 0
    distances[startNode] = 0;

    //itterate through each node, find the shortest path to all
    for (int step = 0; step < graph.size(); step++) {
        //current best node doesn't exist yet
        int currentBestNode = -1;

        //smallest distance, max for now
        int smallestDistance = INT_MAX;

        //go through each node and find the unvisted node with the shortest distance
        for (int i = 0; i < graph.size(); i++) {
            //if the node has not been visited and moving to this node has a shorter distance
            if (!visited[i] && distances[i] < smallestDistance) {
                //update the trackers
                smallestDistance = distances[i];
                currentBestNode = i;
            }
        }

        //if the next node is the best, get out of the loop
        if (currentBestNode == -1 || currentBestNode == targetNode) break;

        //mark the best node as visted
        visited[currentBestNode] = true;

        //go through the neighbors and see if they are a better choice
        for (int neighbor = 0; neighbor < graph.size(); neighbor++) {
            //if a path exists between the new node and the current node and the current node has not been visited
            if (graph[currentBestNode][neighbor] != 0 && !visited[neighbor]) {
                //explore alternate path
                int alt = distances[currentBestNode] + graph[currentBestNode][neighbor];
                //if the new path is better, take it
                if (alt < distances[neighbor]) {
                    distances[neighbor] = alt;
                    predecessor[neighbor] = currentBestNode;
                }
            }
        }
    }

    // reconstruct path for the target node
    vector<int> path;
    for (int v = targetNode; v != -1; v = predecessor[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    //get the total distance from the path
    int totalDistance = 0 ;
    //go through each item in the path except the last
    for (int i = 0; i<path.size()-1; i++){
        //get the distance from each element to the one after it
        totalDistance = totalDistance + graph[path[i]][path[i+1]];
    }

    //print the path and the total distance
    print_path(path);
    cout<< "Total Distance: " << totalDistance << endl;
}
