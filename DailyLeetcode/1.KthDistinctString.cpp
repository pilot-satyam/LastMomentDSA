#include<bits/stdc++.h>
using namespace std;

/*
Ques: https://leetcode.com/problems/kth-distinct-string-in-an-array/?envType=daily-question&envId=2024-08-05
*/

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> m;
        vector<string> ans;
        
       for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
       }
        
        for (int i=0;i<arr.size();i++) {
            if (m[arr[i]] == 1) {
                ans.push_back(arr[i]);
            }
        }
        
        if (ans.size() < k) {
            return "";
        }
    
        return ans[k - 1];
    }
};

int main(){

}