#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers
#include <cmath> // Math library
#include <unordered_map> // Unordered map

/*
525 Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1. 

Input: [0,1,]
Output: 2
Explanation: [0, 1] and [1,0] is the longest contiguous subarray with equal number of 0 and 1 and there are two of them that can be built

What is a contiguous array? Is essentially a 1D vector where elements are arranged in adjacent memory locations without any gaps

Technique: Hashtable: Map the difference of counts to index


Tracks the running difference between counts of 0s and 1s
Stores the earliest index where each difference value occurs
When a difference repeats, it means the subarray between those positions has equal 0s and 1s
Setting diffTable[0] = -1 handles the special case where the balanced subarray starts at index 0

*/

int lenContigArray(std::vector<int> &nums) {
    // To keep track of counts
    int zeros = 0; 
    int ones = 0;  
    int diff_count = 0;
    int res = 0; // result

    std::unordered_map<int, int> diffTable; // Map count[1] - count[0] to ending index of sub array
    
    // Important: Initialize with diff_count 0 at index -1
    // This handles the case where a subarray starts from index 0
    diffTable[0] = -1;

    // Iterate over the input
    for (int i = 0; i < nums.size(); i++) {
        
        // Is the element a zero or a 1
        if (nums[i] == 1) {
            ones++;
        } else {
            zeros++;
        }

        // Current difference between counts of ones and zeros
        diff_count = ones - zeros;

        // If we've seen this difference before, it means we have a subarray with equal 0s and 1s
        if (diffTable.find(diff_count) != diffTable.end()) {
            // Calculate length of current subarray with equal 0s and 1s
            res = std::max(res, i - diffTable[diff_count]);
        } else {
            // First time seeing this difference, store its position
            diffTable[diff_count] = i;
        }
    }

    return res;
}


int main() {

    std::vector<int> nums = {0,1,0}; // answer should be 2
    // std::vector<int> nums = {1,1,1,0,0}; // answer should be 2
    int result = lenContigArray(nums);
    std::cout << "max len: " << result << std::endl; 

    return 0;
}
    


// ************************************



