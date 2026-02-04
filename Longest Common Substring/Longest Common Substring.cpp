#include <iostream>
#include "Longest Common Substring.h"
#include <vector>
#include <utility>
#include <string>

//function that is called from main and will return result
//makes and updates the results matrix to eventually return the longest common substring
void longestCommonSubstring(std::string string_one, std::string string_two){

    //make the matrix, since the instructions state the strings will be the same length, just use the length of string one to intialize
    //since the matrix has row + column labels, must be a string matrix, fill with empty space at first
    std::vector<std::vector<std::string>> matrix(string_one.length()+2, std::vector<std::string>(string_one.length()+2, " "));
    
    //call function to set up the row + column labels and first row to match the example/instructions
    setUpMatrix(matrix, string_one, string_two);
    
    //print the results matrix
    printMatrix(matrix);
}

//function to print the matrix
void printMatrix(std::vector<std::vector<std::string>> matrix){
    //itterate through and print each item
    for (int i =0; i< matrix.size(); i++){
        for (int j = 0; j< matrix.size(); j++){
            std::cout<<matrix[i][j] << " ";
        }
        std::cout<<std::endl;
    }
}

//function to set up the row+column labels and first row
void setUpMatrix(std::vector<std::vector<std::string>> &matrix, std::string string_one, std::string string_two){
    //set up the row+column labels to match the example
    for(int i = 2; i<matrix.size(); i++){
        matrix[0][i] = string_one.at(i-2);
        matrix[i][0] = string_two.at(i-2);
    }

    //fill the second row and column with 0, like in the example
    //since the matrix is strings, cast 0 as a string
    for(int i = 1; i < matrix.size(); i++){
        matrix[1][i] = std::to_string(0);
        matrix[i][1] = std::to_string(0);
    }
}