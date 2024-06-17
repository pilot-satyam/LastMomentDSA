#include<bits/stdc++.h>
using namespace std; 

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