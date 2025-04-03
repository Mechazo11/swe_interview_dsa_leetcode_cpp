#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers
#include <cmath> // Math library
#include <unordered_map> // Dictionary
#include <unordered_set> // List
#include <set> // Python set()
#include <limits> // inf limits
#include <numeric> // std::atoi
#include <utility> // std::pair
#include <queue> // std::queue

/*
127: Word Ladder I [HARD]

127: Word ladder

Given two words (beginWord and endWord), and a dictionary's word list, 
find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time i.e. every adjacent pair of words differs by a single letter
    Each transformed word must exist in the word list. 
    Note that beginWord is not a transformed word.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.


-- Discussion:
    - most simply this is just a unidirected graph where edges are added one after the other
    - an excellent problem that goes back and forth between characters, strings, hashmaps
    - same legnth, same case, we should consider using a hashmap to see if the characters changed are available in all the characters in the list
    - the problem states shortest sequeence, this clearly is a Breadth First Search problem
    - it is very simple we will iterate through the position of each letters, try to form a graph and add it to the queue.
    - we will keep track of both node and level in a hashmap i.e. cog: 1, dog:2 etc.
    - I overthought this process, no problem would need THREE pointers. This should be big red flag
    - the problem is just a unidrected graph problem, which doesn't warrent tracking child pointers.

*/

class Node {
    public:
    std::string word; // Word contained in this node

    // Constructor
    Node(std::string in_word){
        word = in_word;
    }
    
    // Destructor
    ~Node() = default;

};


int wordLadderBFS(std::string &beginWord, std::string &endWord, std::vector<std::string> &dictionary) {
    
    // Create dictionary set for O(1) lookups
    std::unordered_set<std::string> dict_set(dictionary.begin(), dictionary.end());
    
    // If end word is not in dictionary, no solution exists
    if (dict_set.find(endWord) == dict_set.end()) {
        return 0;
    }
    
    // Extract all unique characters
    std::set<char> uniqueChar;
    for (const auto& word : dictionary) {
        for (char c : word) {
            uniqueChar.insert(c);
        }
    }
    
    // Track visited words
    std::unordered_set<std::string> visited;
    
    // Queue for BFS - store word and its distance from start
    // Unique to this problem queue is a tuple not just int
    std::queue<std::pair<std::string, int>> queue;
    
    // Path taken
    std::unordered_map<std::string, std::string> parent;

    // Start BFS from beginWord with distance 1
    // distance in graph is analogous to paths

    queue.push({beginWord, 1});
    
    visited.insert(beginWord);
    
    // Main BFS loop
    while (!queue.empty()) {
        
        // Extract word and distance
        auto [currentWord, distance] = queue.front();
        queue.pop();


        // If we reached the end word, return the distance
        if (currentWord == endWord) {
            
            // Reconstruct path from end to beginning
            std::vector<std::string> path;
            std::string word = endWord;
            
            while (word != beginWord) {
                path.push_back(word);
                word = parent[word];
            }
            path.push_back(beginWord);
            
            // Reverse to get path from beginning to end
            std::reverse(path.begin(), path.end());
            
            // Print the path
            std::cout << "Path: ";
            for (size_t i = 0; i < path.size(); i++) {
                std::cout << path[i];
                if (i < path.size() - 1) {
                    std::cout << " -> ";
                }
            }
            std::cout << std::endl;
            
            
            return distance;
        }
        
        // End word not reached, lets try to mutate the word

        // Try changing each character position
        // If a new word is found add it to the graph, remember I don't have to think about three positions, just the three characters
        for (int i = 0; i < currentWord.length(); i++) {
            char original = currentWord[i];
            
            // Try each possible character
            for (char c : uniqueChar) {
                if (c == original) continue; // this position already as a unique character
                
                std::string newWord = currentWord;
                newWord[i] = c; // swap character with that position
                
                // If the new word is in dictionary and not visited
                if (dict_set.find(newWord) != dict_set.end() && visited.find(newWord) == visited.end()) {
                    queue.push({newWord, distance + 1}); // Distance goees by one why, because its a different level
                    visited.insert(newWord);
                    parent[newWord] = currentWord;  // Track parent for path reconstruction
                }
            }
        }
    }
    
    // No path found
    return 0;
}


int main() {

    
    // Setup the problem
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> dictionary = {"hot","dot","dog","lot","log","cog"};
    // "hit" -> "hot" -> "dot" -> "dog" -> "cog",

    // std::string beginWord = "dot";
    // std::string endWord = "cog";
    // std::vector<std::string> dictionary = {"hot","dot","dog","mit","log", "cog"};
    // Path: dot -> dog -> cog

    // TODO how do we go from string to chars
    // Question how do we use HashMaps here correctly

    int result = wordLadderBFS(beginWord, endWord, dictionary);

    std::cout <<"shortest path " << result << std::endl;

    return 0;
}
    


// ************************************



