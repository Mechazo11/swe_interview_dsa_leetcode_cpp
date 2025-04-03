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
347. Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Note: The answer can be returned in any form.
- It is guranteed that the answer is unique

-- Discussion
    - This is a key value problem where we count the frequency of certain numbers being repeated and then return k most repeated numbers
    - Is it HashMap or something more
    - this problem is a clever of doing max heap

*/

std::vector<int> findKMostRepeated(std::vector<int> &nums, int &k){

    /*
        Pseudocode
        - cycle through all the elements and add the frequency of elements found in the hashmap
        - figure out how to sort the keys based on ascending order of the values: max heap
        - I will use the 
    */

    // Initialize the output variable
    std::vector<int> k_max_nums;

    /*
        Guard clause what happens if nums is empty or k is less than 1
    */

    if (nums.empty() || k < 1){
        return k_max_nums; // Empty list
    }

    // If there is only one element in the array, then it is the element with maximum values
    if (nums.size() == 1){
        k_max_nums.push_back(nums[0]);
        return k_max_nums;
    }

    // Initialize the HashMap and count the frequency of unique elements

    std::unordered_map<int, int> value_map;

    for (int i =0; i < nums.size(); i++) {
        // Is this number already added?
        if (value_map.find(nums[i])==value_map.end()){
            // New number
            value_map[nums[i]] = 1;
            
        } else {
            // Number is there, increase the count
            value_map[nums[i]]++;
        }
    }

    // Step 2: Take the frequency column and heapify it
    // Create a max heap (descending order) of frequencies
    std::priority_queue<std::pair<int, int>> pq; // We are pushing in a tuple

    // // EXAMPLE OF min heap
    // std::priority_queue<
    // std::pair<int, int>,                // value type
    // std::vector<std::pair<int, int>>,   // container type (missing in your code)
    // std::greater<std::pair<int, int>>   // comparator
    // > pq;


    // Example of accessing hashmap using std::pair
    // That it, the algorithm runs in O(log n) complexity which is not bad
    for (auto & [num, freq] : value_map){
        // This pair is a std::pair object
        pq.push({freq, num}); 
        // The ordering is very important, remember the "keys" are elemetns and frequeuncies are the ones with which we want to make the heap
    }
    // Step 3: Select the first K elements of the max heap

    for (int i = 0; i < k && !pq.empty(); i++) {
        auto [freq, num] = pq.top(); // Same as heap top and then pop
        pq.pop(); // Remove it from the queue
        k_max_nums.push_back(num); // Get the current maximum
    }

    // Step 4: We have obtainded the maximum frequeunces, how query the hash
    
    return k_max_nums;

}

int main() {

    std::vector<int> nums = {1,1,1,2,2,3};
    // std::vector<int> nums = {1};
    int k = 2;

    std::vector<int> result = findKMostRepeated(nums, k);

    std::cout << "Max elements: [" ;
    for (auto ii : result){
        std::cout << ii << " ";
    }
    std::cout << "]" << std::endl;
    
    return 0;
}
    


// ************************************



