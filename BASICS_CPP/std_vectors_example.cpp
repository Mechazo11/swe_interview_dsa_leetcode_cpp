#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.


//* Place any class, struct definitions here

//* Write your interface (alway)

//* Write out a pseudocode first

int main() {
    
    std::vector<std::string> myString{"Heloo", "there!"};

    std::cout << "capacity: " << myString.capacity() << std::endl;

    // Modern C++ range based for loop
    for (const auto &str : myString){
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::vector<int> myVector{2,2,10,10,5,3};

    // Use standard for loop with iterator
    // Time complexity O(n**2) becuase there is a O(n) loop to group through all
    // elements and then there is a O(n) operator to shift subsequent elements

    for (auto it = myVector.begin(); it != myVector.end();) {
        if (*it % 2 == 0) {
            // Erase returns the next valid iterator
            it = myVector.erase(it);
        } else {
            ++it;
        }
    }
    
    // Print result
    for (const auto& num : myVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0; // Indicates successful program execution
}
