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
92. Reverse Linked List II

Reverse a singly linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Input: 1->2->3->4->5-, m = 2, n = 4
Output: 1->4->3->2->5

-- Discussion
    - the problem states directly it is a singly linked
    - we have to only swap position from m to n i.e. 
    - problem is m = 2 and n = 4 are all 1-index, we need to change to 0 index
    - the problem has three parts
    - in the reversed_collection, we check 

-- Solution
    - Using HashSet with visting each node will also make it O(n)
    - doing it in one pass is the difficult part

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

std::vector<std::shared_ptr<Node>> reverseLinkedList(std::vector<int> &linkedListArray, int &m, int &n) {
    
    
    std::vector<std::shared_ptr<Node>> collection;
    
    // Handle empty list
    if (linkedListArray.empty()) {
        return collection;
    }

    // Creatre nodes and initialzie singly linked array
    for (int i = 0; i < linkedListArray.size(); i++) {
        collection.push_back(std::make_shared<Node>(linkedListArray[i]));
        if (i > 0) {
            collection[i - 1]->next = collection[i];
        }
    }

    
    // Get head of the list
    std::shared_ptr<Node> head = collection[0];
    
    // If m == 1, we're reversing from the head
    if (m == 1) {
        // Create a dummy node to simplify the logic
        std::shared_ptr<Node> dummy = std::make_shared<Node>(0);
        dummy->next = head;
        
        // Find the node before the reversal starts
        std::shared_ptr<Node> prev = dummy;
        std::shared_ptr<Node> curr = head;
        
        // Find the mth node (which is the head in this case)
        // No need to move since m == 1
        
        // Save the node that will be the end of the reversed section
        std::shared_ptr<Node> connection = curr;
        
        // Reverse the sublist from m to n
        // Runs fo n-m + 1 nodes
        std::shared_ptr<Node> next = nullptr;

        for (int i = 0; i < n - m + 1; i++) {
            next = curr->next; // Keep copy of next node's connection
            curr->next = prev; // break next node connection and point to prev node
            prev = curr; // move prev to current
            curr = next; // move curr to next
        }
        
        // Connect the reversed section back to the list
        connection->next = curr;
        dummy->next = prev;
        
        // Update the head if needed
        head = dummy->next;
        
        // Update the collection to reflect the new order
        collection[0] = head;
        
        // Rebuild the collection vector to match the new order
        std::vector<std::shared_ptr<Node>> result;
        std::shared_ptr<Node> temp = head;
        while (temp) {
            result.push_back(temp);
            temp = temp->next;
        }
        
        return result;
    } else {
        // Find the node before the reversal starts
        std::shared_ptr<Node> prev = head;
        
        for (int i = 1; i < m - 1; i++) {
            prev = prev->next;
        }
        
        // Find the mth node
        std::shared_ptr<Node> curr = prev->next;
        
        // Save the node that will be the end of the reversed section
        std::shared_ptr<Node> connection = curr;
        
        // Reverse the sublist from m to n
        std::shared_ptr<Node> next = nullptr;
        std::shared_ptr<Node> temp_prev = nullptr;
        
        for (int i = 0; i < n - m + 1; i++) {
            next = curr->next;
            curr->next = temp_prev;
            temp_prev = curr;
            curr = next;
        }
        
        // Connect the reversed section back to the list
        prev->next = temp_prev;
        connection->next = curr;
        
        // Rebuild the collection vector to match the new order
        std::vector<std::shared_ptr<Node>> result;
        std::shared_ptr<Node> temp = head;
        while (temp) {
            result.push_back(temp);
            temp = temp->next;
        }
        
        return result;
    }
}


int main() {

    std::vector<int> linkedListArray = {1,2,3,4,5};
    int m = 2;
    int n = 4;
    
    std::vector<std::shared_ptr<Node>> collection = reverseLinkedList(linkedListArray, m, n);

    // std::cout << "Cycle detected " << (result? "true":"false") << std::endl;

    std::cout << "Linked List structure:" << std::endl;
    for (size_t i = 0; i < collection.size(); i++) {
        std::cout << "Node " << i << ": value = " << collection[i]->data;
        if (collection[i]->next) {
            std::cout << ", next->val = " << collection[i]->next->data;
        } else {
            std::cout << ", next = nullptr";
        }
        std::cout << std::endl;
    }

    return 0;
}
    


// ************************************



