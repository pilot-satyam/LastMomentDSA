#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), maxlen = 0;
        int l = 0, r = 0;
        int hash[255];
        memset(hash, -1, sizeof(hash));
        while (r < n) {
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }
            hash[s[r]] = r;
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};

/*
Checking for Repeating Characters:
if (hash[s[r]] != -1 && hash[s[r]] >= l): If the character at position r has been seen before (hash[s[r]] != -1) and the last occurrence is within the current window (hash[s[r]] >= l), it means there's a repeating character within the current window.
l = hash[s[r]] + 1: Move the left pointer l to the position right after the last occurrence of the current character to exclude the repeating character.
*/

int main(){

}