#include<bitstdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int mini1 = INT_MAX;
        int mini2 = INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(nums[i] < mini1){
                mini2 = mini1; //doing this since if any new value find new smaller than mini1, old mini1 will become mini2 and smaller will be mini1
                mini1 = nums[i];
            }
            else if(nums[i] < mini2){
                mini2 = nums[i];
            }
        }
        return nums[0] + mini1 + mini2;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {5,2,4,3};
    cout << sol.minimumCost(nums) << endl;
    return 0;
}