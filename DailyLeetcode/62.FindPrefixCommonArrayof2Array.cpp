// Q : https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/?envType=daily-question&envId=2026-05-20 

#include<bits/stdc++.h>
using namespace std;

/**
 *  Since A and B are permutations, each number appears exactly once in each array.
    Increase frequency of A[i] and B[i].
    Whenever freq[x] becomes 2, it means x has appeared in both prefixes,
    so increase common count.
 */

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int,int> m;
        int common = 0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            m[A[i]]++; 
            if(m[A[i]] == 2)
                common++;
            m[B[i]]++;
            if(m[B[i]] == 2)
                common++;
            ans.push_back(common);
        }
        return ans;
    }
};

int main(){
    
}