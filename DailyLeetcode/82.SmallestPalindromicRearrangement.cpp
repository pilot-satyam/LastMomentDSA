#include<bits/stdc++.h>
using namespace std;

//Q : https://leetcode.com/problems/smallest-palindromic-rearrangement-i/?envType=daily-question&envId=2026-07-28

// Intuition:
// A palindrome reads the same forwards and backwards, so any valid rearrangement must place pairs
// of matching characters symmetrically around the center. To find the lexicographically smallest
// palindrome, build the left half using the smallest characters first, place any odd-count character
// in the middle, and mirror the left half for the right side.
// Approach:
// 1. Count frequency of each character using an ordered map.
// 2. For each character in ascending order, add floor(count/2) copies to the left half.
// 3. If a character has an odd count, append it to the middle string.
// 4. Mirror the left half to form the right half and concatenate left + middle + right.
// Dry run ("aaabbbb"):
//  counts: a=3, b=4
//  left = "abb" because a contributes 3/2 = 1 copy and b contributes 4/2 = 2 copies
//  middle = "a" (the one odd a), right = "bba"
//  result = "abb" + "a" + "bba" = "abbabba"
class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        } //a->2 b->3

        string left = "",right = "",middle="";
        for(auto &it : m){
            //appending the chars it.second/2 times
            left += string(it.second / 2, it.first);
            if(it.second %2 != 0){
                middle += it.first;
            }
        }
        right = left;
        reverse(right.begin(),right.end());
        return left+middle+right;
    }
};

// Approach 2:
// Intuition:
// The same palindrome construction applies, but frequency counting can be optimized with a fixed-size
// array because all letters are lowercase. This keeps the character order stable and avoids map overhead.
// Approach:
// 1. Count letters using a 26-element frequency array.
// 2. Build the left half from 'a' to 'z' using freq[i]/2 copies.
// 3. Collect any odd-count character for the middle.
// 4. Mirror the left half and return left + middle + right.
// Dry run ("aaabbbb"):
//  freq[a]=3, freq[b]=4
//  left = "abb", middle = "a", right = "bba"
//  output = "abbabba"
class Solution {
public:
    string smallestPalindrome(string s) {
        // map<char,int> m;
        vector<int> freq(26,0);
        for(char c : s){
            freq[c - 'a']++;
        }

        string left = "",right = "",middle="";
        for(int i=0;i<26;i++){
            left += string(freq[i]/2, 'a' + i);
            if(freq[i] % 2 != 0) middle += ('a'+i);
        }
        right = left;
        reverse(right.begin(),right.end());
        return left+middle+right;
    }
};

int main(){
    Solution s;
    string str = "aaabbbb";
    cout<<s.smallestPalindrome(str)<<endl;
    return 0;

}