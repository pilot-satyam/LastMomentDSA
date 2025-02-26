#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/tuple-with-same-product/?envType=daily-question&envId=2025-02-06

/**
 *  nums = [1,2,4,5,10]
 * 
 *  1 -> 1,2,4,5,10
 *  2 -> 8,10,20
 *  4 -> 20,40
 *  5 -> 50
 * 
 * 10 -> 2, 20 -> 2 
 * 
 * nums = [2,3,4,6]
 * 2 -> 6,8,12
 * 3 -> 12,18
 * 4 -> 24
 */

//here we get formula ==> remember we need to take 2 distinct pairs in order to match a particular product
//lets suppose (a,b,c,d) here we select a * b = c * d, so here we have 2 pairs (a,b) and (c,d)
//and internally these pair indidually can be arranged in 2 ways, so total 2 * 2 = 4 ways, so for 
//2 pairs we have 8 ways to select them.
//(a,b,c,d),(a,b,d,c),(b,a,c,d),(b,a,d,c),(c,d,a,b),(c,d,b,a),(d,c,a,b),(d,c,b,a)
// and initially we are selecting two pairs hence we can do using formula (nC2)
// so our formula becomes n * (n-1)/ 2 * 8

//Solved by self, pat on the back!
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int prod = nums[i] * nums[j];
                m[prod]++;
            }
        }
        for(auto it : m){
            int cnt = it.second;
            if(cnt > 1){
                ans  += (cnt * (cnt -1))/2 * 8;
            }
        }
        return ans;
    }
};

int main(){

}