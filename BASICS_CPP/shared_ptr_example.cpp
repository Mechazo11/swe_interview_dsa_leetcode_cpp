#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers

//* Place any class, struct definitions here

//* Write your interface (alway)

//* Write out a pseudocode first

class BaseClass {
    public:
        
        BaseClass() = default;

        virtual void speak() {
            std::cout << "I am base." << std::endl;
        }

        // Return type is not required for desctructors
        virtual ~BaseClass() {
            std::cout << "Base destroyed." << std::endl;
        }
};

class DerviedClass : public BaseClass {
    public:
        void speak () override {
            std::cout << "I am derived." << std::endl;
        }

        DerviedClass() = default;

        ~DerviedClass() override {
            std::cout << "Derived destroyed" << std::endl;
        }

};


void custom_deleter(BaseClass* ptr){
    std::cout << "Custom deleter called." << std::endl;
    delete ptr;
}

int main() {
    
    // Create an instance of the BaseClass
    // Uses built-in deleter
    std::shared_ptr<BaseClass> sp1 = std::make_shared<BaseClass>(); // Class constructor arguments would just go in there
    sp1->speak();
    
    std::shared_ptr<BaseClass> sp2(new DerviedClass, custom_deleter);
    sp2->speak();
    
    std::shared_ptr<BaseClass> sp3 = sp1; // Create a pointer from another pointer
    sp3->speak();

    // decouple from previous object's address, decrement object - pointer count and discard object as requried
    sp3.reset(new DerviedClass);
    sp3->speak();

    return 0; // Indicates successful program execution
}
