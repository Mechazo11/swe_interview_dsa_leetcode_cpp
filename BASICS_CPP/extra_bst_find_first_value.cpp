#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers
#include <cmath> // Math library
#include <unordered_map> // HashMaps
#include <numeric> // std::iota

/*
Find first value >= x


- All the arrays are not in sequence.
- Binary search algorithm
- We start with -1 and as we progressively look into the array, we incrementally update with a possible answer
- until the while loop is terminated
- nums[midIdx] >= target condition has an odd behavior. If the sequence contains the same number as target then the final answer
is the target itself

*/

int nextIdxUsingBST(const std::vector<int> &nums, const int &target){
    int currentBestValue = 0; // To store overall best value
    int leftIdx = 0;
    int rightIdx = nums.size() - 1;
    int midIdx = 0;

    while(leftIdx <= rightIdx){
        midIdx = leftIdx + (rightIdx - leftIdx) / 2;
    
        if (nums[midIdx] > target) {
            currentBestValue = nums[midIdx]; // This is the new estimate
            rightIdx = midIdx - 1; // right pointer should be the next element right of middle value else we fall into infinite loop
        }
        else {
            leftIdx = midIdx + 1; // left pointer should be the next element to right of middle value, else we fall into infinite loop 
        }
    }

    return currentBestValue; // Returns either -1 or the first higher number

}

int main() {

    std::vector<int> nums = {2,3,4,5,6,8,10,12};
    int target = 10;

    int result = nextIdxUsingBST(nums, target);

    std::cout << "Next best number in sequence: " << result << std::endl;

    return 0;
}
    


// ************************************



