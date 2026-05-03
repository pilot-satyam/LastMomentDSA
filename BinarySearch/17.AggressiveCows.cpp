#include<bits/stdc++.h>
using namespace std;

//Q : https://www.naukri.com/code360/problems/aggressive-cows_1082559?leftPanelTabValue=PROBLEM

/**

 Here problem says that we have to place all the given cows in such a way that distance between two
 cows must be maximum(among min distances).
 The basic idea is to test every possible distance between 1 and the difference between the farthest and
 nearest stalls. The largest distance for which canBePlaced() returns true will be our answer.

 Algo : Sort the stalls: Arrange the stalls in ascending order.
        Set the search range:
            Start with the smallest possible distance.
            The largest possible distance is the gap between the farthest and nearest stalls.
        Use Binary Search: Repeat the process until the search range is exhausted:
            Pick the middle distance: Test this distance as a possible answer.
            Check if it works:
                If it works: Try to increase the distance to see if a larger one is possible.
                If it doesn’t work: Decrease the distance and test smaller ones.

 */

bool canBePlaced(vector<int> &stalls, int cows, int distance){
    int cntCows = 1, lastPlacedCow = stalls[0];
    //starting from 1 since we have already considered cow at 0th index
    for(int i=1;i<stalls.size();i++){
        if(stalls[i] - lastPlacedCow >= distance){
            cntCows++;
            lastPlacedCow = stalls[i];
        }
        if(cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n-1] - stalls[0];
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(canBePlaced(stalls,k,mid) == true){
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}

int main(){
}