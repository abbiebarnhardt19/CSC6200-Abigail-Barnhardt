#include <array>
#include <vector>
#include <utility>


//function for printing the a 2D vector array. Takes in 2D vector, returns nothing 
void printMatrix(std::vector<std::vector<int>> sparseMatrix);

//stuct to make the linked list
struct Node {
    int row;
    int column;
    int value;
    Node* next = nullptr;
};

//function for printing the compressed array list
void printLinkedList(Node firstNode);


//function for converting the original sparse array to compressed array
//takes in 2D vector array (sparse) and returns a linked list (compressed)
Node sparseToCompressed(std::vector<std::vector<int>> sparseMatrix);




