#include <bits/stdc++.h>
using namespace std;

/*
Quest: To find the longest subarray with sum k
*/

/*
REMEMBER: When ever you need to generate subarray in that case put both pointer i and j at 0th idx,
because single element is also a subarray, after considering it move the j forward until the end of array,
next move the i pointer to 1st idx and so on so that next subarray can be created and repeat the same procedure
*/

/*
Sol: 
BRUTE: 
1)Generate all subarray and then match the condition

int sum = 0,maxi=0;
for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        for(int k=i;k<n;k++){
            sum+=a[k];
            if(sum == k)
            {maxi = max(maxi,j-i+1);} // j-i+1 since we want the length of the subarray
        }
    }
}

further optimizing BRUTE: Since for every subarray we are summing the next element, so we don't require the k loop
    so simply we can do something like this  ===> for(i..){for(j...) {sum+=a[j]}}

BETTER SOLN: To use HashMap ---> Write in Notebook --> Why are we exactly using HashMap? 



*/


/*
Q2. Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
LinK : https://leetcode.com/problems/subarray-sum-equals-k/description/
*/

// Soln 

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> m;
    int sum = 0, count = 0;
    m[0] = 1; // Consider the case when sum - k = 0 ==> sum = k 
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        int rem = sum - k;
        if (m.find(rem) != m.end()) {
            count += m[rem]; //sum - rem = k. If such a sum exists, 
            //it means that there are subarrays whose sum equals k. 
            //The value m[rem] represents the number of occurrences of rem in the array up to the current index i. 
            //By adding m[rem] to the count, you're 
            //adding the number of subarrays ending at index i whose sum equals k.
        }
        m[sum]++; 
        //  keeps track of the frequency of sum encountered so far,
        //  which will be used in subsequent iterations to determine 
        // if there are more subarrays whose sum equals k.
    }
    return count;
}
/*
   if(sum == k){
                count++;
                m.insert({sum,i});
            }
    this will not work because You're only considering subarrays 
    ending at the current index i. However, you need
     to consider all subarrays ending at any index before i as well.
*/

};

int main()
{

}