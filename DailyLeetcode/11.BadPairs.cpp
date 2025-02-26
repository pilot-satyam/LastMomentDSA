#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/count-number-of-bad-pairs/?envType=daily-question&envId=2025-02-09

/**think it as reverse engineering, given eq : j - i != nums[j] - nums[i]
 * which can be written as nums[i] -i = nums[j] - j
 * then instead of using nested loops we can use hashmap to store the difference of nums[i] - i
 * then we will add it to goodPairs and in the end we will subtract it from total pairs,
 * total pairs will be nC2, hence it becomes nC2 - goodPairs
 */

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long,long long> m;
        long long n = nums.size(), goodPairs = 0;
        for(int i=0;i<n;i++){
            long long diff = nums[i] - i;
            goodPairs += m[diff]; //existing good pairs
            m[diff]++; //if not then insert
        }
        long long ans = (n*(n-1)/2) - goodPairs;
        return ans;
    }
};

int main(){

}