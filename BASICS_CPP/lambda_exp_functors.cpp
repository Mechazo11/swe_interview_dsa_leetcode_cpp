#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.


//* Place any class, struct definitions here

//* Write your interface (alway)

// Here [](int n){std::cout << n << ",";} is the lambda function

// [captures](params){body} // Inline function

struct printFunctor{
    
    // Member variables
    int lastResult = -1;
    
    // operator() method must be implemented
    // It doesn't have to be an 
    void operator()(int n){
        lastResult = n;
        std::cout << n << ",";
    }
};

int func(int n){
    std::cout << n << ",";
    return n;
}


int main() {
    
    std::vector<int> v{1,3,2,5,9};
    std::vector<int> v2;

    std::for_each(v.begin(), 
                  v.end(), 
                  func);
    
    std::cout << std::endl;

    std::for_each(v.begin(), 
                  v.end(), 
                  printFunctor());
    

    std::cout << std::endl;
    
    return 0; // Indicates successful program execution
}
