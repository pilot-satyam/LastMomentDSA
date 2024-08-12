#include<bits/stdc++.h>
using namespace std;

/*
Ques : https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
*/

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    int left=0, right=0, maxLen=-1;
    unordered_map<char,int> m;
    while(right<s.size()){
        m[s[right]]++;
        if(m.size() > k){
            m[s[left]]--;
            if(m[s[left]] == 0){
                m.erase(s[left]);
            }
            left++;
        }
        if(m.size() == k){
            maxLen = max(maxLen,right-left+1);
        }
        right++;
    }
    return maxLen;
    }
};

int main(){

}