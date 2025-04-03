#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers
#include <cmath> // Math library
#include <unordered_set>

/*
Leetcode: 240
A variant of this problem is 74 which can be solved in O(N * M) time
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom // 

The second property states 

Input = [
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

- This problem is essentially a Binary search performed n times
- If value is found, return true, else false

Test with 74

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true

- Even if my solution is not optimal for both cases, it is much better than brute force method

*/

int isElementIn2DMatrix(const std::vector<std::vector<int>> &matrix, const int &target){

    /*
        Psuedocode
        - Get rows and colm number
        - for each row perform binary search
        - if target found return 1 else go through the rest of the rows
        - return -1 if no solution is found
    */

    // Get row and column numbers of the 2D matrix
    int rows = matrix.size();
    int cols = matrix[0].size(); // Each element of the matrix is a row vector also

    // Cycle through each row
    for (int i = 0; i < rows; i++){
        // Initialize variables for this row
        std::vector<int> thisRow = matrix[i];
        int left = 0;
        int right = thisRow.size() - 1;
        int middle = -1;
        
        // Enough to terminate loop check
        // Why do we need (left <= right)? Without this condition, we will not check the final element at left == right, which is the correct answer
        while (left <= right){
            // Get middle index
            middle = left + (right - left) / 2;
            
            // Are we done
            if (thisRow[middle] == target){
                return 1;
            }
            
            // If mid value < target, move left index to right 
            if (thisRow[middle] < target){
                left = middle + 1; // without +1 may get stuck on a while loop
            } else {
                // target value is less than middle value, push right ptr to right
                right = middle - 1;
            }

        }
        // DEBUG
        std::cout << "Row: " << i << " done" <<std::endl;

    }

    return -1; // Value was not found
}


int main() {

    // std::vector<std::vector<int>> matrix = {
    //     {1,  4,  7, 11, 15},
    //     {2,  5,  8, 12, 19},
    //     {3,  6,  9, 16, 22},
    //     {10, 13, 14, 17, 24},
    //     {18, 21, 23, 26, 30}
    // };

    // From 74, 
    std::vector<std::vector<int>> matrix = {
        {1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    
    int target = 5;
    
    int result = isElementIn2DMatrix(matrix, target);

    std::cout << "Element: " <<target<<" is in matrix? " << (result? "YES":"NO") << std::endl;
    
    return 0;
}
    


// ************************************



