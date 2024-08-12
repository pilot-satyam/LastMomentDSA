#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxLen=0,maxFreq=0;
        // unordered_map<char,int> m;
        int m[26];
        memset(m,0,sizeof(m));
        while(r < s.size()){
            m[s[r] - 'A']++;
            maxFreq = max(maxFreq,m[s[r]-'A']);
            if((r-l+1) - maxFreq > k){
                m[s[l]-'A']--;
                maxFreq = 0;
                l++;
            }
            if((r-l+1) - maxFreq <= k){
                maxLen = max(maxLen,r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};

int main(){

}