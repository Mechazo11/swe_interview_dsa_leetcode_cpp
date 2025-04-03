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
143. Reorder List



-- Discussion
    - Observe the head and tail connects
    - L1 connects to Ln-1 where n is the last value.
    - Alternating between middle and end
    - the following is O(n) and O(1) solution but if the simpler one is 
    - O(n) time and O(n) space by creating a second list, using two pointers until they don't meet in the middle
    - the value in the middle will then be pushed back


-- Solution
    - big idea is to split the list into two halves
    - then start merging between them
    - 2nd list is going to be merged from the right
    - observe for the 2nd half of the the list, the links are going in the wrong direcotin, simple is to reverse

*/

//  Common for any singly liked list
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

std::vector<std::shared_ptr<Node>> reOrderLinkedList(std::vector<int> &linkedListArray){

    // Initialize work varialbe
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

    // First record a pointer to the head itself
    std::shared_ptr<Node> head = collection[0]; // Always remeber the head in fast slow pointer method

    // Handle single node case
    if (collection.size() <= 1) {
        return collection;
    }
    
    // Phase 1, figure out the starting of the second half and reverse the links
    // Floyd's two pointer slow and fast pointer
    // At the very beginning both slow and fast pointers are pointing to the head
    std::shared_ptr<Node> slow = head;
    std::shared_ptr<Node> fast = head;

    // How long to run this loop, as long as fast pointer does not become null and fast->next does has a 
    while(fast->next != nullptr && fast->next->next != nullptr){
        // Shift slow by one pointer
        slow = slow->next;
        fast = fast->next->next; 
    }

    // Now slow pointer is in the middle of end of first half
    std::shared_ptr<Node> second = slow->next; // Start of second half
    slow->next = nullptr; // Break the link between first and second half

    // reverse the 2nd half
    std::shared_ptr<Node> prev = nullptr;
    std::shared_ptr<Node> current = second;
    std::shared_ptr<Node> next = nullptr;

    while (current != nullptr) {
        next = current->next; // Remember next node
        current->next = prev; // break connection and pair backwards
        prev = current; // update previous to become current
        current = next; // make current move to the next
    }

    // Phase 3: Merge the two halves
    std::shared_ptr<Node> first = head;
    std::shared_ptr<Node> temp1, temp2;
    
    // How to decide which is the condition for the while loop. 
    // Observe that in both cases the 2nd half of the list will be same or smaller so make sense we iterate for it
    // We are breaking and readding connection now twice. Better to have two temporary ptrs
    

    while (second != nullptr) {
        // Save next pointers
        temp1 = first->next;
        temp2 = second->next;
        
        // Connect nodes in the required pattern
        first->next = second; // L0 -- Ln, L1 -- Ln-1
        second->next = temp1;
        
        // Move to the next pair of nodes
        first = temp1;
        second = temp2;
    }
    
    // Rebuild collection to reflect the new order
    collection.clear();
    std::shared_ptr<Node> current_node = head;
    while (current_node != nullptr) {
        collection.push_back(current_node);
        current_node = current_node->next;
    }
    
    // Print the reordered sequence (without modifying head)
    std::cout << "Reordered sequence: ";
    current_node = head;
    while (current_node != nullptr) {
        std::cout << current_node->data;
        if (current_node->next) {
            std::cout << "->";
        }
        current_node = current_node->next;
    }
    std::cout << std::endl;
    
    return collection;
}

int main() {

    std::vector<int> linkedListArray = {1,2,3,4}; // ans: 1->4->2->3.
  
    
    std::vector<std::shared_ptr<Node>> collection = reOrderLinkedList(linkedListArray);

    // std::cout << "Cycle detected " << (result? "true":"false") << std::endl;

    


    return 0;
}
    


// ************************************



