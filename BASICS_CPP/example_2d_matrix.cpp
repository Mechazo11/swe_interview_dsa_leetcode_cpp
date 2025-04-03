#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.


//* Place any class, struct definitions here

//* Write your interface (alway)

//* Write out a pseudocode first

int main() {
    
    std::vector<int> my1DArray(5, 23); // Five element 1D array, all initialized to 23

    int row_num = 3;
    int col_num = 3;

    // Each row is a std::vector
    // Inside each row, is a vector of integer of size (col_num)
    std::vector<std::vector<int>> myMat(row_num, std::vector<int>(col_num));

        // Populate myMat with values
        // Best way to cycle through elements of a matrix
        for (int i = 0; i < row_num; ++i) {
            for (int j = 0; j < col_num; ++j) {
                myMat[i][j] = i * col_num + j + 1; // Example: Filling with sequential values
            }
        }
    

    return 0; // Indicates successful program execution
}
