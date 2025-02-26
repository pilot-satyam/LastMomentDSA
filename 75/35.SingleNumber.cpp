#include<bits/stdc++.h>
using namespace std;

/*
We loop through each element num in the array nums, and for each element, we apply result ^= num. 
This keeps updating result as we process each number.
After all the numbers are processed, the number that appears only once will remain in result 
because all the other numbers that appear twice will cancel each other out.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(auto it : nums){
            result ^= it;
        }
        return result;
    }
};

int main(){

}