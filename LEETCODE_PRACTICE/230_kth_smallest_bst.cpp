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
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3

Follow up:
What if the BST is modified (insert/delete operations) 
often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?


-- Discussion
    - clarificaiton we are looking to find if k^tg smallest element
    - The tree is BST and so are its subtrees. So the values must be in order.
    - when in a tree we want k^th value, it means excluding the root value. Hence the return must be k-1
    - High probability that only the left sub trees needs to be focused
    - The interface function is already defined
    - at least 1 smallest value will be available, this means an empty tree or a tree with one node would have a value of 1
    - Assume null can be substituted with -1 and all values of the nodes are positive integers
    - I think BFS would be an idea solution though recursive depth first search would also work

-- Solution
    - The focus is on searhcing through all levels, so this level traversal based problem 
    - If we go to the very bottom collecting all left sub tree node values and reverse it, we can then return k^th values
    - we need to define a Node class for binary tree with shared_ptrs to avoid doing manual memory management

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

    ~Node(){
        // do nothing
    }

};

int kthSmallest(std::vector<int> &root, int &k){

    // work variable
    
    std::vector<std::shared_ptr<Node>> tree;
    
    /*
        Guard clauses
    */
    if (root.empty() || root.size() == 1){
        std::cout << "empty tree or only one element given" << std::endl;
        return -1;
    }

    if (k < 1){
        std::cout << "input k less than 1 or zero" << std::endl;
        return -1;
    }

    // Setup the nodes
    for (auto i : root){
        // Check if the value is -1 which is null
        if (i == -1) continue;

        tree.push_back(std::make_shared<Node>(i));
    }

    // Update parent child relationshi
    for (int i = 0; i  < tree.size(); i++){
        // get the indices for left and right nodes
        int leftIdx = 2*i + 1;
        int rightIdx = 2*i + 2;

        // Populate child relations
        // The index cannot be greater than elements available
        if (leftIdx < tree.size()){
            tree[i]->left = tree[leftIdx];
        }

        if (rightIdx < tree.size()){
            tree[i]->right = tree[rightIdx];
        }

    }

    // Breadth-first search and go level by level in order and take elements of the left tree
    std::unordered_set<int> visited; // Set  to keep track of visited nodes
    std::vector<int> leftTreeValues; 
    std::queue<std::shared_ptr<Node>> node_queue;

    // BFS

    // Start with the root
    node_queue.push(tree[0]);

    while(!node_queue.empty()) {
        auto node_now = node_queue.front(); // Acquire the first in element
        node_queue.pop(); // Remove it from queue
        
        // If this node has a left child, add the left child's value to our collection
        if (node_now->left != nullptr) {
            leftTreeValues.push_back(node_now->left->data);  // Add the left child's value
            node_queue.push(node_now->left);  // Process the left child later
        }
        
        // We still need to process right children to continue traversal
        // but we don't collect their values
        if (node_now->right != nullptr) {
            node_queue.push(node_now->right);
        }
    }


    // All levels traversed but the result is in descending order
    std::sort(leftTreeValues.begin(), leftTreeValues.end()); // Ascending order, [1,2,3,4,5 ....]


    /*
        Maybe a guard clause check of leftTree values are empty in the case the BST only has right trees
    */

    // Print the values in leftTreeValues
    // std::cout << "leftTreeValues contains: ";
    // if (leftTreeValues.empty()) {
    //     std::cout << "empty";
    // } else {
    //     for (size_t i = 0; i < leftTreeValues.size(); i++) {
    //         std::cout << leftTreeValues[i];
    //         if (i < leftTreeValues.size() - 1) {
    //             std::cout << ", ";
    //         }
    //     }
    // }
    // std::cout << std::endl;

    // Also print the size for verification
    // std::cout << "leftTreeValues size: " << leftTreeValues.size() << std::endl;
    

    return leftTreeValues[k-1];
}

int main() {

    // Setup the problem
    // std::vector<int> root = {5,3,6,2,4,-1,-1,1};
    // int k = 3; // which k^th smallest element do we want to find

    std::vector<int> root = {3,1,4, -1 , 2};
    int k = 1; // which k^th smallest element do we want to find

    int result = kthSmallest(root, k);

    std::cout << "kth smallest value: " << result << std::endl;
    
    return 0;
}
    


// ************************************



