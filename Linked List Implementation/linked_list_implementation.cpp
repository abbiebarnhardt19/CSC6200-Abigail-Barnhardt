#include <iostream>
#include "linked_list_implementation.h"
#include <array>
#include <iostream>
#include <vector>
#include <utility>

//function for printing the 2D vector arrays
void printMatrix(std::vector<std::vector<int>> sparseMatrix){
    //go through each row
    for (int i = 0; i < sparseMatrix.size(); i++) {
        
        //go through each column
        for (int j = 0; j < sparseMatrix[i].size(); j++) {
            //print the value
            std::cout << sparseMatrix[i][j] << " ";
        }
        //line break after each row
        std::cout << std::endl;
    }

}

//function for converting sparse array to compressed
Node sparseToCompressed(std::vector<std::vector<int>> sparseMatrix){
    Node firstNode;
    Node prevNode;
    Node currentNode;

    std::string state = "empty list";

    //for each row
    for (int i = 0; i < sparseMatrix.size(); i++) {
        
        //for each column
        for (int j = 0; j < sparseMatrix[i].size(); j++) {
            if(sparseMatrix[i][j] != 0){
                if (state == "empty list"){
                    firstNode = {i, j, sparseMatrix[i][j]};
                    state = "just head";

                }
                else if (state == "just head"){
                    currentNode = {i, j, sparseMatrix[i][j]};
                    firstNode.next = &currentNode;
                    std::cout<<firstNode.next;
                    state = "multinode list";
                }
                else{
                    prevNode = currentNode;
                    currentNode = {i, j, sparseMatrix[i][j]};
                    prevNode.next = &currentNode;
                }
            }
        }
    }

    //return the compressed matrix
    return firstNode;
}

void printLinkedList(Node firstNode){
    Node currentNode = firstNode;
    while (currentNode.next != nullptr){
        std::cout<< "{" << currentNode.row << ", " << currentNode.column << ", " << currentNode.value << "}, ";
        currentNode = *currentNode.next;
    }
    //print the last node
    std::cout<< "{" << currentNode.row << ", " << currentNode.column << ", " << currentNode.value << "}";
}
