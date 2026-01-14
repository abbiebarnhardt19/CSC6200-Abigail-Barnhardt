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
Node* sparseToCompressed(std::vector<std::vector<int>> sparseMatrix){
    //make node pointers to keep track of the first node and the current node
    Node* firstNode = nullptr;
    Node* currentNode = nullptr;

    //for each row in the sparse matrix
    for (int i = 0; i < sparseMatrix.size(); i++) {
        
        //for each column in the sparse matrix
        for (int j = 0; j < sparseMatrix[i].size(); j++) {
            //if the value isn't zero, it should be added to the compressed matrix
            if(sparseMatrix[i][j] != 0){

                //if there are no nodes, make it the head node
                if (firstNode == nullptr){
                    //make the node, now firstNode isnt nullptr anymore
                    firstNode = new Node{i, j, sparseMatrix[i][j], nullptr};
                }
                //if theres only the header
                else if (currentNode == nullptr){
                    //make the new node, now currentNode isnt nullptr anymore
                    currentNode = new Node{i, j, sparseMatrix[i][j], nullptr};
                    //make the first node point to the new node
                    firstNode->next = currentNode;
                }
                //if theres multiple nodes
                else{
                    //save the pointer to the node the new one will have to be attached to
                    Node* prevNode = currentNode;
                    //make the new node
                    currentNode = new Node{i, j, sparseMatrix[i][j], nullptr};
                    //connect the previous node to the new one
                    prevNode->next = currentNode;
                }
            }
        }
    }

    //return the first node of the compressed matrix
    return firstNode;
}

//function to print all the nodes in the compressed matrix
void printLinkedList(Node* firstNode){
    //set the current node to the first node
    Node* currentNode = firstNode;

    //while current node isnt the tail
    while (currentNode->next != nullptr){
        //print {row, column, value}
        std::cout<< "{" << currentNode->row << ", " << currentNode->column << ", " << currentNode->value << "}, ";
        //set current node to the next node in the list
        currentNode = currentNode->next;
    }
    //print the tail node
    std::cout<< "{" << currentNode->row << ", " << currentNode->column << ", " << currentNode->value << "}";
}
