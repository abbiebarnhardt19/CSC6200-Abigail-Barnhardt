// #ifndef ARRAYIMPLEMENTATION_H
// #define ARRAYIMPLEMENTATION_H
#include <array>
#include <vector>
#include <utility>


//function for printing the a 2D vector array. Takes in 2D vector, returns nothing 
void printMatrix(std::vector<std::vector<int>> sparseMatrix);

//function for converting the original sparse array to compressed array
//takes in 2D vector array (sparse) and returns a 2D vector array (compressed)
std::vector<std::vector<int>> sparseToCompressed(std::vector<std::vector<int>> sparseMatrix);

// #endif
