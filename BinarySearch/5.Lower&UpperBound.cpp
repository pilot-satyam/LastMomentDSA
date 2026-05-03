##include<bits/stdc++.h>
using namespace std;
/*
here ans = n, since if the element is not found in the array then we will insert it or return at the last index
eg: arr = [2, 4, 6, 8]
    x = 10

ans: [2, 4, 6, 8, 10]
                  ↑
                index = n

Because n represents “not found”.

Think of it this way:

Valid indices: 0 to n-1

Index n is just outside the array

So:

If no element ≥ x exists, return n.
*/

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0;
    int high = n-1;
    int ans = n;
	while(low <= high){
	int mid = low + (high - low) / 2;
		if(arr[mid] >= x){
			ans = mid;
			high = mid -1;
		}
		else{
			low = mid+1;
		}
	}
	return ans;
}


int upperBound(vector<int> &arr, int x, int n){
    int low = 0;
    int high = n-1;
    int ans = n;
	while(low <= high){
	int mid = low + (high - low) / 2;
		if(arr[mid] > x){
			ans = mid;
			high = mid -1;
		}
		else{
			low = mid+1;
		}
	}
	return ans;
}


int main()
{
}