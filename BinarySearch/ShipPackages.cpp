#include<bits/stdc++.h>
using namespace std;

//Q : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

/**

Intuition here is that minimum we require array(max) element since the summation of the whole array will either be equal
or greater than this  element. Hence our range would be from [maxElement , Summation]. Now we have to find capacity of the
ship. To find the capacity we will use `load + weights[i]` since initially the load will be 0 and with each iteration we
will increase the load and when it exceeds certain capacity then we will carry current array element to the next day,
hence we will increase the day as well.

*/

class Solution {

private:
    int solve(vector<int> &weights, int capacity){
        int load = 0, days = 1;
        for(int i=0;i<weights.size();i++){
            if(load + weights[i] > capacity){
                days += 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(solve(weights,mid) <= days) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};

int main(){
}