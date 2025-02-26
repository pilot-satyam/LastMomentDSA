#include<bits/stdc++.h>
using namespace std;

/*
    1) We will use Binary search, and in single pass we cannot get hence we will require 2 pass

*/

int firstOccurence(int n, int x, vector<int> &v){
    int low = 0, high = n - 1;
    int mid = low + (high-low)/2;
    int first = -1;
    while(low <= high){
        if(v[mid] == x){
            res = mid;
            high = mid - 1;
        }
        else if(v[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return first;
}

int lastOccurence(int n, int x, vector<int> &v){
    int low = 0, high = n - 1;
    int mid = low + (high-low)/2;
    int last = -1;
    while(low <= high){
        if(v[mid] == x){
            res = mid;
            low = mid + 1;
        }
        else if(v[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return last;
}

pair<int,int> firstAndLastPosition(vector<int> &v, int n, int x){
    int first = firstOccurence(n,x,v);
    if(first == -1) return {-1,-1}; //because if first me nai milega to last me obiovsuly nai hoga
    int last = lastOccurence(n,x,v);
    return {first,last};
}

int main(){

}