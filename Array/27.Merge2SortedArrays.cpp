#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int left = n-1;
            int right = 0;
            while(left >= 0 and right < m){
                if(arr1[left] > arr2[right]){
                    swap(arr1[left],arr2[right]);
                    left--;
                    right++;
                }
                else{
                    break;
                }
            }
                sort(arr1,arr1+n);
                sort(arr2,arr2+m);
        } 
};


//GAP Method

 private:
        void swapIfGreater(long long arr1[], long long arr2[],int idx1,int idx2){
            if(arr1[idx1] > arr2[idx2]){
                swap(arr1[idx1],arr2[idx2]);
            }
        }
    
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int len = n + m;
            int gap = (len/2) + (len%2);
            while(gap > 0){
                int left = 0;
                int right = left + gap;
                while(right < len){
                    //if a1 & a2
                    if(left < n and right >= n){
                        swapIfGreater(arr1,arr2,left,right-n);
                    }
                    //both in a2
                    else if(left >= n){
                        swapIfGreater(arr,arr2,left-n,right-n);
                    }
                    
                    //both in a1
                    else{
                        swapIfGreater(arr1,arr1,left,right);
                    }
                    left++, right++;
                }
                if(gap == 1) break;
                gap = (gap/2) + (gap%2);
            }
        } 

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
