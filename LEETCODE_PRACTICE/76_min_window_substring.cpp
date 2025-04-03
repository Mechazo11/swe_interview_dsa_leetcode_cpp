#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers
#include <cmath> // Math library
#include <unordered_set>
#include <unordered_map>

/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).


If there is no such window in S that covers all characters in T, return the empty string "". {edge case}

If there is such window, you are guaranteed that there will always be only one unique minimum window in S.


- As O(n) is needed, we will use the Two pointer method
- The minumum window is guranteed to be always one
- we can convert the given T into an unorderd_set T_set and then maintian a running set that will check if all the elements in 
- T_set is present in the current substring. If yes, return the string, if not, continue
- If loop ends, return blank string
- the reults should be BANC
- this means the current number of character must be same as the number of characters in T.
- we can initialzie a hashmap for known keys using a range based for loop
- we assume number of characters in T i.e M is less than Input string S so that time complexity O(N) > O(M)

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"

-- Uses the simple concept of counting frquencies of unique charcter in target that appears in the minimum window of S_in

*/

std::string minWindow(std::string &S_in, std::string &T_in) {
    
    // Handle edge case
    if (T_in.empty() || S_in.empty()) {
        return "";
    }
    
    // Define some work variables
    std::string outStr = "";
    int left_ptr = 0;
    int right_ptr = 0;
    
    std::unordered_map<char, int> countT;
    std::unordered_map<char, int> currentWindow;
    
    // Initialize frequency map for T_in
    // All these characters will have a value of 1
    for (char c : T_in) {
        countT[c]++;
    }
    
    int matched = 0;
    int required_matches = countT.size();
    
    // Slide window through S
    while (right_ptr < S_in.length()) {
        char current_char = S_in[right_ptr];
        
        // If current character is in T
        if (countT.find(current_char) != countT.end()) {
            // Add this character's count up in currentWindow hashmap
            currentWindow[current_char]++;
            
            // the current character is a valid match, so count up how many matched character we got.
            if (currentWindow[current_char] <= countT[current_char]) {
                matched++;
            }
            
            // Try to minimize window when all characters matched
            while (matched == required_matches) {
                int windowLen = right_ptr - left_ptr + 1; // inclusive counting
                
                // Form the current output string.
                if (outStr.empty() || windowLen < outStr.length()) {
                    outStr = S_in.substr(left_ptr, windowLen);
                }
                
                // Shrink from left
                char leftChar = S_in[left_ptr];
                if (countT.find(leftChar) != countT.end()) {
                    currentWindow[leftChar]--; // Reduce the leftmost character's frequency by 1.
                    // Reduced matched 
                    if (currentWindow[leftChar] < countT[leftChar]) {
                        matched--;
                    }
                }
                
                left_ptr++; // Move left pointer by one step
            }
        }
        
        right_ptr++;
    }
    
    return outStr;
}


int main() {

    std::string in_S = "ADOBECODEBANC";
    std::string in_T = "ABCE";
    // std::string in_T = "";
    
    std::string minStr = minWindow(in_S, in_T);

    std::cout << "minumum window substring: " << minStr << std::endl;

    return 0;
}
    


// ************************************



