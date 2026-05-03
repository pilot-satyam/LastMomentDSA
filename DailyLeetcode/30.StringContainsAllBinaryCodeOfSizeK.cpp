#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/?envType=daily-question&envId=2026-02-19 

/**
 * 
 * If problem says:

    “Check every substring of size k”

    Immediately think:

    for(i = 0; i <= n - k; i++)

    Why n - k ?

        Suppose:

        s = "00110110"
        n = 8
        k = 2

        We want substrings of length 2.

        Now ask yourself:

        👉 What is the last index where a substring of size 2 can START?

        If substring length = k
        Starting index = i
        Ending index = i + k - 1

        This must be valid:

        i + k - 1 < n

        Solve it:

        i ≤ n - k

        That’s why we write:

        for(int i = 0; i <= n - k; i++)
 *
 * 
 */

class Solution {

private:
    // Approach 1: Brute Force using Substrings
    // Intuition:
    // - For every substring of length k in the string, insert it into a set.
    // - If the set size equals 2^k, all possible binary codes of size k are present.
    // - Simple but not optimal for large k, as substring creation is costly.
    bool checkBinary(string s, int k){
        int n = s.size();
        int left = 0;
        unordered_set<string> st;
        for(int i=0;i<=n-k;i++){
            string sub = s.substr(i,k);
            st.insert(sub);
        }
        if(st.size() == pow(2,k)) return true;
        return false;
    }

// public:
//     bool hasAllCodes(string s, int k) {
//         return checkBinary(s,k);
//     }
public:
    // Approach 2: Rolling Hash (Optimal)
    // Intuition:
    // - Treat each substring of length k as a binary number and use a rolling hash to avoid substring creation.
    // - Use a bitmask to keep only the last k bits as we iterate.
    // - Insert each number into a set; if set size equals 2^k, all codes are present.
    // - Much faster for large k, avoids string operations.
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        
        if (n - k + 1 < (1 << k)) 
            return false;

        unordered_set<int> st;
        int num = 0;
        int mask = (1 << k) - 1;

        for (int i = 0; i < n; i++) {
            num = ((num << 1) & mask) | (s[i] - '0');

            if (i >= k - 1) {
                st.insert(num);
            }
        }

        return st.size() == (1 << k);
    }

};

int main(){
    Solution sol;
    string s = "00110110";
    int k = 2;
    cout << sol.hasAllCodes(s, k) << endl; // Output: true
    return 0;
}