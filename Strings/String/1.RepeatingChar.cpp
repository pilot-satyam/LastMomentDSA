#include<bits/stdc++.h>
using namespace std;

/**
 * 
 * Idea, is to use two pointer along with map/set tp track characters in current substr, 
 * 1)for each char if it is not in set add it and move the right pointer
 * 2)if it's already present then remove chars from start until duplicate is removed
 */

int lengthOfLongestSubstring(string s){
    unordered_set<char> st;
    int maxLength = 0, l = 0;
    for(int r=0;r<s.length();r++){
        while(st.find(s[r]) != st.end()){
            st.erase(s[l]);
            l++; //increasing the counter since duplicate has been found
        }
        st.insert(s[r]);
        maxLength = max(maxLength,r-l+1);
    }
    return maxLength;
}

// using character array s.c --> O(26)


int longestSubstringWithoutRepeatingCharacters(const string& s) {
    int charIndex[26];  // Array to store the most recent index of each character
    fill(begin(charIndex), end(charIndex), -1);  // Initialize all indices to -1 (indicating no characters seen yet)
    
    int maxLength = 0;
    int start = 0;  // Left boundary of the sliding window

    for (int end = 0; end < s.length(); ++end) {
        char currentChar = s[end];
        int charIndexInArray = currentChar - 'a';  // Map char to array index (0 for 'a', 1 for 'b', ..., 25 for 'z')
        
        // If the character was seen before and is within the current window
        if (charIndex[charIndexInArray] >= start) {
            // Move the start of the window right past the last occurrence of the repeating character
            start = charIndex[charIndexInArray] + 1;
        }
        
        // Update the most recent index of the current character
        charIndex[charIndexInArray] = end;

        // Update the max length of the substring
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "Longest substring without repeating characters: " 
         << longestSubstringWithoutRepeatingCharacters(s) << endl;
    return 0;
}
