// Q : https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/?envType=daily-question&envId=2026-06-01

#include<bitstd/stdc++.h>
using namespace std;

/**

9 7 6 5 2 2

*/

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int ans = 0;
        sort(cost.begin(),cost.end(),greater<int>());
        for(int i=0;i<n;i+=3){
            ans += cost[i];
            if(i+1 < n) ans += cost[i+1]; 
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> cost1 = {1, 2, 3};
    cout << sol.minimumCost(cost1) << endl; // Expected output: 5

    vector<int> cost2 = {6, 5, 7, 9, 2, 2};
    cout << sol.minimumCost(cost2) << endl; // Expected output: 23

    vector<int> cost3 = {5, 5};
    cout << sol.minimumCost(cost3) << endl; // Expected output: 10

    return 0;
}