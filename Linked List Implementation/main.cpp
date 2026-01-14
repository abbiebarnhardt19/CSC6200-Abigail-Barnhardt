#include "linked_list_implementation.h"
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    //make the sparse matrix
    vector<vector<int>> sparseMatrix = {{0, 3, 0, 0}, { 0, 0, 0, 1}, {0,0,0,0}, {0, 19, 0, 0}};
    //proper output: first non-zero value is row 0, column is 1, and value is 3
    //second non-zero value is row 1, column 3, and value 1
    
    //display the original matrix
    cout<<"Sparse Matrix"<<endl;
    printMatrix(sparseMatrix);


    cout<<"Compressed Sparse Matrix"<<endl;
    //compress the sparse matrix and get the pointer to the first node
    Node* compressedFirstNode = sparseToCompressed(sparseMatrix);
    //display the compressed matrix
    printLinkedList(compressedFirstNode);

    return 0;
}
