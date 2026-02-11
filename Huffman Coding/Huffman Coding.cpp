#include <iostream>
#include "Huffman Coding.h"
#include <algorithm>

//function to print the tree, this code mostly comes from a stack overflow thread
void printTree(const std::string& prefix, const Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->content.first << ", " << node->content.second << std::endl;

        // enter the next tree level - left and right branch
        printTree( prefix + (isLeft ? "│   " : "    "), node->leftChild, true);
        printTree( prefix + (isLeft ? "│   " : "    "), node->rightChild, false);
    }
}

void printTree(const Node* node)
{
    printTree("", node, false);    
}


// Node* buildHuffTree(std::string string_one, std::vector<int> freq)
// {
//     //make a vector of pairs to map chars to frequencies
//     std::vector<std::pair<char, int>> charFreq;

//     //fill in the vector
//     for (int i = 0; i < freq.size(); i++) {
//         charFreq.push_back({string_one[i], freq[i]});
//     }

//     // sort the vector by frequency
//     std::sort(charFreq.begin(), charFreq.end(),[](const std::pair<char, int>& left, const std::pair<char, int>& right) {return left.second < right.second; });

//     //make a size variable
//     int n = charFreq.size();

//     // make the first node so the for loop has something to go off of, use * to indicate a not-leaf node
//     Node* root = new Node(charFreq[0].second + charFreq[1].second, '*');

//     //make the children
//     root->leftChild  = new Node(charFreq[0].second, charFreq[0].first);
//     root->rightChild = new Node(charFreq[1].second, charFreq[1].first);

//     //build off that first tree until all chars are represented
//     for (int i = 2; i < n; i++) {
//         //build up the tree, with bigger values being closer to the top
//         Node* newRoot = new Node(root->content.first + charFreq[i].second, '*');

//         //make the old root the child
//         newRoot->leftChild  = root;
//         newRoot->rightChild = new Node(charFreq[i].second, charFreq[i].first);

//         root = newRoot;

//         std::sort(charFreq.begin(), charFreq.end(),[](const std::pair<char, int>& left, const std::pair<char, int>& right) {return left.second < right.second; });
//     }

//     printTree(root);
//     return root;
// }
Node* buildHuffTree(std::string string_one, std::vector<int> freq)
{
    std::vector<Node*> nodes;

    // Step 1: create leaf nodes
    for (int i = 0; i < freq.size(); i++) {
        nodes.push_back(new Node(freq[i], string_one[i]));
    }

    // Step 2: build the tree
    while (nodes.size() > 1) {

        // Sort nodes by frequency (smallest first)
        std::sort(nodes.begin(), nodes.end(),
            [](Node* a, Node* b) {
                return a->content.first < b->content.first;
            }
        );

        // Take two smallest
        Node* left  = nodes[0];
        Node* right = nodes[1];

        // Create parent
        Node* parent = new Node(
            left->content.first + right->content.first,
            '*'
        );

        parent->leftChild  = left;
        parent->rightChild = right;

        // Remove used nodes
        nodes.erase(nodes.begin());
        nodes.erase(nodes.begin());

        // Put new tree back into list
        nodes.push_back(parent);
    }

    printTree(nodes[0]);
    return nodes[0];
}
