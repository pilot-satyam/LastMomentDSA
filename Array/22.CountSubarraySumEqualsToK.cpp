#include<bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector<int> &a,int k){
    unordered_map<int,int> m;
    m[0] = 1;
    int n = a.size();
    int preSum = 0,cnt=0;
    for(int i=0;i<n;i++){
        preSum+=a[i];
        int remove = preSum-k;
        cnt+=m[remove];
        m[preSum]+=1;
    }
    return cnt;
}

int main(){

}