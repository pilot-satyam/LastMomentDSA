/*
Q. Return Yes if two elements equal to a sum else no
*/

#include<bits/stdc++.h>
using namespace std;
string read(int n, vector<int> book, int target)
{
    map<int,int> m;
    for(int i=0;i<n;i++){
        int rem = target - book[i];
        if(m.find(rem)!=m.end()){
            return "YES"; //if need to return indexs --> {m[rem], i}
        }
        m[book[i]] = i; //inserting this element in map if it is not found equal to rem, so that it can be checked later on
                        //for other element reference
    }
    return "NO";
}

//If no map is allowed then in that case we can use 2pointer Approach

string read(int n, vector<int> book, int target){
    int left = 0, right = n-1;
    sort(book.begin(),book.end());
    while(left < right){
        int sum = book[left] + book[right];
        if(sum == target) return "YES";
        else if(sum < target) left++; //if the sum is less than target, we need to move from left to right
        else right--; //sly if sum > target then right to left
    }
    return "NO";
}

int main(){

}