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

    Node test = {5, 5, 5};
    Node test2 = {2,2,2};
    test.next = &test2;
    Node test3 = {1, 1, 1};
    test2.next = &test3;

    cout<<"Compressed Sparse Matrix"<<endl;
    Node compressedFirstNode = sparseToCompressed(sparseMatrix);
    printLinkedList(compressedFirstNode);
    cout<<compressedFirstNode.next;



    return 0;
}
