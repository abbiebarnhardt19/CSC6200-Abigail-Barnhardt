#include <iostream>
#include "indices.h"
#include <array>
#include <iostream>
#include <vector>
#include <utility>

//using vector so I can get size inside function
std::pair<int, int> getNumSums(std::vector<int> nums, int target, int test[]) {
    int iterations = 0;

    std::cout << "Array size: " << sizeof(test) << std::endl;

    //check 2 <= nums.length <=104 constraint
    if (nums.size() < 2 || nums.size() > 104){
        std::cout << "Vector size not within constraints" << std::endl;
        return {-1, -1};
    }

    //check -109 <= target <= 109 constraint
    if (target < -109 || target > 109){
        std::cout << "Target not within constraints" << std::endl;
        return {-1, -1};
    }

    //check first element for -109 <= nums[i] <= 109 constraint
    if (nums[0] < -109 || nums[0] > 109){
        std::cout << "Element not within constraints" << std::endl;
        return {-1, -1};
    }

    //start at first index, stop one short of last since it will 
    //compare to the one after it
    for (int i=0; i<nums.size() - 1; i++){
        //start at index after current index and go until last index
        for(int z=i+1; z < nums.size(); z++){

            //check remaining elements for the -109 <= nums[i] <= 109 constraint
            if (nums[z] < -109 || nums[z] > 109){
                std::cout << "Element not within constraints" << std::endl;
                return {-1, -1};
            }

            //check if they equal target
            if(nums[i]+nums[z] == target){
                //if they do, print return the indexes as a pair
                return {i, z};
            }
            //just for testing efficiency
            else{
                iterations = iterations + 1;
            }
        }
    }

    //print no solution and end function
    std::cout << "No solution found in " << iterations << " itterations" << std::endl;
    return {-1, -1};
}
