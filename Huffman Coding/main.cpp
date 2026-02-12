#include "Huffman Coding.h"
#include <vector>
#include <string>
using namespace std;

int main() {
    //things to pass in
    string string_one = "abcdef";
    vector<int> freqs = {5, 9, 12, 13, 16, 45};

    //make the tree and get the root node
    Node* root = buildHuffTree(string_one, freqs);

    //output the codes generated from that tree
    printCodes(root, " ");

    return 0;
}
