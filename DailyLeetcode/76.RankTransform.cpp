// Q : https://leetcode.com/problems/rank-transform-of-an-array/?envType=daily-question&envId=2026-07-12 

/**
 * 
 * This problem is about rank transformation of an array. 
 * The idea is to assign ranks to the elements of the array based on their values. 
 * The smallest element gets the rank 1, the second smallest gets rank 2, and so on. 
 * If there are duplicate elements, they receive the same rank.
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> cp = arr;
        sort(cp.begin(),cp.end());
        unordered_map<int,int> m;
        int curRank = 1;
        for(auto it : cp){
            if(m.find(it) == m.end()){
                m[it] = curRank;
                curRank++;
            }
        }
        for(auto &it1 : arr){
            it1 = m[it1];
        }
        return arr;
    }
};

int main() {
    Solution s;
    vector<int> arr = {40,10,20,30};
    vector<int> ans = s.arrayRankTransform(arr);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}