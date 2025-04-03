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


1197. Minimum Knight Moves

V.V.I: This is definitely a Breadth First Search + 2D matrix traversal

In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, 
then one square in an orthogonal direction

- https://www.youtube.com/watch?v=OgPUNRLSp_c
*/

/**
No time and doing it now would make you very nervous. Just focus on the pseudocode and pray for the best


- Logic to select the row colum position the knights move allows us to add the neighbors to select
- This problem does not need to keep track of visited nodes, all we just need to do is keep exploring the until we reach the target square
- We can speed up the computation by enforcing which quadrent should the exploration nodes be added too

-- Clarificaiton question
    - is it guranteed to there be always a valid answer?
    - what happens if the algorithm cannot find value beyond 300 x 300

*/

int main() {
    // Define board dimensions (standard 8x8 chess board)
    
    int x = 3;
    int y = 4;
    
    const int rows = x;
    const int cols = y;

    // All possible knight moves from current position (r, c)
    std::vector<std::pair<int, int>> knightMoves = {
        {-2, -1}, {-2, 1},  // Two up, one left/right
        {-1, -2}, {-1, 2},  // One up, two left/right
        {1, -2},  {1, 2},   // One down, two left/right
        {2, -1},  {2, 1}    // Two down, one left/right
    };

    std::queue<std::pair<int, int>> cell_queue;

    // Starting position
    int r = 4;
    int c = 0;
    
    std::cout << "Knight at position (" << r << ", " << c << ")\n";
    std::cout << "Valid moves:\n";

    // To use in a BFS or similar algorithm:
    for (const auto& move : knightMoves) {
        // int newRow = r + move.first;
        // int newCol = c + move.second;
        int newRow = r + move.first;
        int newCol = c + move.second;

        std::cout << "  → (" << newRow << ", " << newCol << ")\n";

        // Here if we know which quadrent the target is falling, we can 

        // Check if the new position is within bounds
        if ((newRow != 0 && newRow <= rows) && (newCol != 0 && newCol <= cols)) {
            // Valid move, add to queue
            cell_queue.push({newRow, newCol});
            std::cout << " Pushed → (" << newRow << ", " << newCol << ")\n";
        }
        
    }
    
    std::cout << "\nTotal valid moves: " << cell_queue.size() << std::endl;
    
    // Process the queue (example of how you might use it in BFS)
    std::cout << "\nProcessing queue in BFS order:\n";
    while (!cell_queue.empty()) {
        auto [currentRow, currentCol] = cell_queue.front();
        cell_queue.pop();
        std::cout << "Processing: (" << currentRow << ", " << currentCol << ")\n";
        
        // In a real BFS, you would add neighbors here
        // For example: for (const auto& move : knightMoves) { ... }
    }
    
    return 0;
}

    


// ************************************



