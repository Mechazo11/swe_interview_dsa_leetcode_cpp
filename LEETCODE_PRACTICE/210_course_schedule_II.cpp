#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers
#include <cmath> // Math library
#include <unordered_map> // Hasmaps
#include <unordered_set> // Hashsets
#include <functional> // for std::function a wrapper for functional pointer
#include <numeric> // std::atoi

/*

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

* Pseudocode
    - Determine if problem is tree or a graph?
    - If graph, Node class is not going to have left and rigth ptrs
    - Using the constraints given, create graph as a std::vector but with no adjacency list (i.e. directions)

*/

class Node {

    public:
    
    // Variables
    int data;
    std::vector<int> neighbors; // To track neighbors

    // Constructor and Destructor
    Node(int val){
        this->data = val; // This course number
    }


};


int runDFSSort(int node, const std::vector<Node> &graph, 
    std::unordered_set<int>& visited, std::unordered_set<int>& path,
    std::vector<int>& result){

    // If node is the current path, we have detected a cycle
    // This reads like the following, check the hashmap and if you find the element before you reach the end
    // execute the following if logic
    if (path.find(node)!=path.end()){
        return false;
    }

    // Is this node already visited?
    // This node has already been visited so we don't need to run dfs on this anymore
    if (visited.find(node)!=visited.end()){
        return true;
    }

    // Now this current node needs to be in the visited set
    visited.insert(node);
    
    // Put this node in the current path
    // Without this step we cannot detect cycle
    path.insert(node);

    // Now check this node's adjacency list
    for (int neighbor : graph[node].neighbors) {
        // Run dfs and see it it returns false.
        // If it returns false, we may have detected a cycle in the deeper level
        // ** THIS IS WHERE RECURSION OCCURS
        if (!runDFSSort(neighbor, graph, visited, path, result)){
            return false;
        }
    }

    // Take out this node from the current path
    path.erase(node);

    // Now add this node to the results path
    result.push_back(node);

    return true; // This node has been visited and has been added to the path

}

std::vector<int> sovleTopologicalSortUsingDFS(int &num, std::vector<std::vector<int>> prerequisites){

    /*
        Need to return empty array if it is impossible to finish all courses i.e. cycle detection
    */
    std::vector<int> result; // final path

    // Step: Create the graph
    std::vector<Node> graph; // The entire graph is this collection

    for (int i = 0; i < num; i++){
        graph.push_back(Node(i)); // We are creating the graph with no directed edges just the nodes
    }

    // Step: Define the adjacency list i.e. directions to other nodes
    for (auto pair : prerequisites){
        int course = pair[0];
        int prereq = pair[1];

        // This prereq is now a neighbor of the course Node
        graph[course].neighbors.push_back(prereq); // 0.neighbours(1)

    }

    // Step define the Hashsets to keep track of visited and current path
    // Lets define two sets one to keep track of visited nodes and the other to keep track of current path
    std::unordered_set<int> visited; // All visited node
    std::unordered_set<int> path; // Current DFS path, used internally

    // Step now cycle through all nodes and check if we have reached end of 
    for (int i = 0; i < num; i++){
        if (visited.find(i) == visited.end()){
            // This states this node has not been visited until now
            // runDFSSort will return false if it detects a cycle
            if (!runDFSSort(i, graph, visited, path, result)){
                result.clear();
                return result; // Returns empty as the problem is not solvable
            }
        }
    }

    // Reverse for correct topological order
    // DFS processes the leaf node first before back tracking
    std::reverse(result.begin(), result.end());


    return result;

}

int main() {

    // int num = 4;
    // std::vector<std::vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}}; // list in list

    int num = 4;
    std::vector<std::vector<int>> prerequisites = {{3, 1}, {1, 0}, {1, 2}}; // list in list

    // int num = 2;
    // std::vector<std::vector<int>> prerequisites = {{1, 0}};

    std::vector<int> result = sovleTopologicalSortUsingDFS(num, prerequisites);

    // Print the result
    if (result.empty()) 
    {
        std::cout << "No valid course order exists (cycle detected)" << std::endl;
    } else {
        std::cout << "Course order: ";
        for (int course : result) {
            std::cout << course << " ";
        }
        std::cout << std::endl;
    }
    

    return 0;
}
    


// ************************************



