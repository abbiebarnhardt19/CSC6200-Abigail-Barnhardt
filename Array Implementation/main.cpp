#include "array_implementation.h"
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

    //convert the sparse matrix to conmpressed and save it seperately
    vector<vector<int>> compressedMatrix = sparseToCompressed(sparseMatrix);

    //display the compressed matrix
    cout<<"Compressed Matrix"<<endl;

    printMatrix(compressedMatrix);

    return 0;
}
