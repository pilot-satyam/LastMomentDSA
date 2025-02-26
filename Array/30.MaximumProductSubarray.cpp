#include<bits/stdc++.h>
using namespace std; 

//1st optimal

/*
   1) Initially store 0th index value in prod1, prod2 and result.
   2) Traverse the array from 1st index. 
   3) For each element, update prod1 and prod2.
   4) Prod1 is maximum of current element, product of current element and prod1, product of current element and prod2
   5) Prod2 is minimum of current element, product of current element and prod1, product of current element and prod2
   6) Return maximum of result and prod1
*/

int maxProductSubArray(vector<int>& nums){
    int prod1 = nums[0], prod2 = nums[0], res = nums[0];
    for(int i=1;i<nums.size();i++){
        int temp = max({nums[i],prod1 * nums[i],prod2 * nums[i]});
        int prod2 = min({nums[i],prod1 * nums[i], prod2 * nums[i]}); // here we reqiuire min so that we can consider a case where 2 or more -ve integers are present
        prod1 = temp;
        res = max(res,prod1);   
    }
    return res;
}

// {1,2,-3,0,-4,-5}; prod1 = prod2 = res = 1
// temp = max({2,2,2}) ==> 2 , prod2 = min({2,2,2}) ==> 2  (i == 1) , prod1 == 2, res = max(1,2) = 2
// temp = max({-3,-6,-6}) ==> -3 , prod2  ==> -6 (i==2), prod1 = -3 , res = max(2,-3) = 2
// temp = max({0,0,0}) ==> 0, prod2 ==> min({0,0,0}) ==> 0 , prod1 = 0 (i == 3), res = max(2,0) = 2
// temp = max({-4,0,0}) ==> 0 , prod2 ==> min({-4,0,0}) ==> -4 , prod1 = 0 (i == 4), res = max(2,0) = 2
// temp = max({-5,0,0}) ==> 0, prod2 ==> min({-5,0,-20}) ==> 20, prod1 = 0 (i == 5), res = max(2,20) = 20



// 2nd Optimal
class Solution{
public:
    int maxProduct(vector<int>& nums){
        int pre = 1, suf = 1;
        int ans = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;
            pre = pre * a[i];
            suf = suf * a[n-i-1];
            ans = max(ans,max(pre,suf));
        }
        return ans;
    }

};

int main(){

}