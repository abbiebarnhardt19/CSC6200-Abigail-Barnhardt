#ifndef HUFFMAN_CODING_H
#define HUFFMAN_CODING_H

#include <vector>
#include <string>
#include <algorithm>

//struct for the nodes of the graph
//keeps track of children, freqency, and the character
struct Node {
    std::pair<int, char> content;
    Node* leftChild;
    Node* rightChild;


    //constructor
    Node(int freq, char character) {
        content = {freq, character};
        leftChild = nullptr;
        rightChild = nullptr;
    }

};

//function to output the tree
void printTree(const Node* node);

//function to build the tree
Node* buildHuffTree(std::string string_one, std::vector<int> freq);

#endif
