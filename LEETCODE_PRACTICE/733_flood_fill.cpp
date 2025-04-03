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
#include <queue> // std::queue

/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, 
"flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels 
connected 4-directionally to the starting pixel of the same color as the starting pixel, 
plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), 
and so on. Replace the color of all of the aforementioned pixels with the newColor. 


image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation:
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.

https://www.youtube.com/watch?v=xlVX7dXLS64&t=191s [very intuitive explanation]


- Discussion
    - each pixel or graph can take a value between 0 - 65535
    - connected pixels share the same value and have a path between them by moving either left, right, up and down
    - as it says connected pixels, this immediately signals it is a graph problem and solvable by BFS
    - These problems I need to ask the interviewer is the time complexity of setting up the 2d matrix going to be counted as a penalty
    - to the actual problem solver since these algorithms does not 
    - what is the fastest way to go from 2d matrix to graph and back which data structure?

- Solution steps
    - setup the input, the matrix map, sr, sc, newColor
    - pass them to floodFill() interface

    - Setup a queue and put first starting location in the queue
    - use a hashset to keep track of `visited` location. I have to see how to do this with std::vector and not invoke array
    - while queue is not empty
        - get row, col by popping queue
        - add it to the visited set
        - transform the pixel from old value to new value
        - cycle through all the neighbors
        - if that [row, col] is not found in visited
            - add it to the `queue`
    - when queue is done, return the transformed image.
    - claude just showed there is no need to creating a custom Node class???

*/

// Solve the flood fill problem using Breadth First Search
void floodFillWithBFS(int &sr, int &sc, int &newColor, std::vector<std::vector<int>> &image){

    /*
        The following pattern is called guard clauses and is very strategic to use early in the code before going into full execution
    */
    // Ask to the intervieiwer what type of edge cases we would consider here
    // cannot be an empty matrix or the size of the matrix cannot exceed given dimensions
    if (image.empty() || image.size() > 50 || image[0].size() > 50){
        std::cout << "image emtpy or out of range" << std::endl;
        return;
    }
    // If there is no change in color
    int oldColor = image[sr][sc];
    if (oldColor == newColor){
        return;
    }

    // Handle valid starting position
    if (sr >= 0 && sr < image.size()){
        // okay
    } else {
        std::cout << "sr out of range" << std::endl;
        return;
    }

    if (sc >= 0 && sc < image[0].size()){
        // okay
    } else {
        std::cout << "sc out of range" << std::endl;
        return;
    }

    // Start by getting rows and columns of image
    int rows = image.size();
    int cols = image[0].size();

    // Setup queue and push first element
    std::queue<std::pair<int, int>> cell_queue;

    // Push the root / first element into the queue
    cell_queue.push({sr, sc}); // Observe the 2nd bracket

    // Main BFS loop runs here iteratively using queue
    while (!cell_queue.empty()) {
        auto [r, c] = cell_queue.front(); // automatically retrives the two elements
        cell_queue.pop();
        
        // Here the logic will change depending on what problem we are dealing with.
        if (image[r][c] == oldColor) {
            image[r][c] = newColor;
            
            // Add 4 adjacent cells
            if (r > 0) cell_queue.push({r-1, c}); // If r>0, we are in the middle to last row so element in TOP exsists
            if (r < rows-1) cell_queue.push({r+1, c}); // r < rows - 1, its in top to 2nd last row, so BOTTOM exsists
            if (c > 0) cell_queue.push({r, c-1}); // If c > 1, its in 2nd col to last column so LEFT exsists
            if (c < cols-1) cell_queue.push({r, c+1}); // if c < cols - 1, so its from 1st to 2nd last col, so RIGHT exsists 
        }
    }
    // Thats it, the queue will keep iteratively updating until we are done
    // No need to return as update is inplace

}

int main() {

    
    // Setup the problem
    int sr = 1;
    int sc = 1;
    int newColor = 2;

    std::vector<std::vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    
    floodFillWithBFS(sr, sr, newColor, image); // Image will be overwritten in place

    std::cout << "Flood filled image:" << std::endl;
    for (int i = 0; i < image.size(); i++) {
        std::cout << "row " << i << ": ";
        for (int val : image[i]) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}
    


// ************************************



