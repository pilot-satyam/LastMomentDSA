#include<bit/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/daily-temperatures/description/?envType=study-plan-v2&envId=leetcode-75
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int mini = 0;
        int n = temperatures.size();
        vector<int> ans(n,0);
        int cnt = 0;
           for(int j = 0;j<n;j++){
            while(!st.empty() and temperatures[j] > temperatures[st.top()]){
               int i = st.top();
               st.pop();
               ans[i] = j - i; // 1 - 0 ==> 40 - 30
            }
            st.push(j);
        }
        return ans;
    }
};

int main(){

}