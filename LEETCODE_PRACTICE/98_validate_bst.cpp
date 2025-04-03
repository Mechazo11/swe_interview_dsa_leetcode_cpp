#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers
#include <cmath> // Math library
#include <unordered_map> // Hasmaps
#include <unordered_set> // Hashsets
#include <limits> // inf limits

/*

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

- Discussion
    - Ask if it is okay to swap out null with -1 so that they can be thrown out

- Solution
    - Depth first search with Node defined as binary nodes
    - Simple thing to do each time we see a node, we check if the number of left child value is less and right child value is more
    - First only check all the left sub-trees and then look the right subtrees

Input: [2,1,3]

*/

class Node {
   
    public:
    
    // Variables
    int data;
    // In a tree structure each node must maintain unique ownership to nodes they are pointing to.
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    // Class constructor, technique of list initialization
    Node (int val){
        
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    
    // Class destructor
    // Automatic garbage collection
    ~Node() {}

};


// Recursive depth first search
bool istBST(std::shared_ptr<Node> node, int minVal, int maxVal) {
    
    // If this a leaf node, return true
    if (node->left == nullptr && node->right == nullptr){
        return true;
    }

    // Is the current node violating any of the BST property
    if (node->data <= minVal || node->data >= maxVal){
        // Fails either the left bst or right bst property
        return false;
    }

    // Now recursively call both left and right trees and AND their logic.
    // If both left and right children are also valid BST, they will return true, else a false
    
    return istBST(node->left, minVal, node->data) && istBST(node->right, node->data, maxVal);

}

bool isValidBST(std::vector<int> &traversalArray){

    

    // What happens if the traversal array is empty
    // Empty tree is valid
    if (traversalArray.empty()){
        return true;
    }

    // Working variables
    std::vector<std::shared_ptr<Node>> nodes;
    // We are checking bounds, these would be adequate until we overflow int
    int minVal = std::numeric_limits<int>::min();
    int maxVal = std::numeric_limits<int>::max();


    // Create nodes
    for (int val : traversalArray) {
        nodes.push_back(std::make_shared<Node>(val));
    }
    
    // Connect nodes (level-order). This creates the tree
    for (int i = 0; i < nodes.size(); i++) {
        
        if (traversalArray[i] == -1) continue;


        int leftIdx = 2 * i + 1;  // 1, 3 , 5
        if (leftIdx < nodes.size()) {
            nodes[i]->left = nodes[leftIdx];
        } 
        
        int rightIdx = 2 * i + 2; 
        if (rightIdx < nodes.size()) {
            nodes[i]->right = nodes[rightIdx];
        } 
    }
    
    // Call the node only ONCE
    // We need to iteratively 
    bool out = istBST(nodes[0], minVal, maxVal); // Recursively calls

    return out;

    // return true;
}


int main() {

    std::vector<int> traversalArray = {5,1,4,-1,-1,3,6}; // False
    // std::vector<int> traversalArray = {5,3,7,-1,-1,4,8}; // False
    // std::vector<int> traversalArray = {2,1,3}; // True
 
    bool result = isValidBST(traversalArray);

    std::cout << "Input2 is BST: " << (result ? "Yes" : "No") << std::endl;
    

    return 0;
}
    


// ************************************



