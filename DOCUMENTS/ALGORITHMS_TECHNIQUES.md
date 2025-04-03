# Algorithms and Techniques

- *Sorting*
    - `std::sort()`: Uses `O(n logn)` introsort a hybrid technique
    - `std::sort()` by default is ascending order
    - Uses:
        - min/max kth elements
    
    - QuickSort:
        - Recursive algotihm
        - Items to left of `pivot` are smaller
        - Items to right of `pivot` are larger
        - Choose a best pivot using **TODO**
        - Move pivot at the end of the array
        - Recursively do the following 
            - Find `itemFromLeft` > `pivot`
            - Find `itemFromRight` < `pivot`
            - Swap items from left to items from right
            - If `itemFromLeft` has greater index from `itemFromRight` we are done
        - Swap `itemFromLeft` with `pivot`
        - Recursively perform the operation with larger partition
        
    - Topological Sort:
        - Based on `depth first search` where nodes are ordered such that they obey dependencies i.e. if V is dependent on U, U must be processed
        first before going to V. 

- *Prefix Sum* is a special case of this problem. Only required when we need to find sum of a `subarray` or `contiguous subarray`
    
    - *Preprocessing*: Build prefix sum array where `prefix[i]` contains sum of all elements from `nums[0]` to `nums[i-1]`
    - `prefix[0] = 0`
    - `prefix[i+1] = prefix[i] + nums[i]` for i ≥ 1

    - *Range Sum Query*: Calculate sum of elements from index i to j
    - `sum[i,j] = prefix[j+1] - prefix[i]`

    - *Time Complexity*:
    - Preprocessing: `O(n)` to build the prefix array
    - Query: `O(1)` per range sum query

    - *Space Complexity*: 
    - `O(n)` to store the prefix sum array

- *Two Pointer Method*
    - Time Complexity: `O(n)`: Need to go through the array/string/list at least `once`
    - Space complexity: `O(1)`: Why we are only using two pointers to access variables alread in memory

    - Use cases:
        - Prefix sum
        - Sliding window problems (with Hashmaps or Hashsets)
        - Three sum problems [O(n^2)]
        - For finding target sum, the array needs to be sorted

- *Binary Search*
    - Array must be **sorted** or at least **rotated** with two **sorted** halves
    - Time Complexity: `O(log_2 n) == O(log n)`, Space complexity is `O(n)`
    
    - Use cases:
        - SORTED LIST, find something
        - Min max of a sorted array
        - 2D matrix traversal where rows are sorted, columns are ascending to descending sorted or has other special structure
    
    - How to Implement?
        - **TODO**

- *Depth First Search*
    - Tree must be **Binary**, for Grapsh **??**
    - Basic idea: Go as deep as possible to `leaf` nodes then `backtrack` to upper levels until and repeat the process
    - DFS processe the furthest leaf first before back trakcing. Hence resutls must be **revesred** using ```std::reverse(result.begin(), result.end());```
    - Uses `Stack` data structure
    - Time Complexity: `O(V + E)` where `V` total vertices and `E` is total edges. Space complexity **TODO**
    - **VVI** I have opted to only learn `recursive` which requires a helper function `dfs` inside the main interface
    - Things required 
        - We need a tree passed as `std::vector<std::shared_ptr<Node>>`
        - We need a variable to keep track of current track
        - Back tracking automatically happens via recursion
        - Only call the function once in the `interface` class.
        
    - Uses
        - Path to leafs, longest path problems
        - Combined with Hashmaps can solve
            - **Topological Sort**
            - **Cycle Detection**
    
    - How to use
        - Binary Trees
            - **TODO**
        - Graphs
            - No left and right pointers instead we will need ```std::vector<int> neighbors```

