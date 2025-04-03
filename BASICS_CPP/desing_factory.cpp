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

    // Abstract base class for vehicles
    // Why, all functions are purely abstract
    class Vehicle {
    public:
        virtual ~Vehicle() = default;
        virtual std::string getType() const = 0;
    };
    
    // Concrete vehicle classes
    class Car : public Vehicle {
    public:
        std::string getType() const override { 
            return "Car";
        }
    };
    
    class Bike : public Vehicle {
    public:
        std::string getType() const override {
            return "Bike";
        }
    };
    
    class Truck : public Vehicle {
    public:
        std::string getType() const override {
            return "Truck";
        }
    };
    
    // Abstract factory class
    class VehicleFactory {
    public:
        virtual ~VehicleFactory() = default;
        virtual std::unique_ptr<Vehicle> createVehicle() const = 0;
    };
    
    class CarFactory : public VehicleFactory {
        // Write your code here
        public:
            std::unique_ptr<Vehicle> createVehicle() const override {
                return std::make_unique<Car>();
            }
    };
    
    class BikeFactory : public VehicleFactory {
        public:
            std::unique_ptr<Vehicle> createVehicle() const override {
                return std::make_unique<Bike>();
            }
    };
    
    class TruckFactory : public VehicleFactory {
        // Write your code here
        public:
            std::unique_ptr<Vehicle> createVehicle() const override {
                return std::make_unique<Truck>();
            }
    };
    
    // Test function
    void testFactory(const std::unique_ptr<VehicleFactory> &factory) {
        std::unique_ptr<Vehicle> vehicle = factory->createVehicle();
        std::cout << "Created vehicle of type: " << vehicle->getType() << std::endl;
    }
    
    int main() {
        // Test your implementation here
        
        std::unique_ptr<VehicleFactory> carFactory = std::make_unique<CarFactory>();
        std::unique_ptr<VehicleFactory> truckFactory = std::make_unique<TruckFactory>();
        // CarFactory* carFactory = new CarFactory(); 

        testFactory(carFactory);
        testFactory(truckFactory);

        return 0;
    }
    


// ************************************



