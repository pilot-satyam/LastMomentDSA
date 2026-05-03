#include<bits/stdc++.h>
using namespace std;

/**

https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

A : Intuition here is same as previous example, only difference is being that we have to take acount of consequtive bloomed floweers
    ** We make consequtiveBloomedFlowers = 0, since we might have encoutered a case where we were counting all the bloomed
       flowers, but suddenly a non bloomed flower appears, hence we need to restart the count again after calculating
       previous set/ Like this eg :

       Imagine we have flowers that bloom on: [1, 2, 3, 100, 5, 6, 7] and we need k=2 consecutive flowers per bouquet.
       Scenario 1: Non-bloomed flower breaks the sequence

       for(int i = 0; i < v.size(); i++){
           if(v[i] <= day){
               cnt++;  // Flower bloomed, add to count
           }
           else{
               noOfBouqet += (cnt / k);  // FIRST TIME: flower hasn't bloomed
               cnt = 0;  // Reset for next sequence
           }
       }
       ```

       Let's trace with `day = 10`:
       ```
       i=0: v[0]=1 ≤ 10   → cnt=1 (bloomed)
       i=1: v[1]=2 ≤ 10   → cnt=2 (bloomed)
       i=2: v[2]=3 ≤ 10   → cnt=3 (bloomed)
       i=3: v[3]=100 > 10 → BREAKS SEQUENCE!
            noOfBouqet += (3/2) = 1 bouquet made
            cnt = 0 (reset for next sequence)
       i=4: v[4]=5 ≤ 10   → cnt=1 (new sequence starts)
       i=5: v[5]=6 ≤ 10   → cnt=2 (bloomed)
       i=6: v[6]=7 ≤ 10   → cnt=3 (bloomed)
       Loop ends...

       Scenario 2: What happens after the loop ends?
       After the loop, we still have cnt=3 flowers from the last sequence that hasn't been counted yet!

       noOfBouqet += (cnt / k);  // SECOND TIME: count remaining flowers
       ```

       If we **don't** do this second line:
       ```
       noOfBouqet = 1 (only counted first sequence)
       But we have 3 more bloomed flowers at the end!
       We'd get WRONG answer.
       ```

       If we **do** this second line:
       ```
       noOfBouqet = 1 + (3/2) = 2 bouquets total
       CORRECT answer!
       ```

       ## **Visual Explanation**
       ```
       Flowers: [1, 2, 3, 100, 5, 6, 7]
       Day 10:  [✓, ✓, ✓,  X, ✓, ✓, ✓]

       Sequence 1: [✓, ✓, ✓]  → 3/2 = 1 bouquet (counted in loop)
       Sequence 2: [✓, ✓, ✓]  → 3/2 = 1 bouquet (counted AFTER loop)

       Total: 2 bouquets
    */

class Solution {

private:
    int solve(vector<int> &v, int day, int m, int k){
        int noOfBouqet = 0;
        int consequtiveBloomedFlowers = 0;
        for(int i=0;i<v.size();i++){
            //if it has bloomed, taking all consecutive flowers
            if(v[i] <= day){
                consequtiveBloomedFlowers++;
            }
            else{
                noOfBouqet += (consequtiveBloomedFlowers / k);
                consequtiveBloomedFlowers = 0; //making it 0 again to handle case where the flowe hasn't blommed yet
            }
        }
        noOfBouqet += (consequtiveBloomedFlowers / k);
        return noOfBouqet >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        //since we are multiplying an integer it might overflow, hence convert into long long
        long long val = m * 1LL * k * 1LL;
        if( val > n) return -1;

        // for BS minimum element of array will be low and highest element will be high
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i=0;i<n;i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        //BS starts here

        int low = mini, high = maxi;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(solve(bloomDay,mid,m,k)){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};

int main(){
}