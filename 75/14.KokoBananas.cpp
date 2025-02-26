#include<bits/stdc++.h>
using namespace std;

// https://takeuforward.org/binary-search/koko-eating-bananas/

class Solution {
private:
    long long calculateTotalHours(vector<int>& piles, long long mid){
        long long totalH = 0;
        long long n = piles.size();
        for(long long i=0;i<n;i++){
            totalH += ceil((double)piles[i]/(double)mid);
        }
        return totalH;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1, high = *max_element(piles.begin(),piles.end());
        while(low <= high){
            long long mid = low + (high-low)/2;
            long long totalH = calculateTotalHours(piles,mid);
            if(totalH <= h) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};

/**
 * Complexity Analysis

    Time Complexity: O(N * log(max(a[]))), where max(a[]) is the maximum element in the array and N = size of the array.
    Reason: We are applying Binary search for the range [1, max(a[])], and for every value of ‘mid’, we are traversing the entire array inside the function named calculateTotalHours().

    Space Complexity: O(1) as we are not using any extra space to solve this problem.
 */

int main(){

}