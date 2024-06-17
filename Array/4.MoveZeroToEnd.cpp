#include<bits/stdc++.h>
using namespace std;

//Most Optimal Solution
//Two Pointer Approach, imagine j to be at any negative iidx, after that we will check for the first 0 of the array
// because we don't want to disturb the position of the array, after we have got the first 0 position
//next we will place the 'i' pointer at next idx of 'j' so that comparison can be made and we can swap the elements

vector<int> moveZeros(int n,vector<int> a){
    //getting first 0
    int j = -1; 
    for(int i=0;i<n;i++){
        if(a[i] == 0){
            j = i;
            break;
        }
    }

    //no non zero numbers
    if(j == -1) return a;

    for(int i=j+1;i<n;i++){
        if(a[i] != 0){
            swap(a[i],a[j]);
            j++;
        }
    }
    return a;
}

int main(){

}