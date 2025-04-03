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
#include <queue> // Queue data structure

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

Given binary tree [3,9,20,null,null,15,7],

result

[
  [3],
  [9,20],
  [15,7]
]

- Two hash sets visited and current. Then also a vector in vector for levels

* Pseudocode
- First we start by defining a class for nodes in a binary tree
- Setup the interface function that takes input binary tree as a ordede traversal list
- Define the nodes as vector<int> and pass into the solution fuction
- Construct the nodes and then define the parent child relationships
- Note that in breadth first search since we are only concerned with nodes at levels, keep track of visited is not required as it is not a graph nor is 
- current path needed to keep track of cycle
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
  ~Node() {}

};

// Breadth-First Search algorithm
// This function was unnecessary, try not to have two method solutions except DFS
void levelOrderBFS(std::shared_ptr<Node> &node, std::vector<std::vector<int>> &outPaths){

  // What happens if the node is empty i.e. empty list
  if (!node || node == nullptr){
    return;
  }

  // Initialize a queue object
  std::queue<std::shared_ptr<Node>> node_queue;

  // Push queue into this node
  node_queue.push(node); // Push adds at the back of the queue

  // Start iterative Breadth First Search algorithm
  // When empty, node_queue.empty() returns True which the Logical NOT operator flips to False
  while(!node_queue.empty()){

    // How many nodes at this level
    int levelSize = node_queue.size();

    // A container to store all nodes in this level
    std::vector<int> currentLevelNodes;

    // process all nodes in this level

    for (int i = 0; i<levelSize; i++){
      // Add the first  node (front of the queue to the level) and then pop it
      auto frontNode = node_queue.front();
      node_queue.pop(); // Remove the frontNode from queue as we are processing it

      // Add this node back to the vector
      currentLevelNodes.push_back(frontNode->data); // Value of the node

      // Look to left and right children and if they exsist append to the queue
      if (frontNode->left) node_queue.push(frontNode->left);
      if (frontNode->right) node_queue.push(frontNode->right);

    }

    // Add the current level to result
    outPaths.push_back(currentLevelNodes);
  }
  
}

std::vector<std::vector<int>> levelOrderTraversalUsingBreadthFirstSearch(const std::vector<int> &traversalArray){

  // Initialize some work variables
  
  std::vector<std::shared_ptr<Node>> nodes;

  // Create the nodes
  for (int val : traversalArray) {
    if (val == -1) continue; // We don't need the null or -1 nodes
    nodes.push_back(std::make_shared<Node>(val));
  }

  // Add / update parent child relationships
  for (int i = 0; i < nodes.size(); i++) {
    int leftIdx = 2*i + 1;
    int rightIdx = 2*i + 2;

    // left tree index is within bound
    if (leftIdx < nodes.size()){
      nodes[i]->left = nodes[leftIdx];
    }

    // right tree index is within bound
    if (rightIdx < nodes.size()){
      nodes[i]->right = nodes[rightIdx];
    }

  }

  // Setup some variables for performing breadth-first search
  std::unordered_set<int> visited; // Nodes that have been already visited
  std::unordered_set<int> currentPath; // Lets keep it
  std::vector<std::vector<int>> outPaths;
  
  
  // Breadth-First search is to be done using queue
  levelOrderBFS(nodes[0], outPaths);


  return outPaths;

}

int main() {

    std::vector<int> traversalArray = {3,9,20,-1, -1, 15, 7};

    std::vector<std::vector<int>> result = levelOrderTraversalUsingBreadthFirstSearch(traversalArray);

    // Print the level order traversal result
    std::cout << "Level Order Traversal:" << std::endl;
    for (int i = 0; i < result.size(); i++) {
        std::cout << "Level " << i << ": ";
        for (int val : result[i]) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::vector<int>> result2 = result; // Make a copy
    std::reverse(result2.begin(), result2.end());

    // 107
    // Print the level order bottom up
    std::cout << "Level Order Traversal bottom up:" << std::endl;
    for (int i = 0; i < result2.size(); i++) {
        std::cout << "Level " << i << ": ";
        for (int val : result2[i]) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}
    


// ************************************



