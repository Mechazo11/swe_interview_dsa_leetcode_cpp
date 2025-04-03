# Datastructures, Patterns and Techniqueas

From [LeetCode Was Hard Until I Learned THESE 8 Patterns (With Templates!)](https://www.youtube.com/watch?v=RYT08CaYq6A) and []()

*Introduction:*
- 8 important patterns for coding interviews split into two categories:
- *Linear structures:* arrays, linked lists, strings.
- *Nonlinear structures:* trees, graphs.
- Focus on pre-built code templates for these patterns.

- **Linear Data Structure Patterns:**
1. **Two Pointers**
    - Reduces time complexity to linear time \(O(n)\).
    - `int left = 0 or i+1` for three pointer
    - `int right = nums.size() - 1`
    - if `sum < 0` or `sum<target` we need to advance the left pointer by 1 i.e. `left++`;
    - if `sum > 0` or `sum<target` we do pull right pointer by 1, i.e. `right--`

2. **Sliding Window:**
    - Very useful for `strings, subarrays, linkedlists`
    - If you see a binary / truth value array, maybe not use it.
    - Augmented version of two pointer approach where $i$ , $j = i + some-offset$
    - Expands or contracts the window to meet specific conditions (e.g., longest substring without repeating characters).
    - Two pointers method: `O(n)` time complexity

2.a **HashMaps**:
    - Essentially the same functionality as python's dictionary
    - Supports dynamic data
    - Common operations are insert, delete and search
    - `std::unordered_map`: Key-value pairs with unique keys
    - `std::unordered_set`: Collection of unique values
    - `std::unordered_multimap`: Multiple values per key
    - `std::unordered_multiset`: Multiple instances of values
    - Time complexity: ```O(1)``` is their average `search` time
    - Space complexity: ```O(n)```

3. **Binary Trees and Binary Search and Modified Binary Search**
    - All Binary tree problems can be decomposed to the following four steps
        a. Finding one or more base cases
        b. Calling itself (recursion) on the left sub tree
        c. Calling itself (recursion) on the right sub tree
        d. Joining the results
    
    - Time complexity $O(log n)$
    - Extends to lists with monotonic conditions, not just sorted numbers.
    - Examples that we need to solve: 
        a. Finding the minimum in a rotated sorted array
        
4. **Breadth-First Search (BFS):**
    - Explores nodes level by level.
    - Uses a queue to keep track of visited nodes (ideal for level order traversal).

5. **Depth-First Search (DFS):**
    - Dives deep into one path before exploring others.
    - Often uses recursion and is memory efficient for exploring all paths.
    - Example: counting islands in a grid.

    b. Sum of all elements in the binary tree
        c. Max value of tree
        d. find height of tree
        e. reverse node

6. **Backtracking / Greedy:**
    - Extension of DFS, explores all possible solutions.
    - Builds the solution dynamically by making decisions and backtracking on invalid paths.
    - Example: letter combinations of a phone number.

7. **Heaps:**
    - Used for questions related to top K, K smallest/largest.
    - *Min Heap:* smallest value at the root.
    - *Max Heap:* largest value at the root.
    - Max Heap is used to find K smallest values, and vice versa for K largest.


- **Dynamic Programming (DP):**

8. *Dynamic Programming:*
    - Optimizes solutions by breaking problems into overlapping subproblems.
    - Two approaches:
    - *Top-down:* recursive with memoization to store results.
    - *Bottom-up:* solves smaller subproblems iteratively using a table.
    - Too complex for this video but covered in-depth on their website.


---

### Notes on Binary Tree Algorithms

### Binary Trees

- root node: The starting node / parent node
- nodes: intermediary nodes that can be parent/children to other intermediary nodes
- leaf: a node that has **zero** children

- Condition 1 at most 2 children per node
- Condition 2 exactly one root
- Condition 3 exactly one path connects each node to the root. If there were more than one, then it is not a binary tree problem

- singleton tree: tree with just the root node, is still a binary tree as it satisfies the three conditions

- binary trees are usually represented using a class
- usually we just have the node class, then setup the rest of the problem


### Depth First Search

- Uses `Stack` which uses `Last-in First Out` data structure
