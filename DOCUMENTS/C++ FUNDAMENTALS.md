# C++ Fundamentals

### OOP:

`Class`: A `blueprint` written by a programmer that defines the `attributes` of an `object`.

* `Object`: Each object is an `instance` of a `class` in computer's memory. Creating an object from a class is thus called `instantiation`.

* `Encanpsulation`: Bundling data and methods that operate on that data within a single unit (class), and restricting access to some of the object's components.

* `Interface`: Essentially Python's `abstractclass` but with the following differences

    * C++ uses virtual keyword and = 0 syntax for pure virtual functions
    * C++ has no explicit interface keyword
    * C++ requires explicit override keyword (in modern C++)
    * C++ needs virtual destructors for proper cleanup

* `Inheritence`: Derive variables and methods from other classes in an `heirarchical` manner.

* `Polymorphism`: The ability to present the same interface for different underlying forms or data types, allowing objects of different classes to be treated as objects of a common superclass.
 
    - Compile time i.e. `static-binding`. Overloading `function`, `operators` and `templated classes` are some common examples
    - Run-time i.e. `late binding` that deinfes the actual class/object/function implementation is unknown until the program executes. Common example include derived classes from a base class, implementing pure virtual functions and so on.

* `Abstraction`: Hide complexity / Information hiding. Only certain API are exposed for other objects / programmers to use. You don't need to understand in details what is going on in these classes, just know how to use the API and what are the input and outputs and edge cases if known

* The difference between `early-binding` / `static` to `late-binding`/`dynamic` is very simple. Ask yourself, "Do we have the information about the element's attributes before `runtime` or is it determined during `runtime`?"

    - An example is sensor data process which can only work during `run-time`. So is `robotics-related` projects.


## C++ Compilation Speed Techniques

* `Precompiled headers (PCH)`: Compile stable headers once
* `Forward declarations`: Reduce header dependencies
* `Include guards/pragma once`: Prevent multiple includes
* `Minimize header includes`: Only include what's needed
* `Unity builds`: Combine source files into fewer translation units
* `Modules (C++20)`: Modern alternative to headers
* `Parallel compilation`: Use -j flag with build systems
* `Incremental builds`: Only recompile changed files
* `Optimize include hierarchies`: Avoid deep nesting
* `External dependency management`: Use package managers
* Using `contexpr` expression to speed up compile-time compliation and is related to `static-optimization`. However using `contexpr` is very tricky.

For large codebases, consider distributed build systems like DistCC, compiler caches like ccache, or build systems like Ninja.


### Build and Tools: 

* Builds, Linters, Tests, Static Code Analysis, Format, CI/CD, Version Control (git), Debugger 

* Compiler performs four distinct operation to build a code: `Pre-process`, `Compile`, `Assembly`, `Link`.

* `Linkers` in particular adds `.so` files of `libraries` with `.o` files of this codebase.

* **TODO** finish reviewing this video https://www.youtube.com/watch?v=OLl6TSmhIIs&list=PLgnQpQtFTOGRM59sr3nSL8BmeMZR9GCIA&index=17

### Memory management:

- int: 4 bytes
- char: 1 bytes
- float: 4 bytes

* Operator `&` returns address of a memory of an element.

* Using deference operator `->`, we can access an already created object.

* ```obj_ptr->Func()``` <-> ```(*obj_ptr).Func()``` i.e. ```(*obj_ptr)``` is called `deferencing` and will give direct access to the object created apriori. Hence very easy to goof it up

* `stack-frame`: A portion of the stack that is allocated to let main() run.

* `new`: Keyword to allocate memory from `heap`, a larger chunk of memory that does not have automatic garbage collection and is larger in size than `stack`. Elements (objects, pointers, variables, arrays) must be then manually deleted using `delete` keyword. These elements are those which requires persistence i.e. must survive unlike stack that are automatically deleted as soon as element goes out of scope. Problem is we are in charge of freeing the memory, it is not automatically freed.

### Pointers

- Pointers are `type defined` variables that just stores address of certain objects/variables
- When we put `(*)` infront of a poitner, it gives `VALUE` of that location or the object in that location. This is called `DEREFERENCING`

