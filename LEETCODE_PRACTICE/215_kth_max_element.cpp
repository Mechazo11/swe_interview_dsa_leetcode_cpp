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
#include <utility> // std::pair, std::swap
#include <queue> // std::queue
#include <set>

/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Input: [3,2,1,5,6,4] and k = 2
Output: 5

- Discusison
    - This is a sorting problem which we will do using QuickSort a divide and conqure strategy

*/

int kthLargestElement(std::vector<int> &inputArray, int &k){

    // K appears to mean 0-th index this needs to be clarified

    std::sort(inputArray.begin(), inputArray.end());
    std::reverse(inputArray.begin(), inputArray.end());
    

    std::set<int> sortedDistinct;

    for (auto i : inputArray){
        sortedDistinct.insert(i);
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Find the kth element
    auto it = sortedDistinct.begin();
    std::advance(it, k - 1); // Move to the (k-1)th position (0-indexed)
    
    return *it;
    
}

int main() {

    std::vector<int> inputArray = {3,2,3,1,2,4,5,5,6}; // Answer is 4
    int k = 4;

    int result = kthLargestElement(inputArray, k);

    std::cout << k << " largest element: " << result << std::endl;

    return 0;
}
    


// ************************************



