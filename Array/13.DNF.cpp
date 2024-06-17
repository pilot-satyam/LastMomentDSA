#include<bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &v,int n){
    int low = 0, mid =0;
    int high = n-1;
    while(mid <= high){
        if(a[mid] == 1) mid++;
        else if(a[mid] == 0) {
            swap(a[mid],a[low]) mid++, low++;
        }
        else{
            swap(a[high],a[mid]) high--;
        }
    }
}

int main(){

}