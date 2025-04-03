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
#include <utility> // std::pair
#include <queue> // std::queue

/*

Implement the missing code for CarFactory, BikeFactory, and TruckFactory classes.
Each factory should properly implement the createVehicle() method to return the appropriate vehicle type.
Complete the main() function to demonstrate the factory pattern by creating and using each factory type.

- https://www.youtube.com/watch?v=phTXrJqRgnI

*/

// Builder patterns are only useful when the class is very complex. I think for Waymo's interface problem this would be an ideal pattern to look into.

// Product

// Base class
class Pizza {
public:
    std::string dough;
    std::string sauce;
    std::string topping;

    void show() {
        std::cout << "Pizza with " << dough << ", " << sauce << ", " << topping << "\n";
    }
};
    
// Builder
/*
    Builders may not inherit the base class since the idea is to compose base classes which may be multiple not to become
    the Pizza itself. i.e a human is the builder using legeo blocks but is not itself a lego
*/

// This is the base pizza builder from which other type of related builders may inherit
class PizzaBuilder {
protected:
    Pizza pizza;
public:
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    Pizza getPizza() { return pizza; }
};

// Concrete Builder
class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    void buildDough() override { pizza.dough = "cross"; }
    void buildSauce() override { pizza.sauce = "mild"; }
    void buildTopping() override { pizza.topping = "ham+pineapple"; }
};

class CheesePizzaBuilder : public PizzaBuilder {
    public:
        void buildDough() override { pizza.dough = "hand-made"; }
        void buildSauce() override { pizza.sauce = "roman"; }
        void buildTopping() override { pizza.topping = "mushroom+tomtato"; }
    };

// Director
class Cook {
public:
    void makePizza(PizzaBuilder& builder) {
        builder.buildDough();
        builder.buildSauce();
        builder.buildTopping();
    }
};

int main(){
    Cook cook;
    HawaiianPizzaBuilder builder;
    CheesePizzaBuilder cbuilder;
    cook.makePizza(cbuilder);
    Pizza pizza = cbuilder.getPizza();
    pizza.show();
    return 0;
}
    