- An `address of a function` is also called its `entry point` of a function

### Vectors

* std::vector
- `heap` allocated as this vector can grown in size much bigger than 8Mb
- `.at()`: access specified element with bounds checking
- `.front()`: First element
- `.back()`: Last element
- `.resereve(int)`: Allocated memory for elements if size is known
- `.clear()`: Reset the container
- Iterators are pointers to starting and ending positions of the vector as shown ```myVector.begin(), myVector.end()```
- ```.erase()``` pops an element 


## Conditionals and Swtich

* An anatomy example of switch

```c++
switch (expression)
    {
    case constant expression:
        /* code */
        break;
    
    default:
        break;
    }
```


### Templates: 

* Most importantly, for writing `generic` functions

* An example
```c++
// Basic function template
template <typename T>
T max(T a, T b) {
   return (a > b) ? a : b; // ? : is a  compact form of if-else. If true, sets a else sets b
}

// Usage
int main() {
   int i = max<int>(10, 5);        // i = 10
   double d = max<double>(3.5, 7.2); // d = 7.2
   
   // Type deduction (C++14+)
   auto s = max("hello", "world");  // s = "world"
   
   return 0;
}
```

* `template` is the keyword and a `function template` defines a `family` of functions.

* `template` lives in the `static` world.

* For us roboticists, `templates` makes sense only for writing debugging/utility tools or generic `dataloaders` i.e. not super important

## Unit Testing and associated frameworks

* [Phil Nash](https://www.youtube.com/watch?v=Ob5_XZrFQH0): Lecture on use of Catch2


## Misc Defintions

* `factory function`: A factory function is a function that creates and returns objects of a class or related classes, abstracting away the direct use of constructors.

* In the example below, ```Product* createProduct(std::string type)``` is a factory function
```c++
#include <memory>

class Product {
public:
    virtual void operation() = 0;
};

class ConcreteProduct : public Product {
public:
    void operation() override { /* implementation */ }
};

// Factory function
std::unique_ptr<Product> createProduct(std::string type) {
    if (type == "concrete")
        return new ConcreteProduct();
    // Can return other derived types
    return nullptr;
}
```

* For empty structs, at least `1` byte of space is reserved to give the struct a distinct memory address.

* The core difference between `classes` and `structure` 
    - `classes` are by default private. 
    - `structure` are by default allocated to `stack` and is thus in certain, scenarios where `immutable data structure` is required, is more performant than `classes`.
    - `structs` are really there to make `C` codes compliant to `C++`

* `Call by reference` creates no new objects, it is simply a reference to an exsisting object in memory. Whereas call by value 
or pass by value creates a new copy of the object


## Lambda functions in C++

* Added in Modern website
    - Constructs a closure: An unnamed object capable of capturing variables in scope.
* They are useful for
    - Creating quick, anonymous functions inline where they're needed
    - Capturing local variables to use within functions
    - Simplifying code that needs function objects (e.g., STL algorithms)
    - Implementing callbacks without separate function declarations
    - Parallel programming with concurrency librarie

## Functors / Fuction objects in C++

- Structs or objects that acts as function operators in C++.
- i.e. named `Function Objects` i.e. Lambda expressions 
- Must have a `operator()` but note that this is not a `virtual` function that has been `overridden`, it is simply `syntax` for functors.
- Why does fuctor matter than having pure functions?
    * Objects / structurs have member variables
    * It remembers a `state`.

## OOP in C++

* `shared_ptr` like smart pointers are `templated classes`
* ```std::shared_ptr<ClassName> classObject  = std::make_shared<ClassName>();``` creates `classObject` on the `heap`

* ```Friend function```: 

## <algorithms library>

- `std::for_each`: std::for_each applies a specified function object to each element in a range (from begin to end iterator), without modifying the container structure itself, and returns the final state of that function object. Requires a **functor**

## Time complexity

* https://www.youtube.com/watch?v=BgLTDT03QtU

* Big (O): A way to measure execution time as input size (n) grows.



