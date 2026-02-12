#ifndef HUFFMAN_CODING_H
#define HUFFMAN_CODING_H

#include <vector>
#include <string>
#include <algorithm>

//this code is roughly based on the cited Medium article, but has been modified to work better for the tree
//struct for the nodes of the graph
//keeps track of children, freqency, and the character
struct Node {
    //match the character to the frequency
    std::pair<int, char> content;
    Node* leftChild;
    Node* rightChild;

    //constructor for leaf nodes
    Node(int freq, char character) {
        content = {freq, character};
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

//function to output the tree
void printTree(const Node* node);

//helper function to sort nodes
bool compareNodes(Node* one, Node* two);

//function to build the tree
Node* buildHuffTree(std::string string_one, std::vector<int> freq);

//function to assign codes
void printCodes(Node* root, std::string currPath);

#endif
