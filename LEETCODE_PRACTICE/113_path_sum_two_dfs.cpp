#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers
#include <cmath> // Math library
#include <unordered_map> // Hasmaps
#include <unordered_set> // Hashsets
#include <limits> // inf limits
#include <numeric> // std::atoi, std::accumulate
#include <utility> // std::pair
#include <queue> // std::queue
#include <stack>

/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

return
[
   [5,4,11,2],
   [5,8,4,5]
]


-- Dicussion
    - this problem asks go form root to leaf which and for the path traveled asks to find the sum
    - this is a depth first search problem as we want to explore as deep as possible before backtracking
    - the problem gives us a generic binary tree
    - my solution by default is the in-order-traversal i.e. parent - left - right and then repeat
    - stack / queue are adapter containers that wraps around the STL 
    - stacks are last in fast out

-- Solutiuon
    - define a class called Node with two pointers and a value
    - manually construct the tree and pack it as a vector of Node points
    - start the interface for the solution

*/

class Node {
    public:

    int data;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }

    ~Node() = default;

};


std::vector<std::vector<std::shared_ptr<Node>>> pathSumUsingDFS(std::vector<int> &traversalArray, int &target_sum){

    // Variables / Book keepers
    std::vector<std::shared_ptr<Node>> tree;
    std::vector<std::vector<std::shared_ptr<Node>>> paths;

    /*
        Guard clause
        - what if the root node already had the target sum?
    */
    if (traversalArray.empty()){
        std::cout << "no tree as level traversal array provided" << std::endl;
        return paths; // Just return wont work
    }

    // Create nodes
    for (auto i : traversalArray){
        if (i == -1) continue;
        tree.push_back(std::make_shared<Node>(i));
    }

    // Setup the partent-child relationships
    // As it is a binary tree, we can use the following pattern
    // for (int i = 0; i < tree.size(); i++) {
    //     int leftIdx = 2*i + 1;
    //     int rightIdx = 2*i + 2;

    //     // left tree index is within bound
    //     if (leftIdx < tree.size()){
    //     tree[i]->left = tree[leftIdx];
    //     }

    //     // right tree index is within bound
    //     if (rightIdx < tree.size()){
    //     tree[i]->right = tree[rightIdx];
    //     }

    // }

    // Manually setup the tree

    // Level 1
    tree[0]->left = tree[1];
    tree[0]->right = tree[2];

    // Level 2 left
    tree[1]->left = tree[3];

    // Level 2 right
    tree[2]->left = tree[4];
    tree[2]->right = tree[5];

    // Level 3 left
    tree[3]->left = tree[6];
    tree[3]->right = tree[7];

    // Level 3 right
    tree[4]->left = nullptr;
    tree[4]->right = nullptr;

    tree[5]->left = tree[8];
    tree[5]->right = tree[9];


    // TODO is there a way to check the parent and childres of all these nodes

    // for (int i = 0; i < tree.size(); i++) {
    //     std::cout << "Node " << i << " (Value: " << tree[i]->data << "): ";
        
    //     if (tree[i]->left) {
    //         std::cout << "Left = " << tree[i]->left->data << ", ";
    //     } else {
    //         std::cout << "Left = NULL, ";
    //     }
        
    //     if (tree[i]->right) {
    //         std::cout << "Right = " << tree[i]->right->data;
    //     } else {
    //         std::cout << "Right = NULL";
    //     }
        
    //     std::cout << std::endl;
    // }
    

    // Setup DFS
    // std::vector<int> currentPath;
    // std::stack<std::shared_ptr<Node>> stack;
    
    std::vector<std::shared_ptr<Node>> currentPath;
    std::stack<std::pair<std::shared_ptr<Node>, int>> stack; // Node and its position in path
    

    // std::unordered_set<int> visited; // Hash
    
    // Push root to the stack
    stack.push({tree[0], 0}); // Root node at position 0
    
    while(!stack.empty()) {
        auto [currentNode, pathIndex] = stack.top(); // LIFO get the node that is in the top
        stack.pop(); // Remove this node from stack
        
        std::cout << "Now processing node: " << currentNode->data << std::endl;

        // Change 5: Resize path to current position before adding node
        // TODO why?
        if (currentPath.size() > pathIndex) {
            currentPath.resize(pathIndex);
        }

        // Add this node's value into the current path
        currentPath.push_back(currentNode);
        
    
        // Have we reached the leaf node and gotten the target sum
        if (currentNode->left == nullptr && currentNode->right == nullptr){
            
            // If the sum comes up okay then add it to the paths
            int sum_val = 0;
            for (int k = 0; k < currentPath.size(); k++){
                // std::cout << currentPath[k] <<std::endl;
                sum_val = sum_val + currentPath[k]->data;
            }
            
            std::cout << "current sum " << sum_val <<std::endl;
            
            if (sum_val == target_sum){
                paths.push_back(currentPath);
            }
        } else {
            // This is an intermediate node, push its children to the stack
            if (currentNode->right !=nullptr) {
                stack.push({currentNode->right, pathIndex + 1});
            }
            if (currentNode->left !=nullptr) {
                stack.push({currentNode->right, pathIndex + 1});
            }
        }
    }
    
    return paths;
}

int main() {

    std::vector<int> traversalArray = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, -1, 5, 1};
    int sum = 22;

    std::vector<std::vector<std::shared_ptr<Node>>> paths = pathSumUsingDFS(traversalArray, sum);

    // TODO a code to extract the data of the paths and show the path as their chain

    if (paths.empty()) {
        std::cout << "No paths found with the given sum." << std::endl;
    } else {
        for (size_t i = 0; i < paths.size(); ++i) {
            std::cout << "Path " << (i + 1) << ": ";
            
            // Print each node's value in the path
            for (size_t j = 0; j < paths[i].size(); ++j) {
                std::cout << paths[i][j]->data;
                
                // Add arrow between nodes (except after the last node)
                if (j < paths[i].size() - 1) {
                    std::cout << " -> ";
                }
            }
            
            // Optionally, verify the sum
            int pathSum = 0;
            for (const auto& node : paths[i]) {
                pathSum += node->data;
            }
            std::cout << " (Sum: " << pathSum << ")" << std::endl;
        }
    }


    
    return 0;
}
    


// ************************************



