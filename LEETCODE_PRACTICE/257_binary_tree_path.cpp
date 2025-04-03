#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers
#include <cmath> // Math library
#include <unordered_map> // Hasmaps
#include <functional> // for std::function a wrapper for functional pointer
/*
Given a binary tree, return all root-to-leaf paths.


Input:

   1
 /   \
2     3
 \
  5


Note: a leaf is a node with no children

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

- I will exclusively use Class to define a binary tree. Structs are also possible but this gives me a good chance to practice both together
- Both DFS and BFS woudl solve this problem but the problem asks to path root to leaf, hence depth first is required

Pseudocode
    - Define a templated Node class (always)
    - Initialize the nodes and define parent child relations. Idea is to do this level by level
    - Pack all nodes into a std::vector (conforming to stack principle)
    - Pass to solution interface
    - Solve the problem

- Depth first search rules



*/

// template<typename T> problematic because the type names are now completley ambiguous leading to misting "2" with 2
class Node {
   
    public:
    
    // Variables
    char data;
    // In a tree structure each node must maintain unique ownership to nodes they are pointing to.
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    // Class constructor, technique of list initialization
    Node (char val){
        
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    
    // Class destructor
    ~Node() = default;

};

// Recursive depth first search
void depthFirstSearch(std::shared_ptr<Node> node, std::string currentPath, std::vector<std::string> &out) {
    
    // At beginning no path has been explored so its empty. Add root node in the explored path
    if (currentPath.empty()) {
        currentPath = std::string(1, node->data); // Convert char to string properly, create string with one character
    } else {
        // unique to this problem
        currentPath = currentPath + "->" + std::string(1, node->data); // Add node to end of path
    }
    
    // If leaf node, we have reached end of path
    if (node->left == nullptr && node->right == nullptr) {
        out.push_back(currentPath);
        return; // In recursion THIS IS WHERE backtracking happens
    }
    
    // Recursively process children
    if (node->left) depthFirstSearch(node->left, currentPath, out);
    if (node->right) depthFirstSearch(node->right, currentPath, out);
}

std::vector<std::string> pathsOutUsingDepthFirstSearch(std::vector<std::shared_ptr<Node>> &tree){
    // Initialize some work variables
    std::vector<std::string> out;

    // Check if tree is empty
    if (tree.empty() || !tree[0]) {
        return out;
    }
    
    // Call the DFS function with the root node.
    // AS DFS runs recursively it will complete the problem automatically
    depthFirstSearch(tree[0], "", out);
    
    return out;
}



int main() {

    // Initialize all nodes
    std::shared_ptr<Node> root = std::make_shared<Node>('1');
    std::shared_ptr<Node> node_2 = std::make_shared<Node>('2');
    std::shared_ptr<Node> node_3 = std::make_shared<Node>('3');
    //std::shared_ptr<Node> node_4 = std::make_shared<Node>('4');
    std::shared_ptr<Node> node_5 = std::make_shared<Node>('5');

    // Define parent-child relationships, this constructs the tree

    // root - level 1
    root->left = node_2; // Shared pointers does not need std::move() command
    root->right = node_3;

    // level 1 - level 2
    node_2->right = node_5;

    // Pack as a std::vector
    std::vector<std::shared_ptr<Node>> tree = {root, node_2, node_3, node_5};
    
    std::vector<std::string> paths = pathsOutUsingDepthFirstSearch(tree);

    std::cout << "\nFinal paths:" << std::endl;
    for (auto& path : paths) {
        std::cout << path << std::endl;
    }


    return 0;
}
    


// ************************************



