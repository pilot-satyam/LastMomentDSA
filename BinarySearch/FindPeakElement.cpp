##include<bits/stdc++.h>
using namespace std;

/**

Q : https://leetcode.com/problems/find-peak-element/

A : Intuition is that like previous problem we have to compare here, so since we have to compare we will start from
    second and second last index. So we will first handle case for the first and last element.

    Peak element means the element should be greater than it's left element and right element, so we will use BS and
    check if mid satisfies our criteria (since mid always lie on peak or bottom) then return mid nahi to if an element before mid is lesser than mid then it's peak
    will also lie in right half because mid bhi to us element ke right mein hai. Hence we will increase low = mid + 1;
    Else the peak will lie in left and so we shift high = mid - 1; this last case also covers a case where mid element is
    lower than it's left and right element (in this case peak is either side and hence we can choose to move left)

*/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int low = 1;
        int high = n - 2;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1]) return mid;
            else if(nums[mid] > nums[mid-1]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};

int main(){
}