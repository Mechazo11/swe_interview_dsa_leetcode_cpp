#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers
#include <cmath> // Math library
#include <unordered_map> // HashMaps
#include <numeric> // atoi

/*
Suppose an array sorted in ascending order is rotated 
at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. 
If found in the array return its index, otherwise return -1. You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n). This is binary search

- Very popular problem, this clearly shows how to apply Binary search to non-sorted arrays
- Varition of this problem is finding the smallest element
- Here comparing with middle element is not enough
- We take advantage of the pattern, nums has two distinctly equal sorted arrays
- This problem is difficult in the sense that there are too many discrete cases.

- Brute force method is O(n)

Input: nums = [4,5,6,7,0,1,2], target = 0

*/

int findIdxInRotatedArray(const std::vector<int> &nums, const int &target){

    // Initalize pointers
    int left = 0;
    int right = nums.size() - 1;
    int middle = 0;

    // Two pointer method
    while(left <= right){
        middle = left + (right - left)/2 ; 
        
        // Did any of the three pointers found the target
        if (nums[middle] == target){
            // We are done 
            return middle;
        } else if (nums[left] == target){
            return left;
        } else if (nums[right] == target){
            return right;
        } else {
            // Do nothing
        }
        
        // Is the target in left or right sorted halve
        if (nums[left] <= nums[middle]){ // Is the target in left sorted halve
            if (nums[left] <= target && target < nums[middle]){
                right = middle - 1; // Tartget is in left portion
            }
            else {
                left = middle + 1; // Target is in the right portion
            }
            
            
        } else { // target is in the right sorted position
            if (target < nums[middle] && target <= nums[right]){
                left = middle + 1; // Target is the right sorted portion
            } else {
                right = middle - 1; // Target is the left portion
            }
        }
    }

    return -1; // No answer found, target not in this array

}

int main() {

    
    std::vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0; // Ans 4
    // int target = 3; // Ans -1
    int result = findIdxInRotatedArray(nums, target);

    std::cout << "result: " << result << std::endl;

    return 0;
}
    


// ************************************



