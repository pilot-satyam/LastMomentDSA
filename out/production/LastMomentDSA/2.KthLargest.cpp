/**
The intuition behind using a min-heap to find the Kth largest element in an array revolves around the idea of maintaining a small, but efficient, data structure that helps you track the largest elements without needing to sort the entire array.

Let's break down the logic:

1. Concept of K Largest Elements:
To find the Kth largest element in an array, you don't need to know every element in sorted order. Instead, you only need to know the top K largest elements. Once you have these K elements, the smallest element in that group will be the Kth largest element in the entire array.

Why the smallest of the top K largest?
In an unsorted array, the Kth largest element is the smallest element in the group of the K largest elements. To illustrate:
If we pick the top 3 largest elements from the array {3, 2, 1, 5, 6, 4}, we get {6, 5, 4}. The smallest in this group is 4, which is the 3rd largest element in the array.
2. Min-Heap as a Tool:
A min-heap is a data structure that keeps the smallest element at the top. When we use a min-heap of size K, it allows us to efficiently manage the top K largest elements.

Why a Min-Heap?
A min-heap gives us two key benefits:
The smallest element (i.e., the root) is always at the top, so we can easily identify the smallest of the K largest elements.
The heap is always sorted in a way that allows us to insert a new element in logarithmic time 
𝑂
(
log
⁡
𝐾
)
O(logK), ensuring we maintain the K largest elements efficiently as we process the array.
 */


/**
Brute : sort and return n - k element ==> O(nlogn)
Optimal: use minHeap, first insert first k elements in heap and then
traverse in array after kth element and if element is greater than ccurrent 
heap root then add it in the heap and remove the existing root and 
if the val is less than the root then ignore. ==> O(nlogk)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int i=0;i<k;i++){
            minHeap.push(nums[i]);
        }
        for(int i = k;i<nums.size();i++){
            if(nums[i] > minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};