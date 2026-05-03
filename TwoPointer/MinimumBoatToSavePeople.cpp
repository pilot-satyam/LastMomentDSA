#include<bits/stdc++.h>
using namespace std;

//Ques: https://leetcode.com/problems/boats-to-save-people/description/

//As we know in two pointer if the result is greater than the target we 
// move the right pointer to left to reduce the sum
//else we move the left pointer to right to increase the sum

//This is greedy approach as we are trying to fit the heaviest person with the lightest person
//to minimize the number of boats used
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();
        int left = 0, right = n-1;
        int cnt = 0;
        while(left <= right){
            //since our strategy is to pick lightest and heaviest
            if(people[left] + people[right] <= limit){
                cnt++;
                left++;
                right--;
            }
            else{
                cnt++;
                right--;
            }
        }
        return cnt;
    }
};

int main(){
    Solution sol;
    vector<int> people = {3,2,2,1};
    int limit = 3;
    cout << sol.numRescueBoats(people, limit) << endl;
    return 0;
}