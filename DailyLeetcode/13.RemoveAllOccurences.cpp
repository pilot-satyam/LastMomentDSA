#include<bits/stdc++.h>
using namespace std;

/**
 * Input: s = "daabcbaabcbc", part = "abc"
 *  Output: "dab"
 *  ans = dab
 */

class Solution {
public:
    string removeOccurrences(string s, string part) {
    size_t pos;
    while ((pos = s.find(part)) != string::npos) {
        s.erase(pos, part.length());
    }
    return s;
}
};

/**
 * @brief Using KMP: for pattern matching in O(N+M) and using LPS. If you will use normal matching pattern
 * then it will take quadratic time,
 * 
 */

class Solution {
public:
    short lps[1000]={0};
    // cpmpute lps for pattern
    void preKMP(const string& pattern, int pz) {
        for (int i=1, j=0; i<pz; i++) {
            while (j>0 && pattern[i]!=pattern[j]) 
                j=lps[j-1];
            lps[i]=(pattern[i]==pattern[j])?++j:j;
        }
    }

    string removeOccurrences(string& s, string& part) {
        const int pz=part.size(), n=s.size();
        preKMP(part, pz);
        string ans;
        vector<short> st;  // Store pattern index j
        st.reserve(n);
        int j=0;  // Current pattern index
        int az=0;
        for (char c : s) {
            ans.push_back(c);
            az++;
            // KMP matching 
            while (j>0 && c != part[j]) 
                j=lps[j-1];
            if (c==part[j]) 
                j++;
            st.push_back(j); // put j to st

            // Found part, remove it
            if (j==pz) {
                az-=pz;
                ans.resize(az);  // Remove last pz chars
                st.resize(az);  // Restore st
                
                // Backtrack j using st
                j=(az==0)?0:st.back();
            }
        }
        return ans;
    }
};

int main(){

}