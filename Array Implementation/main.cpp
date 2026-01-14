#include "array_implementation.h"
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    //puedocode: 
    //declare a 2-D sparse matrix
    //pass it into a function that takes in the matrix and returns a new compressed matrix 
    //(3 rows, num not 0 values columns)
    //have a function that takes in compressed matrix and displays it as a sparse matrix

    vector<vector<int>> sparseMatrix = {{ 2, 3, 0, 0}, { 0, 0, 0, 1}};
    cout<<"Sparse Matrix"<<endl;
    printMatrix(sparseMatrix);

    vector<vector<int>> compressedMatrix = sparseToCompressed(sparseMatrix);

    cout<<"Compressed Matrix"<<endl;

    printMatrix(compressedMatrix);

    
    return 0;
}
