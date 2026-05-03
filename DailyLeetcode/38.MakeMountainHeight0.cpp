#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description/?envType=daily-question&envId=2026-03-03

/**
worker 0 -> w = 2
worker 1 -> w = 1
worker 2 -> w = 1

4 partitions

worker0:
w * x(x+1)/2
2 * (1*2)/2 = 2  (1 partition)

worker1:
1 * (2*3)/2 = 3  (2 partitions)

worker2:
1 * (1*2)/2 = 1  (1 partition)

Total time = max(2,3,1) = 3

so main question relies in finding x, to find x we need to answer the below question
How many layers can each worker remove in T seconds

w * x(x+1)/2 <= T
For each worker compute: max x where w * x(x+1)/2 ≤ T

x2 + x <= 2T/w
x2 + x - 2T/w = 0
roots = x = (-1 ± sqrt(1 + 8T/w)) / 2 {-b +_ √b2-4ac/2a}
we take positive value and then floor it : x = floor((sqrt(1 + 8*T/w) - 1) / 2)

*/


class Solution {

private:
    long long calculateLayer(long long T, int w){
        return (sqrt(1.0 + 8.0 * T / w) - 1) / 2;
    }

private:
    bool canFinish(int mountainHeight, vector<int>& workerTimes, long long T){
        long long totalLayers = 0;
        for(int i=0;i<workerTimes.size();i++){
            totalLayers += calculateLayer(T,workerTimes[i]);
            if(totalLayers >= mountainHeight) return true;
        }
        return false;
    }

public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low  = 0;
        long long high = 1e18;
        long long ans = high;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(canFinish(mountainHeight, workerTimes,mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> workers = {2, 1, 1};
    cout << s.minNumberOfSeconds(4, workers) << endl;
}