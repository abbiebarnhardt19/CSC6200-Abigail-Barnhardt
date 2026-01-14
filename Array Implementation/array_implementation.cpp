#include <iostream>
#include "array_implementation.h"
#include <array>
#include <iostream>
#include <vector>
#include <utility>

void printMatrix(std::vector<std::vector<int>> sparseMatrix){
    for (int i = 0; i < sparseMatrix.size(); i++) {
        
        // Inner loop for columns
        for (int j = 0; j < sparseMatrix[i].size(); j++) {
            std::cout << sparseMatrix[i][j] << " ";
        }
        //line break
        std::cout << std::endl;
    }

}

std::vector<std::vector<int>> sparseToCompressed(std::vector<std::vector<int>> sparseMatrix){
    std::vector<int> rows;
    std::vector<int> columns;
    std::vector<int> values;

    //for each row
    for (int i = 0; i < sparseMatrix.size(); i++) {
        
        //for each column
        for (int j = 0; j < sparseMatrix[i].size(); j++) {
            if(sparseMatrix[i][j] != 0){
                rows.push_back(i);
                columns.push_back(j);
                values.push_back(sparseMatrix[i][j]);
            }
        }
    }

    std::vector<std::vector<int>> compressedMatrix = {rows, columns, values};

    return compressedMatrix;
}
