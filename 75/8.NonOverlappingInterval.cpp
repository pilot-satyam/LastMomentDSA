#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/non-overlapping-intervals/description/?envType=study-plan-v2&envId=leetcode-75

/**
 * Approach
1)We sort the intervals based on their end times in ascending order. This allows us to always consider the interval that finishes the earliest, making it easier to avoid overlap with future intervals.

2)Greedy Selection:

We initialize prevHigherRange to the end time of the first interval.
Then, we iterate through the intervals starting from the second one. If the current interval starts before prevHigherRange, it means it overlaps with the previous selected interval, so we increment the count of intervals to be removed.

If it doesn't overlap (i.e., it starts after prevHigherRange), we update prevHigherRange to the current interval's end time and continue.

3)Count the intervals to remove: The goal is to count how many intervals need to be removed.
 */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //sorting
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });

        int cnt = 0;
        int prevHigherRange = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] < prevHigherRange){
                //it should come in prev range, hence delete it hence overlapping
                cnt++;
            }
            else{
                //now increment the higherRange for next comparison of elements
                prevHigherRange = intervals[i][1];
            }
        }   
    return cnt;
    }
};

int main(){

}