#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.


int compareTwoIntegers (int first_elem, int second_elem){
    
    if (first_elem < second_elem){
        return 1; // Return 1 if first element is smaller
    }
    else if (first_elem == second_elem) 
    {
        return 0; // elements are equal
    }
    else {
        return -1; // First element is larger
    }
}


void BubbleSort1D(std::vector<int> &A, int (*compareTwoIntegersPtr)(int, int)){

    int temp; // Work variable
    // Outer loop
    for (int i = 0; i < A.size(); i++){

        for (int j = 0; j < A.size() - 1; j++ ){
            if (compareTwoIntegersPtr(A.at(j), A.at(j+1)) > 0)
            {
                temp = A.at(j);
                A.at(j) = A.at(j+1);
                A.at(j+1) = temp;
            }
        }
    }
}

int main() {
    // Create a simple vector with unsorted integers
    std::vector<int> numbers = {3,2,1,5,6,4};
    
    // Print the original array
    std::cout << "Original array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Sort using the function pointer
    // Observe carefully, we are directly passing the function not calling it.
    BubbleSort1D(numbers, compareTwoIntegers);
    
    // Print the sorted array
    std::cout << "Sorted array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0; // Indicates successful program execution
}