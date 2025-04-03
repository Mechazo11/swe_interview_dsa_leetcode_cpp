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
    
    https://www.youtube.com/watch?v=pV2kpPD66nE
    Foundational problem on leetcode

    Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
    You may assume all four edges of the grid are all surrounded by water.

    Input:
    11110
    11010
    11000
    00000

    Output: 1

    Input:
    11000
    11000
    00100
    00011

    Output: 3


    Input:
    00000
    00000
    00000
    00001

    Output = 1??


    - Discussion
        - Ask clarification on what is meany by all four edges of the grid are surrounded by water
        - The map is rectangular (BFS does not care)
        - So if there is a chain of 1,1,1,1,0 that makes it a island, so is 11 but if there is discontinuity between congruent 
        - we scan through the 2d map and store possible chains of 1s.
        - in post-process we need to check if any of those chains has a discontinuity in between
        - we also need to use a Hashset to keep track of cells that has been already visited
        - I chose BFS's iterative version using queue and hashsets to keep track of visited node
        - time complexity: O(M*N)
        - space complexity: O(min(N,M))
            - why in worst case the `1` could be the entire row or the entire column or the entire diagonal
        - cases where this algo will fail
            - very large gird may cause stack overflow or number overlofw
            - edge cases, empty map or map with all water / all lands
            - do two diagonals connected together counts as one island

        - Do we assume there is always a land in top-left

    - Solution
        - this is a 2D matrix problem in form of a connected graph
        - for each cell we get a 1, we will put that cell to queue and also in the visited array
        - while time complexity is O(mxn) this is the worst case scenario, in most cases by keeping track of the visited node


*/

// Solve island count problem using Breadth First Search
int findIslandsBFS(std::vector<std::vector<int>> &grid_map){

    /*
        The following pattern is called guard clauses and is very strategic to use early in the code before going into full execution
    */
    // Ask to the intervieiwer what type of edge cases we would consider here
    // cannot be an empty matrix or the size of the matrix cannot exceed given dimensions
    if (grid_map.empty()){
        std::cout << "empty grid map" << std::endl;
        return 0;
    }

    /*
        Optional if time allows
    */
    // Use two for loops to check for all zeros or all 
    bool allZeros = true;
    bool allOnes = true;

    for (const auto& row : grid_map) {
        for (int cell : row) {
            if (cell != 0) allZeros = false;
            if (cell != 1) allOnes = false;
            
            // Early termination
            if (!allZeros && !allOnes) break;
        }
        if (!allZeros && !allOnes) break;
    }

    if (allZeros) {
        std::cout << "All cells are zeros" << std::endl;    
        return 0;
    }
    if (allOnes) {
        std::cout << "All cells are ones" << std::endl;    
        return 0;

    }

    
    // Start by getting the number of rows and columns
    int rows = grid_map.size();
    int cols = grid_map[0].size();
    int numIslands = 0;

    // Initialize the queue
    std::queue<std::pair<int, int>> grid_queue;
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false)); // Literally another grid map of equal dimensions

    // This problem all the cells has to be visited at least once O(mxn)
    for (int r = 0; r < rows; r++){
        // Cycle through the cols of this row
        for (int c = 0; c < cols; c++){

            // Check if the is cell has been visited, if not, put it in BFS queue
            if (!visited[r][c]){
                visited[r][c] = true; // track it in grid map
                
                // Now is this cell a 1 which will allow us to start the BFS
                if (grid_map[r][c] == 1) {
                    grid_queue.push({r,c}); // Push to queue
                    numIslands++; // Only increment here as we will use BFS to look for other ones
                }

                // Start BFS logic
                while(!grid_queue.empty()){
                    auto [r_i, c_i] = grid_queue.front(); // Get the first element in the queue
                    grid_queue.pop(); // Otherwise this element will not be removed from queue
                    
                    // Have to mark this cell also visited
                    visited[r_i][c_i] = true;
                    
                    if (grid_map[r_i][c_i] == 1){
                        // Add this node's four neighbors (only if not visited)
                        if (r_i > 0 && !visited[r_i-1][c_i]) {
                            visited[r_i-1][c_i] = true;  // Mark as visited before adding to queue
                            grid_queue.push({r_i-1, c_i});
                        }
                        if (r_i < rows-1 && !visited[r_i+1][c_i]) {
                            visited[r_i+1][c_i] = true;
                            grid_queue.push({r_i+1, c_i});
                        }
                        if (c_i > 0 && !visited[r_i][c_i-1]) {
                            visited[r_i][c_i-1] = true;
                            grid_queue.push({r_i, c_i-1});
                        }
                        if (c_i < cols-1 && !visited[r_i][c_i+1]) {
                            visited[r_i][c_i+1] = true;
                            grid_queue.push({r_i, c_i+1});
                        }
                    }
                
                }

            } else {
                // No need to do anything
            }
            
        }
    }

    return numIslands;

}

int main() {

    // Answer 1 why?
    std::vector<std::vector<int>> grid_map = {
        {1,1,1,1,0},
        {1,1,0,1,0},
        {1,1,0,0,0},
        {0,0,0,0,0}

    };

    // std::vector<std::vector<int>> grid_map = {
    //     {1, 1, 0, 0, 0},
    //     {1, 1, 0, 0, 0},
    //     {0, 0, 1, 0, 0},
    //     {0, 0, 0, 1, 1}
    // };
    

    // std::vector<std::vector<int>> grid_map = {
    //     {1,1,1,1,1},
    //     {1,1,1,1,1},
    //     {1,1,1,1,1},
    //     {1,1,1,1,1}

    // };

    // std::vector<std::vector<int>> grid_map = {};

    int island_count = findIslandsBFS(grid_map);

    std::cout << "Number of islands: " << island_count << std::endl;


    return 0;
}
    


// ************************************



