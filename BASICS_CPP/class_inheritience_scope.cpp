#include <iostream>

/**
 * @brief Quick practice of scoped inheritence and dynamic / late-binding or polymorphism
 * 
 */

 class Student {
 
    public:
 
   // student objects will have a name member variable
   std::string name;
   int gpa = 0;
   
   // a simple constructor to set the name member variable
   Student(std::string name) : name(name) {}
   
   // we use the virtual keyword when creating the member function, this will 
   // enable dynamic binding of the print member function when it is called, 
   // we can call the print member function a virtual member function
   virtual void print() { std::cout << name << std::endl; }

   virtual int cgpa() = 0; // pure virtual function

 };





int main() {

    
    return 0;
}
