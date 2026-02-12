#include <iostream>
#include "Huffman Coding.h"
#include <algorithm>

//function to print the tree, this code mostly comes from a stack overflow thread
void printTree(const std::string& prefix, const Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├────" : "└────" );

        // print the value of the node
        std::cout << node->content.first << ", " << node->content.second << std::endl;

        // enter the next tree level - left and right branch
        printTree( prefix + (isLeft ? "│   " : "       "), node->leftChild, true);
        printTree( prefix + (isLeft ? "│   " : "       "), node->rightChild, false);
    }
}

void printTree(const Node* node)
{
    printTree("", node, false);    
}

//helper function to compare nodes for sorting
bool compareNodes(Node* one, Node* two){
    //check which nodes are bigger
    return one->content.first < two->content.first;
}

//function to assemble the huffman tree
Node* buildHuffTree(std::string string_one, std::vector<int> freq)
{
    //make a vector of nodes
    std::vector<Node*> nodes;

    // create nodes for each character
    for (int i = 0; i < freq.size(); i++) {
        nodes.push_back(new Node(freq[i], string_one[i]));
    }

    // assemble the tree using the nodes
    while (nodes.size() > 1) {

        // sort nodes using built in sort and compare function
        std::sort(nodes.begin(), nodes.end(), compareNodes);

        //take the two smallest
        Node* left  = nodes[0];
        Node* right = nodes[1];

        //create parent, use * as indicator
        Node* parent = new Node(left->content.first + right->content.first, '*');

        //make the two smallest nodes children of the parent
        parent->leftChild  = left;
        parent->rightChild = right;

        // remove the two smallest nodes
        nodes.erase(nodes.begin());
        nodes.erase(nodes.begin());

        //add the parent node to the list
        nodes.push_back(parent);
    }

    //display the tree
    printTree(nodes[0]);

    //return the root
    return nodes[0];
}

//function to traverse the tree to get the nodes
void printCodes(Node* root, std::string currPath){
    //if the path stops, stop
    if (root == nullptr){
        return;
    }
    //if its a leaf node, print code and then stop
    if(root->content.second != '*'){
        std::cout << root->content.second << ":" << currPath << std::endl;
        return;
    }
    //if not a leaf node, go left and go right
    printCodes(root->leftChild, currPath + "0");
    printCodes(root->rightChild, currPath + "1");
}
