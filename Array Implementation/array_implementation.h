#ifndef ARRAYIMPLEMENTATION_H
#define ARRAYIMPLEMENTATION_H
#include <array>
#include <vector>
#include <utility>


//function for printing the original sparse arry. Takes in 2D vector, returns nothing 
void printMatrix(std::vector<std::vector<int>> sparseMatrix);

std::vector<std::vector<int>> sparseToCompressed(std::vector<std::vector<int>> sparseMatrix);

#endif
