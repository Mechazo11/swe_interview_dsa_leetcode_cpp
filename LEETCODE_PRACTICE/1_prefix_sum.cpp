#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers

/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
Given nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2) -> 1

These problems would need us to scan the 1D array using two pointers i and j
*/

/*
Assumtpions
the 1D array is not mutable
solution uses the prefix sum method
*/

/**
This is applicable to any Preifx sum problem
*/

//* Write your interface (alway)

float sumRange(int i, int j, std::vector<int> &vecIn){
    std::vector<int> preFixSum(vecIn.size()+1, 0);
    
    // Instead of two pointers, we are progressing 
    for (int k = 0; k < vecIn.size(); k++){
        preFixSum[k+1] = preFixSum[k] + vecIn[k];
        std::cout << preFixSum[k+1];
    }
    
    return preFixSum[j+1] - preFixSum[i];
}


int main() {
    
    // std::vector<int> vecIn = {-2, 0, 3, -5, 2, -1};
    std::vector<int> vecIn = {0,1,2,3};
    float resultOut = sumRange(0,3,vecIn);
    std::cout << "result: " << resultOut << std::endl;

    return 0;
}
    


// ************************************


// #include <iostream> // Provide input output stream (essentially )
// #include <vector> // implements dynamic array
// #include <string> // string handling functionality
// #include <algorithm> // various algorithms like sort(), find() etc.
// #include <memory> // Smart pointers

// /*

// */

// //* Write your interface (alway)




// int main() {
    
    

//     return 0;
// }
    
