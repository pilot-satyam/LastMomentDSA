#include<bits/stdc++.h>
using namespace std;

/*
    we are iterating from last since we want the greater element towards right,
    eg: 10 22 12 3 0 6

    ans: [22,12,6]
    
    Here if 22 > 12 it should mean that it is greater than all the element.

    dry run : maxi = 6, now moving to 0 since 0 < 6 hence 6 remains in the vector
    Now coming to 3 since 3 < maxi i.e 6 hence this also cannot be the leader
    coming to 12 since 12 > maxi, update maxi and insert into array ==> Now array is [6,12]
    coming to 22 since 22 > maxi , update and insert ==>  arr is [6,12,22]
    coming to 10 since 10 < maxi, hence the above array will be our final result.

    Now if they ask us to return the in the same order as it is given in array then in that case
    just reverse the array ==> [22,12,6] hence this is the ans.
*/

vector<int> superiorElements(vector<int> &a){
    int n = a.size();
    int maxi = INT_MIN;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        if(a[i] > maxi){
            ans.push_back(a[i]);
        }
        maxi = max(maxi,a[i]);
    }
    sort(a.begin(),a.end());
}

int main(){
    
}