#include <iostream>
#include "Longest Common Substring.h"
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

//function that is called from main and will return result
//makes and updates the results matrix to eventually return the longest common substring
void longestCommonSubstring(std::string string_one, std::string string_two){

    //make the matrix, since the instructions state the strings will be the same length, just use the length of string one to intialize
    //since the matrix has row + column labels, must be a string matrix, fill with empty space at first
    std::vector<std::vector<std::string>> matrix(string_one.length()+2, std::vector<std::string>(string_one.length()+2, " "));
    
    //call function to set up the row + column labels and first row to match the example/instructions
    setUpMatrix(matrix, string_one, string_two);

    //call function to fill the matrix with the substring counts
    fillMatrix(matrix);

    //display the matrix
    printMatrix(matrix);

    //print the longest common substring
    getResult(matrix);
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
    std::cout<<std::endl;
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

//function to fill the matrix with the longest common substring values
void fillMatrix(std::vector<std::vector<std::string>> &matrix){
    //go through each remaining cell
     for (int i = 2; i < matrix.size(); i++){
        for(int j = 2; j < matrix.size(); j++){
            //fill it with the value of if there was a substring before it
            matrix[i][j] = std::to_string(checkIfEqual(matrix, j, i));
        }
     }
}

//function to check if there was a substring before
int checkIfEqual(std::vector<std::vector<std::string>> &matrix, int row, int column){
    //if we are back to the start of the word, return 0
    if(row < 2 || column < 2){
        return 0;
    }
    //if there is a match, check the character before
    else if (0 != (matrix[0][column] == matrix[row][0])){
        return 1 + checkIfEqual(matrix, row-1, column-1);
    }
    //if there is no match, return 0
    else{
        return 0;
    }
}

//function for navigating the result matrix to get the answer
void getResult(std::vector<std::vector<std::string>> &matrix){
    //keep track of the current max length and where it is located
    int currMax = 0;
    int currMaxIndex = 0;
    //go through each matrix cell
    for (int i = 1; i < matrix.size(); i++){
        for (int j = 1; j < matrix.size(); j++){
            //if the value is bigger than the current max, update
            if (std::stoi(matrix[i][j]) > currMax){
                currMax = std::stoi(matrix[i][j]);
                currMaxIndex = i;
            }
        }
    }

    std::cout<<"The longest common substring has a length of " << currMax << " and is " ;

    //get to the start of the substring
    currMaxIndex = currMaxIndex - currMax+1;

    //print each character of the substring
    for(int i = currMax; i > 0; i--){
        std::cout<<matrix[0][currMaxIndex];
        currMaxIndex = currMaxIndex + 1; 
    }
    std::cout<<std::endl;
}