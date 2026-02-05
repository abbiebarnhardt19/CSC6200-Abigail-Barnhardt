#ifndef Longest_Common_Substring_H
#define Longest_Common_Substring_H
#include <array>
#include <vector>
#include <utility>
#include <string>


//function called in main that returns the result
void longestCommonSubstring(std::string string_one, std::string string_two);

//function to print the results matrix
void printMatrix(std::vector<std::vector<std::string>> matrix);

//function to set up the matrix with the row+column header and second row to match exaple
void setUpMatrix(std::vector<std::vector<std::string>> &matrix, std::string string_one, std::string string_two);

//function to fill the martrix with the substring lengths
void fillMatrix(std::vector<std::vector<std::string>> &matrix);

//function to get the length of substrings to fill the matrix
int checkIfEqual(std::vector<std::vector<std::string>> &matrix, int row, int column);

//function to print the longest substring and length from matrix
void getResult(std::vector<std::vector<std::string>> &matrix);

#endif
