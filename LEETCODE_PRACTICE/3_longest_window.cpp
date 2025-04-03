#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers
#include <cmath> // Math library
#include <unordered_set>

/*
Given a string, find the length of the longest substring without repeating characters. 

Requires 

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
             The reason is "pwke" requires taking 'p', then 'w', then 'k', then 'e', 
             but skipping the second 'w' - making it a subsequence, not a substring -- Credit Claude Sonnet 3.7


We move two pointers both in left to right and then keep count of the character's unique appearance

The idea is very simple. Both left and right pointers starts at 0. Move right pointer by 1.
If the character is new, add it to the unordered set. Then check using `find` if the character exsists anywhere
If yes, remove the character pointed by the left pointer, and increment the pointer by 1.
Repeat the process until right pointer > str.length() i.e. falls out of the size


We use unordered_set since it's average time complexity is O(1) making it most suitable for these problems


*/

int lenString(std::string &str_in) {
    // Returns length of longest substring without repeating characters

    // Sliding window, both pointers are at head, one moves until the other is needed.
    // In constrat for cycle detection in linkedlists, we use Floyd's technique

    int left = 0;
    int right = 0;
    std::string longest = "";
    std::unordered_set<char> current_window; 
    
    // This logic states the right pointer will keep moving until it goes out of bound
    while (right < str_in.length()) {
        // Is this character ABSENT in the current_window set
        
        // This states find has reached the end of the 
        if (current_window.find(str_in[right]) == current_window.end()) {
            
            // This character not found yet, add it to the unordered set
            current_window.insert(str_in[right]);
            
            // longest keeps track of the longest string we have found, we can optionally keep track of it
            // Update longest if current is longer
            std::string current = str_in.substr(left, right - left + 1); // string substitution

            if (current.length() > longest.length()) {
                longest = current;
            }
            
            right++; // Advance right pointer by one character
        } else {
            // This character is already there and was added at the very beginning
            // Found duplicate remove from head
            current_window.erase(str_in[left]);
            left++;
        }
    }

    std::cout << "longest substring: " <<longest << std::endl;
    
    return longest.length();
}


int main() {

    // std::string str_in = "bbbbb";
    std::string str_in = "abcabcbb";
    // std::string str_in = "adcbabca"; // Answer "adcb" i.e. 4
    int result = lenString(str_in);
    std::cout << "longest unique substring: " <<result << std::endl;
    
    return 0;
}
    


// ************************************



