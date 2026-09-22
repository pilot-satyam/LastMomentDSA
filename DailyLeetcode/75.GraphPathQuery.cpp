/**
 * 
*   Node 0 → value 1 
    Node 1 → value 3
    Node 2 → value 5
    Node 3 → value 8
    Node 4 → value 10
 * 
 */

 // Q : https://leetcode.com/problems/path-existence-queries-in-a-graph-i/?envType=daily-question&envId=2026-07-09

 /**
  * 
  * It has a very good concept of connected components.
  * We can assign a component number to each node based on the maxDiff condition.
  * Here we calculate the diff and if the diff is less than or equal to maxDiff, 
  * we assign the same component number to the next node.
  * If the diff is greater than maxDiff, we assign a new component number to the
  * 
  *so component array looks like this for the above example:
    component[0] = 0
    component[1] = 0
    component[2] = 0
    component[3] = 1
    component[4] = 1
    
    If there is no connectivity in component then we return false else true.
  */

 #include<bits/stdc++.h>
 using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<int> component(n);
        component[0] = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff) component[i] = component[i - 1];
            else component[i] = component[i - 1] + 1;
        }

        vector<bool> ans;

        for (auto q : queries) {
            int u = q[0];
            int v = q[1];
            ans.push_back(component[u] == component[v]);
        }

        return ans;
    }
};

int main() {
    Solution s;
    int n = 5;
    vector<int> nums = {1, 3, 5, 8, 10};
    int maxDiff = 2;
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {0, 4}};
    
    vector<bool> result = s.pathExistenceQueries(n, nums, maxDiff, queries);
    
    for (bool res : result) {
        cout << (res ? "true" : "false") << endl;
    }
    
    return 0;
}