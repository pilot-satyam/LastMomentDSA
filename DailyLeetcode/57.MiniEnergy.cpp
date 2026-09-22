#include<bitstd/c++.h>
using namespace std;

//Q : https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/solutions/8196881/solution-by-la_castille-oska/?envType=daily-question&envId=2026-05-12 

// /**

// we will use Binary search over here and we check if we can perform
// all the task for certain energy then we will look smaller than it.
// Also since we want mini we will first sort so that energy gap is mini
// since we want to waste energy. eg. [1,100] ==> to we are left with 99 and 
// consuming very little that is 1 kcal energy rest 99 remains waste.

// */

// class Solution {

// private: 
//     bool canFinish(vector<vector<int>> &tasks, int energy){
//         for(auto it : tasks){
//             int actual = it[0];
//             int mini = it[1];
//             if(energy < mini) return false;
//             energy -= actual;
//         }
//         return true;
//     }

// public:
//     int minimumEffort(vector<vector<int>>& tasks) {
//         int n = tasks.size();
//         sort(tasks.begin(), tasks.end(),
//             [](auto &a, auto &b){
//                 return(a[1] - a[0]) > (b[1] - b[0]);
//         });      

//         // int low = 1;
//         // int high = 1e9;
//         // while(low<high){
//         //     int mid = low + (high - low)/2;
//         //     if(canFinish(tasks,mid)){
//         //         high = mid;
//         //     }
//         //     else{
//         //         low = mid + 1;
//         //     }
//         // }

//         // return low;

///// ----------------- GREEDY ------------------

//          int ans = 0;
//         int spent = 0;

//         for (auto &task : tasks) {

//             int actual = task[0];
//             int minimum = task[1];

//             ans = max(ans, spent + minimum);

//             spent += actual;
//         }

//         return ans;

//     }
// };

// ---------------- IMPROVED GREEDY ----------------------------

class Solution {
public:
    int minimumEffort(vector<vector<int>>& shop) {
        sort(shop.begin(), shop.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] - a[0] > b[1] - b[0];
        });

        int start = shop[0][1];
        int bal = shop[0][1] - shop[0][0];
        int loan = 0;

        for (int i = 1; i < shop.size(); i++) {
            int cost = shop[i][0];
            int thresh = shop[i][1];

            if (bal < thresh) {
                loan += thresh - bal;
                bal = thresh;
            }

            bal -= cost;
        }

        return start + loan;
    }
};

int main(){

}