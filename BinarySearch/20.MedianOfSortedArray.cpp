#include<bits/stdc++.h>
using namespace std;

// O(N1 + N2) ==> T.C
// O(1) ==> S.C

/**
Median ka matlab:

total elements odd → beech ka element

total elements even → beech ke 2 ka average
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int idx2 = n / 2;
        int idx1 = n / 2 - 1;
        int cnt = 0;
        int idxEle1 = -1, idxEle2 = -1;
        int i=0,j=0;
        while(i < n1 and j < n2){
            if(nums1[i] < nums2[j]){
                if(cnt == idx1) idxEle1 = nums1[i];
                if(cnt == idx2) idxEle2 = nums1[i];
                cnt++;
                i++;
            }
            else{
                if(cnt == idx1) idxEle1 = nums2[j];
                if(cnt == idx2) idxEle2 = nums2[j];
                cnt++;
                j++;
            }
        }
        while(i < n1){
            if(cnt == idx1) idxEle1 = nums1[i];
            if(cnt == idx2) idxEle2 = nums1[i];
            cnt++;
            i++;
        }
        while(j < n2){
            if(cnt == idx1) idxEle1 = nums2[j];
            if(cnt == idx2) idxEle2 = nums2[j];
            cnt++;
            j++;
        }
        if(n%2 == 1){
            return idxEle2;
        }
        return (double)((double)(idxEle1 + idxEle2)) / 2.0;
    }
};

//Optimal Solution:
/**

Instead of merging two arrays (O(n+m)), we find where to "cut" both arrays such that:

Left side has exactly half the elements
All elements on the left ≤ all elements on the right

nums1: [ ... l1 | r1 ... ]
nums2: [ ... l2 | r2 ... ]

l1 = array1 ka left ka last element
r1 = array1 ka right ka first element

l2 = array2 ka left ka last element
r2 = array2 ka right ka first element


** Parition Condition :
l1 <= r2  AND  l2 <= r1

Case 1:
l1 > r2

Matlab:

array1 se zyada bada element left me aa gaya
👉 array1 se kam elements lo

Case 2:
l2 > r1

Matlab:

array1 se kam elements liye
👉 array1 se zyada elements lo

We do binary search in smaller array since
1)search space would be less
2)edge cases easy

why ?  left = (n1 + n2 + 1) / 2 since in case of odd elements left side increases and so that we get median from left side

If I select x elements from array1 then automatically array2 se left - x elements chale jayenge

1 2 3 4 5 6 ==> since here the elements are even then 4 would be mid2 and 3 would be mid2 - 1 (this way take both mids, hence we use mid2, mid2 - 1 )

Ans : https://takeuforward.org/data-structure/median-of-two-sorted-arrays-of-different-sizes

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = n1;
        int left = (n1 + n2 + 1) / 2;
        int n = n1 + n2;
        while(low <= high){
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
            if(l1 <= r2 and l2 <= r1){
                if(n%2 == 1) return max(l1,l2);
                return ((double)(max(l1,l2) + min(r1,r2))) / 2.0;
            }
            else if (l1 > l2) high = mid1 - 1;
            else low = mid1 + 1;
        }
        return 0;
    }
};


int main(){
}