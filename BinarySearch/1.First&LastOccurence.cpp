#include<bits/stdc++.h>
using namespace std;

/*
    1) We will use Binary search, and in single pass we cannot get hence we will require 2 pass

*/

private:
int firstOccurence(vector<int> &nums, int target){
    int low = 0;
    int high = nums.size()-1;
    int first = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target) {
            first = mid; //first occurence is here
            high = mid - 1; // searching in left space
        }
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return first;
}

private:
int lastOccurence(vector<int> &nums, int target){
    int last = -1;
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target){
            last = mid;
            low = mid + 1; //searching in the right space
        }
        else if (nums[mid] < target) low = mid + 1;
        else high = mid -1;
    }
    return last;
}

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccur = firstOccurence(nums, target);
        int lastOccur = lastOccurence(nums, target);
        vector<int> ans(2,-1); //since there will always 2 parameters to return
        //just optimizing the code, if first == -1, it means second occurrence will not be there
        // hence we will be saving O(log(n)) call here, if we don't do this rest of the code will still work fine
        // but optimizing this will give you an advantage in interviews
        if(firstOccur == -1){
            return ans;
        }
        ans[0] = firstOccur;
        ans[1] = lastOccur;
        return ans;
    }
};
int main(){

}