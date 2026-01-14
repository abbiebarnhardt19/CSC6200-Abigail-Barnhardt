#include <iostream>
#include "linked_list_implementation.h"
#include <array>
#include <iostream>
#include <vector>
#include <utility>

//function for printing the 2D vector arrays
void printMatrix(std::vector<std::vector<int>> sparseMatrix){
    //go through each row
    for (int i = 0; i < sparseMatrix.size(); i++) {
        
        //go through each column
        for (int j = 0; j < sparseMatrix[i].size(); j++) {
            //print the value
            std::cout << sparseMatrix[i][j] << " ";
        }
        //line break after each row
        std::cout << std::endl;
    }

}

//function for converting sparse array to compressed
std::vector<std::vector<int>> sparseToCompressed(std::vector<std::vector<int>> sparseMatrix){
    //make a vector array for each column of the compressed matrix
    std::vector<int> rows;
    std::vector<int> columns;
    std::vector<int> values;

    //for each row
    for (int i = 0; i < sparseMatrix.size(); i++) {
        
        //for each column
        for (int j = 0; j < sparseMatrix[i].size(); j++) {
            if(sparseMatrix[i][j] != 0){
                //add the row index, column index, and value of the non-zero elements to their 
                //respective vectors
                rows.push_back(i);
                columns.push_back(j);
                values.push_back(sparseMatrix[i][j]);
            }
        }
    }

    //make empty 2D vector matrix
    std::vector<std::vector<int>> compressedMatrix;

    //combine the individual vectors into one compressed matrix
    for (int i = 0; i < rows.size(); i++){
        compressedMatrix.push_back({rows[i], columns[i], values[i]});
    }

    //return the compressed matrix
    return compressedMatrix;
}
