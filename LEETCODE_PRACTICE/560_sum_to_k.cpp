#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers
#include <unordered_map> // To bring in hash tables


/*
Given an integer arrayu and an integer targetr, return incides of two numbers such that they add up to the target integer

In this example since two loops are used since
*/



// //* Write your interface (alway)
// /**
//  * Brute force method O(n^2) complexity
//  */
void getPairIndiciesBruteForce(std::vector<int> &vecIn, int targetVal, int &firstIdx, int &secondIdx) {
    // Forward pass of left pointer
    for (int i = 0; i < vecIn.size(); i++) {
        // Backward pass of right pointer
        for (int j = vecIn.size() - 1; j > i; j--) {
            if ((vecIn.at(i) + vecIn.at(j)) == targetVal) {
                firstIdx = i;
                secondIdx = j;
                return; // Done
            }
        }
    }
    // No pair found
    firstIdx = -1;
    secondIdx = -1;
}

// Example of pass by reference and return by reference
void getPairIndices(std::vector<int> &vecIn, int targetVal, int &firstIdx, int &secondIdx) {
    // Initialize two pointers
    int left = 0;
    int right = vecIn.size() - 1;
    
    // Move pointers toward each other
    for (; left < right; ) {
        int currentSum = vecIn[left] + vecIn[right];
        
        if (currentSum == targetVal) {
            // Found the pair
            firstIdx = left;
            secondIdx = right;
            return; // Thats it we are done
        } else if (currentSum < targetVal) {
            // Sum is too small, increase left pointer
            left++;
        } else {
            // Sum is too large, decrease right pointer
            right--;
        }
    }
    
    // No pair found
    firstIdx = -1;
    secondIdx = -1;
}


void getPairIndiciesHashMap(std::vector<int> &vecIn, int targetVal, int &firstIdx, int &secondIdx){
    // https://www.youtube.com/watch?v=wEpviAgbDtk
    // At best this is also O(n) as at best we have to loop through the whole arrayu once O(n)
    /*
        Pseudocode
        1. Define a hashmap using std::unordered_map
        2. One for loop, idea is second int - target - num.at(i)
        3. BIG idea, we initialize the hashmap as the pointer moves from left to right
        4. Hashmap works in linear run time
    */

    std::unordered_map<int, int> hashTable;
    for (int i = 0; i < vecIn.size(); ++i){
        int second_num = targetVal - vecIn.at(i); 
        if (hashTable.find(second_num)!=hashTable.end()){
            firstIdx = i;
            secondIdx = hashTable.find(second_num)->second;
            return; // Return immediately when pair is found
        } else {
            hashTable[vecIn.at(i)] = i;
        }
    }

    // Only reaches here if no pair was found
    std::cout << "No pair found" << std::endl;
    firstIdx = -1;
    secondIdx = -1;
}

int main() {
    
    std::vector<int> vecIn = {1,5,14,17,22};
    int k = 22;
    int firstIdx = 0;
    int secondIdx = 0;
    int resultSum = 0;

    int firstIdx_h = 0;
    int secondIdx_h = 0;
    int resultSum_h = 0;

    getPairIndices(vecIn, k, firstIdx, secondIdx);
    resultSum = vecIn[firstIdx] + vecIn[secondIdx];

    std::cout << "firstIdx: " << firstIdx << std::endl;
    std::cout << "secondIdx: " << secondIdx << std::endl;
    std::cout << "sum: " << resultSum << "\n" << std::endl;


    // Hashmap solution
    getPairIndiciesHashMap(vecIn, k, firstIdx_h, secondIdx_h);
    resultSum = vecIn[firstIdx_h] + vecIn[secondIdx_h];

    std::cout << "firstIdx_h: " << firstIdx_h << std::endl;
    std::cout << "secondIdx_h: " << secondIdx_h << std::endl;
    std::cout << "sum_h: " << resultSum << std::endl;

    return 0;
}
    


// ************************************



