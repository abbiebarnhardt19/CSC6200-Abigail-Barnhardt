#include "Huffman Coding.h"
#include <vector>
#include <string>
using namespace std;

int main() {
    string string_one = "abcdef";
    vector<int> freqs = {5, 9, 12, 13, 16, 45};

    Node* root = buildHuffTree(string_one, freqs);

    return 0;
}
