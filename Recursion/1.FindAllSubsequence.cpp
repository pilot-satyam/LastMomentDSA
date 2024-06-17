#include<bits/stdc++.h>
using namespace std;

void PrintF(int idx,vector<int> &ds, int a[],int n){
    if(idx == n){
        for(auto it : ds){
        cout<< it << " ";
        }
        if(ds.size() == 0){
            cout << "{}";
        }
        cout<<endl;
        return;
    }

    ds.push_back(a[idx]);
    PrintF(idx+1,ds,a,n);
    ds.pop_back();
    PrintF(idx+1,ds,a,n);
}

int main(){
    int a[] = {3,1,2};
    vector<int> ds;
    int n = 3;
    PrintF(0,ds,a,n);
}