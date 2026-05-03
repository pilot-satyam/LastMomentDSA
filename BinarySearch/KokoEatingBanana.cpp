#include<bits/stdc++.h>
using namespace std;

// Q : https://leetcode.com/problems/koko-eating-bananas/description/

/**

Again here the intuition here is to use binary search, since it is a range based problem.
[3,6,7,11], h = 8

so here we first divide and take ceil to check whether it is <= h, if it is in the range we proceed ahead.
Since we need to find the least time taken an idea here is to divide it with the largest element in the array since it would
be taking an hour only for that case. Like here if take first ans = 11 then total time would be
==> [3/11] + [6/11] + [7/11] + [11/11] ==> 1 + 1 + 1 + 1 ==> 4, above 11 anything will take same time hence our
upper limit is 11 and minimum we can take 1, then our range becomes [1,11]. And then we can continue with our BS
by eliminating the half's which we no longer require.

Make Sure to use "double" since in case of irrational fraction we would have to return ceil.

*/

class Solution {

private:
    int findMax(vector<int> &v){
        int maxi = INT_MIN;
        int n = v.size();
        for(int i=0;i<n;i++){
            maxi = max(maxi,v[i]);
        }
        return maxi;
    }

private:
    long long calculateRate(vector<int> &piles, long long n, long long mid){
        long long totalHour = 0;
        for(long long i=0;i<n;i++){
            totalHour += ceil((double)piles[i]/(double)mid);
        }
        return totalHour;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long n = piles.size();
        long long low = 1, high = findMax(piles);
        while(low <= high){
            long long mid = low + (high - low)/2;
            long long minHours = calculateRate(piles,n,mid);
            if(minHours <= h) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }

    /**
    You can also use answer variable like this:

    int minEatingSpeed(vector<int>& piles, int h) {
            long long n = piles.size();
            long long low = 1, high = findMax(piles);
            int ans = 1;
            while(low <= high){
                long long mid = low + (high - low)/2;
                long long minHours = calculateRate(piles,n,mid);
                if(minHours <= h){
                    ans = mid;
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            return ans;
    }

    */
};

int main(){
}