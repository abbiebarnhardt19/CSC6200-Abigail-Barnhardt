#include "Huffman Coding.h"
#include <vector>
#include <string>
using namespace std;

int main() {
    string string_one = "abcdef";
    vector<int> freqs = {5, 9, 12, 13, 16, 45};

    Node* root = nullptr;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);


    printBT(root);

    return 0;
}
