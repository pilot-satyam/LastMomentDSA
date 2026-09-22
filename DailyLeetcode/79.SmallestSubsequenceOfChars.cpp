// Q : https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/?envType=daily-question&envId=2026-07-19

#include<bits/stdc++.h>
using namespace std;

/**
 * Problem: Smallest Subsequence of Distinct Characters (LeetCode)
 *
/*
Approach (Greedy + Stack)

Observation:
1. We need each distinct character exactly once.
2. Result must be lexicographically smallest.
3. A larger character can be removed only if it appears again later.

Data Structures:
1. freq[char]  -> Remaining occurrences of each character.
2. inAnswer    -> Whether a character is already present in the answer.
3. string ans  -> Acts as a stack.

Algorithm:
1. Count frequency of every character.
2. Traverse the string:
   - Decrease current character's frequency.
   - If already in answer, skip it.
   - While:
        ans is not empty &&
        ans.back() > current &&
        ans.back() appears later (freq > 0)
     -> pop ans.back() and mark it as not present.
   - Push current character and mark it as present.
3. Return ans.

Why Greedy Works?
- Removing a larger character makes the answer smaller lexicographically.
- We remove it only if it appears again later, so no distinct character is lost.
- The while loop ensures all removable larger characters are discarded.

Time Complexity: O(n)
Space Complexity: O(26) = O(1) for lowercase English letters.

*/

class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int> m;
        unordered_set<char> st;
        string ans = "";
        for(int i=0;i<s.size();i++){
            m[s[i]]++; // b -> 2 c-> 2 a->1
        }
        for(int i=0;i<s.size();i++){
            char curr = s[i];
            m[curr]--;
            if(st.count(curr)) continue; //since already in the answer
            while(!ans.empty() and ans.back() > curr and m[ans.back()] > 0){
                st.erase(ans.back());
                ans.pop_back();
            }
            ans.push_back(curr);
            st.insert(curr);
        }
        return ans;
    }
};

int main(){
    Solution s;
    string str = "bcabc";
    cout<<s.smallestSubsequence(str);
}