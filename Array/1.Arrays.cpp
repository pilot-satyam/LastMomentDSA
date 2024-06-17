//in int main maximum size is 10^6 while if we define before int main i.e globally
//it will be 10^7
#include <bits/stdc++.h>
using namespace std;
int main(){

int secondLargest(vector<int> &a, int n){
    int largest = a[0];
    int secondLargest = -1;
    for(i-1;i<n;i++){
        if(a[i] > largest){
            secondLargest = largest;
            largest = a[i];
        }
        else if(a[i] < largest and a[i] > secondLargest){
            secondLargest = a[i];
        }
    }
    return secondLargest;
}

int secondSmallest(vector<int> &a, int n){
    int smallest = a[0];
    int ssmallest = INT_MAX;
    for(int i=1;i<n;i++){
        if(a[i] < smallest){
            ssmallest = smallest;
            smallest = a[i];
        }
        else if(a[i]!= smallest and a[i] < ssmallest){
            ssmallest = a[i];
        }
    }
    return ssmallest;
}

vector<int> getSecondOrderElements(int n,vector<int> a){
        int secLargest = secondLargest(a,n);
        int secSmallest = secondSmallest(a,n);
        return {secLargest,secSmallest}; 
}
}