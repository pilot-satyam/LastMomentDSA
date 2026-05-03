#include <bits/stdc++.h>
using namespace std;

/**

Why use modulo % letters.size()?
This handles the wrap-around case. If no character in the array is greater than target, then low will equal letters.size() (past the last element). The modulo operator wraps it back to index 0.

letters = ['c', 'f', 'j']
target = 'j'

Binary search finds no character > 'j'
low ends up = 3 (out of bounds)

letters[low % letters.size()] 
= letters[3 % 3] 
= letters[0] 
= 'c'  ✓ Correct! Wrap around to the first letter

 */

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(letters[mid] > target){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return letters[low % letters.size()];
    }
};

int main(){
    Solution sol;
    vector<char> letters = {'c','f','j'};
    char target = 'a';
    cout << sol.nextGreatestLetter(letters, target) << endl;
    return 0;
}