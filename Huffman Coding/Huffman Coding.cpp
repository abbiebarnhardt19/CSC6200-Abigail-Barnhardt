#include <iostream>
#include "Huffman Coding.h"



Node* insertNode(Node* root, int val) {
    // If the tree is empty, create a new node and return it
    if (root == nullptr) {
        return new Node(val);
    }
// Recur down the tree to find the correct spot
    if (val < root->content) {
        root->leftChild = insertNode(root->leftChild, val);
    } else if (val > root->content) {
        root->rightChild = insertNode(root->rightChild, val);
    }
 return root;
}

// void printTree(Node* root){
//     std::cout<<root->content<< "--" << std::endl;
// }

void printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->content << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->leftChild, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->rightChild, false);
    }
}

void printBT(const Node* node)
{
    printBT("", node, false);    
}