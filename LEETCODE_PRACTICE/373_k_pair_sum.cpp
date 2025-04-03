#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers
#include <cmath> // Math library
#include <unordered_map> // Hasmaps
#include <unordered_set> // Hashsets
#include <limits> // inf limits
#include <numeric> // std::atoi
#include <utility> // std::pair
#include <queue> // std::queue

/*

373. Find K Pairs with Smallest Sums

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence:
             [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

-- Discussion
    - A brute force approach would be at least O(n^2)
    - The problem is we have to get all unique combinations of 3x3 = 9 pairs before processing them
    - it is stated that the both the elements are sorted, so it is guranteed that the first two 
    - https://www.youtube.com/watch?v=Youk8DDnLU8
*/

std::vector<std::vector<int>> findSmallestSums(std::vector<int> &nums1, std::vector<int> &nums2, int &k){

    std::vector<std::vector<int>> k_sums;

    // k is zero or some negative number
    if (k<1){
        return k_sums;
    }

    /*
        Guard clause what happens if there is no pairwise set
    */

    /*
        Pseudocode
        - Lets create a hashmap so int, std::pair<int, int> one is the sum and the other are the indicies of the visited array
    
    */

    // Start the hashmap to track indicies and sum
    std::unordered_map<int, std::pair<int, int>> sum_map;

    // To avoid double counting we kepe track of the used indicies in hashset
    // Each indicies pair can be used only once
    std::unordered_map<int, std::pair<int, int>> visited; // count, pairs
    
    // Both arrays are identical in shape so that pairwise sums can be made
    
    // Start the two inner loops
    for (int i = 0; i < nums1.size(); i++){

        // RESUME FROM HERE


    }

    return k_sums;

}

int main() {
    
    std::vector<int> nums1 = {1,7,11};
    std::vector<int> nums2 = {2,4,6};
    int k = 3;

    std::vector<std::vector<int>> k_sums = findSmallestSums(nums1, nums2, k);

    return 0;
}
    


// ************************************



