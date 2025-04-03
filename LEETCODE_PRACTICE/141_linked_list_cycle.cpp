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
141. Linked List Cycle

Uses the Floyd's Fast and Slow pointer technique

Given a linked list, determine if it has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by
continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail`s next pointer is connected
to. Note that

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. 
If pos is -1, then there is no cycle in the linked list.


Input: head = [3,2,0,-4]
Output: true / false, pos = 1
Explanation: There is a cycle in the linked list, where tail connects to to the 1st node (0-index)

- Algorithm will 

-- Discussion
    - In this problem a contiguous array is used to simplify the linked list construction
    - Can we use a singly connected list? Yes but how?
    - To traverse a linked list we keep going through the node until we come to a node that returs nullptr in next
    - To detect cycle, it is simpler to use a hashset to detect previously visited node
    - Remember we add the node itself not the value since the value can be duplicated
    - Fast - Slow pointer can very quickly scan through the linked list


-- Solution
    - Using HashSet with visting each node will also make it O(n)
    - Using fast and slow pointer makes it O(n) the tortoise and hare method

*/

class Node {
    public:
        int data;
        std::shared_ptr<Node> next;

    Node(int val){
        data = val;
        next = nullptr;
    }

    ~Node() = default;

};


bool detectCycleInLinkedList(std::vector<int> &linkedListArray, int &pos){

    /*
        Guard clauses
    */
    
    std::vector<std::shared_ptr<Node>> collection; // Actual collection of node

    // std::unordered_set<std::shared_ptr<Node>> visited; // Nodes that have been visited already

    // Step 1 Initialize the nodes and update connections
    for (int k = 0; k < linkedListArray.size(); k++){
        int val = linkedListArray[k];
        collection.push_back(std::make_shared<Node>(val));

        if (k > 0) {  // If NOT the first node
            collection[k-1]->next = collection[k];  // Connect previous to current
        }
    }

    // Step 2: Add the cyclic constraint using pos
    collection.back()->next = collection[pos]; // Last node now points to node at position 1
    
    // TODO print out value and value of nodes pointed by next?

    // std::cout << "Linked List structure:" << std::endl;
    // for (size_t i = 0; i < collection.size(); i++) {
    //     std::cout << "Node " << i << ": value = " << collection[i]->data;
    //     if (collection[i]->next) {
    //         std::cout << ", next->val = " << collection[i]->next->data;
    //     } else {
    //         std::cout << ", next = nullptr";
    //     }
    //     std::cout << std::endl;
    // }


    // Apply Floyd's slow fast poitner trick for circular detection

    // Step 1 make both slow and fast pointer 
    std::shared_ptr<Node> slow = collection[0]; 
    std::shared_ptr<Node> fast = collection[0];

    // Phase 1: Detect cycle
    while (true) {
        // If slow pointer exsists, move to next pointer
        if (slow->next) {
            // slow = slow->next;
            slow = slow->next;
        } else {
            // Why slow pointer has reached end of linked list and there is no more pointers left
            return false; // No cycle if we reach the end
        }
        
        // Move fast pointer two steps
        if (fast->next) {
            // Does the next pointer point to another 
            if (fast->next->next){
                // Advance fast pointer by 2 nodes
                fast = fast->next->next;
            }
            else {
                // Reached end of linked list
                return false;
            }
            
        } else {
            return false; // No cycle if we reach the end
        }
        
        // If slow and fast meet, we found a cycle
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {

    std::vector<int> head = {3,2,0,-4};
    int pos = 1; // Required during construction
    
    bool result = detectCycleInLinkedList(head, pos);

    std::cout << "Cycle detected " << (result? "true":"false") << std::endl;

    return 0;
}
    


// ************************************



