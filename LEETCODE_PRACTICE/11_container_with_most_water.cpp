#include <iostream> // Provide input output stream (essentially )
#include <vector> // implements dynamic array
#include <string> // string handling functionality
#include <algorithm> // various algorithms like sort(), find() etc.
#include <memory> // Smart pointers
#include <cmath> // Math library
#include <unordered_set>

/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49. 
*/

/*
    - lets assume X axis coordinates corresponds to 0 1 2 3 for each of those gives lines. This means we can map height 1 to a 
    - we assume no water spiils over beyond the two red borders
    - depth is unity
    - we need an O(n) problem
    - the problem configuration clearly indicates the minimum height is the limiting factor, so we only need to move left pointer and ensure the
    - left height is not longer than the right height
    - is the max volume possible fixed for this problem or do we need to compute the possible max volume apriori


*/

int maxVolContainer (std::vector<int> &heights, int &idx1, int &idx2){

// Intialize some work variables
int left = 0;
int right = heights.size() - 1;
int maxWater = 0; // book keeper

/*
    Edge cases
    - What if no heights are given
    - What happens if all heights are same
    - 
*/

// Output variable
std::vector<int> outLines;

// Main algorithm
for (;left < right; )
{

    // Calculate current area
    int width = right - left;
    int minHeight = std::min(heights[left], heights[right]);
    int currentWaterArea = width * minHeight;
    
    // Update maximum
    if (currentWaterArea > maxWater) {
        // This is current maximum
        maxWater = currentWaterArea; // update for next run
        idx1 = left;
        idx2 = right;
        // Store the indicies to the two lines
    }
    else {
        // No update
    }
    
    // Move the pointer with smaller height
    if (heights[left] < heights[right]) {
        left++;
    } else {
        right--;
    }

}

return maxWater;

}

int main() {

    // std::vector<int> in_lines =  {1,8,6,2,5,4,8,3,7};
    std::vector<int> in_lines =  {1,3,5,7,9};
    // std::vector<int> in_lines =  {1,9,2,8,6};
    
    // There two are my output variables
    int max_idx1 = 0;
    int max_idx2 = 0;

    int max_vol = maxVolContainer(in_lines, max_idx1, max_idx2);

    std::cout << "maximum volume: " << max_vol << " line1: " <<in_lines.at(max_idx1) << " line2: " << in_lines.at(max_idx2) << std::endl;
    
    return 0;
}
    


// ************************************



