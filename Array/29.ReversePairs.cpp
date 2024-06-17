#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr

        //Modification 1: cnt variable to count the pairs:
        long long cnt = 0;

        //storing elements in the temporary array in a sorted manner//

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1); //Modification 2
                right++;
            }
        }

        // if elements on the left half are still left //

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        //  if elements on the right half are still left //
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt; // Modification 3
    }

    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        long long cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2LL * arr[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        long long cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);  // left sub half of the merge array
        cnt += mergeSort(arr, mid + 1, high); // right sub half of the merge array
        cnt += countPairs(arr, low, mid, high); // last step, merging both subarrays i.e L + R
        merge(arr, low, mid, high);  // merging sorted halves
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};

 
int main(){

}