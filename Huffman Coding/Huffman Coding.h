#ifndef HUFFMAN_CODING_H
#define HUFFMAN_CODING_H

struct Node {
    int content;
    Node* leftChild;
    Node* rightChild;


    Node(int val) {
        content = val;
        leftChild = nullptr;
        rightChild = nullptr;
    }

};

Node* insertNode(Node* root, int val);

//void printBT(Node* root);

void printBT(const Node* node);

#endif
