#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers
#include <cmath> // Math library

/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 

Find all unique triplets in the array which gives the sum of zero.

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

Sort the array first - this enables efficient searching and helps eliminate duplicates [O(n^2) time]
Use a three-pointer approach:
    Fix the first element with an outer loop
    For each first element, use two pointers (left and right) to find pairs that sum with it to zero
    Skip duplicate values to avoid duplicate triplets

Why choose vector in vector: In this problem each element is a vector of exactly three elements

At best O(n^2) time complexity due to the inner loop
*/

std::vector<std::vector<int>> uniqueSet(std::vector<int> &nums) {
    // Initialize the return vector
    std::vector<std::vector<int>> ret;
    
    // Sort the array using std::sort, in memory replacement
    std::sort(nums.begin(), nums.end());

    for (auto i : nums) {
        std::cout << "val: " << i << std::endl;
    }
    
    // Outer loop - iterate through potential first elements
    // Time complexity O(n - 2) == O(n) as we need to go through at worst the entire array
    for (int i = 0; i < nums.size() - 2; i++) {
        
        // Skip duplicates for the first element
        if (i > 0 && nums[i] == nums[i-1]) continue;
        
        // Use two-pointer technique for the remaining two elements
        int left = i + 1;
        int right = nums.size() - 1;

        //* A new technique of initilizing just the left and right pointers first and then not requiring explicit 
        // Condition terminates when both pointers become equal.
        for (; left < right; ) {
            
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum < 0) {
                // Sum too small, advance left pointer to right to increase
                left++;
            } else if (sum > 0) {
                // Sum too large, move right pointer to decrease sum
                right--;
            } else {
                // Found a triplet that sums to zero
                ret.push_back({nums[i], nums[left], nums[right]});
                
                // Move both pointers
                left++;
                right--;
            }
        }

    }
    
    return ret;
}



int main() {

    std::vector<int> nums = {-1, 0,1,2,-1,-4};
    // std::vector<int> nums = {-3, 3,4,-3,1,2};
    
    std::vector<std::vector<int>> result = uniqueSet(nums);

    // Print the result in the desired format
    std::cout << "[" << std::endl;
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << "  [";
        for (size_t j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j];
            if (j < result[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
        if (i < result.size() - 1) {
            std::cout << ",";
        }
        std::cout << std::endl;
    }
    std::cout << "]" << std::endl;



    return 0;
}
    


// ************************************