- *Breadth-First Search (BFS)*
    - Used to search through **TREES** and **GRAPHS**
    - Tree must be **Binary**, for Graphs can be **DIRECTED** or **2D MATRIX**
    - Basic idea: Look at one node every level, queue its neighbors and process those neighbors
    - Then visit each **neighbor** and mark it as visited. Then add all of its `neighbours` in the neighbors queue
    - Time Complexity: `O(V + E)` where `V` total vertices and `E` is total edges
    
    - Uses:
        - 2D matrix problems i.e.
            - Change pixel levels
            - Island counting
            - Rotting oranges
        - Graph problems
            - Finding order level
            - Shortest-path
    - Time Complexity: `O(V+E)`
    
    - To solve Graph problems
        - Create a Node class
            - int data;
            - std::vector<int> neighbors
            - requires std::queue<std::shared_ptr<Node>>
            - returns level order, paths etc.
            - to keep of paths, hashsets must be used
            - when path needs to be reconstructed, tracking the parent of the child nodes is a quick and easy to do so.
            - this requires a dictionary i.e. unordered_map / hashmap of two strings [see the word ladder problem]
    
    - To solve binary tree problems
        - Create Node with val, left and right pointers
        - keep track of visited nodes using Hashsets i.e. `std::unordered_set<int> visited`
    
    - To solve 2D matrix problems
        - **STOP AND CAREFULLY THINK**, if the 2D matrix is in vector in vector that has to replace or update cells, then they can be done without any `Node`. See problem `200` and `733`
    
    - How to use [common idea for both trees and graphs]
        - Binary Trees
            - Needs `Node` class
        - For 2D matrix
            - start by getting rows and col count of matrix
            - initialize a queue and push the first element / root
            - If cell visit problem then often time it is easier to use another 2D matrix of bolleans
            - while (!q.empty())
                - pop the first element fropm queue
                - perform logic / operation on current cell 
                - add the 4 adjacent cells to the queue using
                ```c++
                if (r > 0) cell_queue.push({r-1, c}); // If r>0, we are in the middle to last row so element in TOP exsists
                if (r < rows-1) cell_queue.push({r+1, c}); // r < rows - 1, its in top to 2nd last row, so BOTTOM exsists
                if (c > 0) cell_queue.push({r, c-1}); // If c > 1, its in 2nd col to last column so LEFT exsists
                if (c < cols-1) cell_queue.push({r, c+1}); // if c < cols - 1, so its from 1st to 2nd last col, so RIGHT exsists 
                ```
            - when while loop terminates, return result

- *Floyd's Fast and Slow Pointer*
    - Heavily useful for 1D singly linkedlist maniupulation for reversal and reordering
    - Time complexity: `O(n)` and `O(1)` space complexity
    - `slow->slow->next` advance slow pointer by 1 node
    - `fast->fast->next->next` advance fast pointer by 2 nodes 
    - needs at least a `head` ptr and `prev` pointer

- *Min/Max Heap*
    - Also called the heapify operation
    - `O(n)` to create, `O(log n)` for insertion, deletion.
    - The following illustrates creating a max heap {here we are using std::pair<int, int> taken from a HashMap}
    ```c++
    // EXAMPLE OF MIN HEAP
    std::priority_queue<
    std::pair<int, int>,                // value type
    > pq;
    ```

    - The following is the same example for a MIN HEAP
    ```c++
    // EXAMPLE OF min heap
    std::priority_queue<
    std::pair<int, int>,                // value type
    std::vector<std::pair<int, int>>,   // container type (missing in your code)
    std::greater<std::pair<int, int>>   // comparator
    > pq;
    ```

    - Accesing heap is `SAME` as acceing `std::heap` data structure that we will NOT use for DFS.
    ```c++
    auto [freq, num] = pq.top(); // Same as heap top and then pop
    pq.pop(); // Remove it from the queue
    ```

    - Uses
        - K most/least occuring element
        - K pairs of smallest/largerst sum


- *Prim's Algo*:
    - Results in a miniumum spanning tree
    - Prim's is a greedy algorithm, queue the node with smallest edge on every node that has been visited
    - Minimum Spanning Tree: A listing of nodes whose pairwise sum of edges comes out to be the minimum.

- *Dijkstra's Shortest Path*
    - Graph connected by weighted edges. Undirected
    - Find shortest path from a fixed node to every other node
        - Calculate distance from city to every other city to find optimal path
    
    Variables
        - current distance
        - last distance
        - visited nodes 
        - hashtable containing all data
    
    Steps
        1. Mark all nodes as unvisited. We just need the visited set
        2. Assign a Hashmap of <int, pair<Node, Node> > where the pair contains shortest distance, previous node. First value is node name
        3. Start at node A (start), calculate the distance between all the unvisited nodes
            3.1 : Update the shortest distance for all pairs, find node with shorter distance and update the table
        4. Mark current node visited and use a greedy heuristic i.e. children with least distance on the queue.
        5.  Go back to step 3 and **CUMULATIVE** add current distance with distance from that node to its neighbors
        6. After the loop is over, we now have the shorest distance from A to all other nodes
        7. To find the shortest path, we start going backward, C --> F --> D --> A i.e. start with node and query what was the previous node that it was assigned to

- *A (start)*
    - A deterministic algroithm based on the knowledge of a complete map and heursitics
    - Grid nodes in a 2D grid map. We can calculate 8 nodes from that, technically a BFS
    - Requires knowledge of the start and end node.
    - Start from node A calculate for 8 neighbors
        - G cost: distance from this node to the neighbor
        - H cost (heuristic): distance of the neighbor from end node
        - F cost: G cost + H cost
    - Chose the node with the lowest `F cost` and move their
    - Now in this new node, repeat the process
        - Calculate G cost for neighbors
        - Calculate H cost for neighbors
        - get F cost
        - move to lowest F-cost
    - Why it works
        - As we move closer to the goal, G cost increase and H cost decreases
        - At end, H-cost goes to 0
    - Say two neighbors have same F-cost, then the tie breaker is the node with loweset H-cost