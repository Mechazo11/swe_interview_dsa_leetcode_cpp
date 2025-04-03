#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers
#include <cmath> // Math library
#include <unordered_map> // Hashmaps 
#include <numeric> // std::iota

/*
704. Given a sorted (in ascending order) integer array nums of n elements and a target value, 
write a function to search target in nums. If target exists, then return its index, otherwise return -1.
You musts write the algorithm to solve in O(log n) time.

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

- Is any edge case possible?
    - when updating the left and right 

- If the problem states to solve it in O(log n) time then we use Binary search
- Why binary search is O(log n) time: 
    - Beacause in every iteration, the search space gets halved.
    - log_2(n) passes are required which works out to O(log n) time complexity

C++ implementation based on https://www.youtube.com/watch?v=GU7DpgHINWQ&t=66s
*/

/*
367. Valid Perfect Sqaure

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Cannot use built-in sqrt function

Solve in O(log n) format

Input: 16
Output: true

Input: 14
Output: false
*/



int findTargetUsingBinarySearch(const std::vector<int> &nums, const int &target) {
    // const std::vector<int> &nums in the scope of this function, no changes can be made to nums vector
    // Initialize some work variables
    // int loopCount = nums.size();
    int leftIdx = 0;
    int rightIdx = nums.size() - 1;
    int midIdx = 0;

    while(leftIdx <= rightIdx){
        // Compute middle value
        midIdx = leftIdx + (rightIdx - leftIdx) / 2;
        
        // If mid value larger that target, shrink window from right
        if (nums[midIdx] > target){
            rightIdx = midIdx - 1; // If we do not exlcude mid exactly then we get stuck into minima and infinite loop
        } 
        else if (nums[midIdx] < target) {
            // If mid value smaller than target 
            leftIdx = midIdx + 1; // If we do not exlcude mid exactly then we get stuck into minima and infinite loop
        }
        else if (nums[midIdx] == target) {
            // Did we find our answer
            return midIdx;
        }
    }

    return -1;
}

int checkIfValidSquareUsingBST(const int &num) {
    // const std::vector<int> &nums in the scope of this function, no changes can be made to nums vector
    // Initialize some work variables
    // int loopCount = nums.size();
    
    // We need to generate a range of numbers for which to square and test if the the target number is indeed a square
    std::vector<int> nums(50); // A vector of 50 ints, all initialized to zeros
    std::iota(nums.begin(), nums.end(), 1); // The third element is the starting number from which sequntial numbers are created
    
    int leftIdx = 0;
    int rightIdx = nums.size() - 1;
    int midIdx = 0;

    while(leftIdx <= rightIdx){
        // Compute middle value
        midIdx = leftIdx + (rightIdx - leftIdx) / 2;
        
        // If mid value larger that target, shrink window from right
        if (nums[midIdx]*nums[midIdx] > num){
            rightIdx = midIdx - 1; // If we do not exlcude mid exactly then we get stuck into minima and infinite loop
        } 
        else if (nums[midIdx]*nums[midIdx] < num) {
            // If mid value smaller than target 
            leftIdx = midIdx + 1; // If we do not exlcude mid exactly then we get stuck into minima and infinite loop
        }
        else if (nums[midIdx]*nums[midIdx] == num) {
            // num is a square number, return true
            return 1; // True
        }
    }

    return 0; // False
}


int main() {

    // 704
    // std::vector<int> nums = {-1,0,3,5,9,12};
    // int target = 9; // Answer is 4,
    //int target = 2; // Answer is -1
    // int outIdx = findTargetUsingBinarySearch(nums, target);
    // std::cout << "idx: "<< outIdx << " value: " << nums[outIdx] << std::endl;

    // 367
    int num = 16; // Answer is 1
    // int num = 20; // Answer is 0

    int isSquare = checkIfValidSquareUsingBST(num);
    std::cout << "Value: " << num << " is square: " << (isSquare ? "YES" : "NO") << std::endl;

    return 0;
}
    



