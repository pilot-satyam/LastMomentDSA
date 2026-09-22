#include<bits/stdc++.h>
using namespace std;

// Q : https://leetcode.com/problems/image-overlap/description/?envType=daily-question&envId=2026-09-13

/***
 * IMPORTANT :
 * 
 * In C++, an std::unordered_map needs to know how to hash its keys. Out of the box, it knows how to handle basic types 
 * like int or string.However, it does not know how to use a pair of numbers like pair<int, int> as a key. If you try to 
 * write unordered_map<pair<int, int>, int>, your code will fail to compile unless you write a custom hashing function.
 * To avoid that headache, we smash our two numbers (r_shift and c_shift) into one single integer so the map can accept 
 * it easily.
 * 
 * How the Math Works (The 100x Trick)The problem statement guarantees that the size of the grid (\(N\)) will 
 * never be larger than 30.This means our row shifts and column shifts will always fall somewhere between -30 and +30.
 * Because 30 is a small number, multiplying the row shift by 100 acts like a separator that pushes it into the "hundreds 
 * place," leaving the "ones place" wide open for the column shift. This guarantees that no two different shifts will ever 
 * accidentally produce the same key.Look at these examples:
 * 
 * Example 1: Shift Down 2, Right 5r_shift = 2, c_shift = 5key = (2 * 100) + 5 = 205Example 2: Shift Down 5, 
 * Right 2r_shift = 5, c_shift = 2key = (5 * 100) + 2 = 502Example 3: Shift Up 3, Left 4 (Negative shifts)r_shift = -3, 
 * c_shift = -4key = (-3 * 100) + (-4) = -304Because we multiplied by 100, 205, 502, and -304 are all completely unique 
 * numbers. The map reads 205 and instantly knows it means exactly (2, 5).
 */


//Brute force : O(N^4) where N is the size of the image




//Optimised : O(K^2) where K is the number of 1s in the image

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> list1, list2;
        
        // Step 1: Store coordinates of all 1s
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (img1[r][c] == 1) list1.push_back({r, c});
                if (img2[r][c] == 1) list2.push_back({r, c});
            }
        }
        
        // Step 2: Map to keep track of how many pairs share the exact same shift
        unordered_map<int, int> shift_counts;
        int max_overlap = 0;
        
        // Step 3: Calculate the relative shift for every pair of 1s
        for (auto& p1 : list1) {
            for (auto& p2 : list2) {
                int r_shift = p2.first - p1.first;
                int c_shift = p2.second - p1.second;
                
                // Hash the 2D shift into a unique 1D key (since max N is 30, multiplying by 100 is safe)
                int shift_key = r_shift * 100 + c_shift;
                
                shift_counts[shift_key]++;
                max_overlap = max(max_overlap, shift_counts[shift_key]);
            }
        }
        
        return max_overlap;
    }
};

int main() {
    vector<vector<int>> img1 = {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    vector<vector<int>> img2 = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
    
    Solution solution;
    int result = solution.largestOverlap(img1, img2);
    
    cout << "Largest Overlap: " << result << endl; // Output: Largest Overlap: 3
    
    return 0;
}