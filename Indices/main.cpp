#include "indices.h"
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int target = 11;
    vector<int> nums = {3,2, 8};
    int test[3] = {1, 2, 3};

    std::pair<int, int> result = getNumSums(nums, target, test);
    std::cout << "Result: [" << result.first << "," << result.second << "]" << std::endl;
    
    return 0;
}
