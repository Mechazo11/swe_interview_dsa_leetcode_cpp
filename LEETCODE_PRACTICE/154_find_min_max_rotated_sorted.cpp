#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers
#include <cmath> // Math library
#include <unordered_set>

/*
Leetcode 154: Hard
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

* The array may contain duplicates.
* Would allow duplicates affect the run-time complexity? How and why?
* Use O(log n) solution

Solution: Carefully
- 
*/


int findMaximumElementRotatedtWithBST(const std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    
    // Some edge cases
    
    if (nums.size() == 1){
        return nums[0]; // Only one element array
    } else if (nums.size() == 0) {
        return -1; // Empty array
    }

    // Main O(log n) loop, decide which way to go
    while (left < right) {
        int mid = left + (right - left) / 2; // Proportionally scales distances
        
        // Handle duplicates
        if (nums[mid] == nums[right]) {
            right--; // Reduce search space carefully
        }

        // If left portion is increasing (normal order)
        else if (nums[left] < nums[mid]) {
            left = mid; // Maximum could be mid or in right portion
        }
        // If there's a pivot in the left portion
        else {
            right = mid - 1; // Maximum must be in left portion
        }
    }

    
    return nums[left];
}

int findMinumumElementRotatedWithBST(const std::vector<int> &nums){

    // Initialize some work variables
    int left = 0;
    int right = nums.size() - 1;
    int mid = 0;

    // Big idea, we keep looking through until two value remains where the left one is minimum
    while (left < right)
    {
        mid = left + (right - left) / 2;

        // How do we handle duplicates, 
        // Logic for only looking at right side, if we did both we cannot be sure
        // where the ambiguity lies
        // At least with right side, we are scanning from right
        if (nums[mid] == nums[right]){
            right--; // advance right pointer by 1 to the left
        }

        // Now check which side is the minimum value
        // we check right because in a rotated array, the minimum part is now in the right
        // we will therefor advance the left pointer more
        if (nums[mid] > nums[right]){
            left = mid + 1; // The minima may lie on the right sorted array
        }
        else {
            // right = mid - 1; // The minima may lie on the left sorted array
            right = mid; // The minima may lie on the left sorted array
        }
    }

    return nums[left];

}

int main() {

    // std::vector<int> nums = {2,2,2,0,1}; // Answer 0 (minimum), Answer 2 (maximum)
    std::vector<int> nums = {2,3,4,6,9,12,11,8,6,4,1}; // Answer 1 (minimum), Answer 12 (maximum)

    // int result = findMaximumElementRotatedtWithBST(nums);
    // std::cout <<"Minimum " << result << std::endl;

    int result = findMinumumElementRotatedWithBST(nums);
    std::cout <<"Val " << result << std::endl;

    return 0;
}
    


// ************************************

