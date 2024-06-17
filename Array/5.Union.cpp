#include<bits/stdc++.h>
using namespace std;

// KEEP IN MIND : BOTH ARRAYS ARE SORTED ARRAYS

/*
BRUTE : USE SET 
Explain: 
*/

//Brute Force

vector<int> sortedArray(vector<int> a, vector<int> b){
    set<int> st;
    int n1 = a.size();
    int n2 = b.size();

    for(int i=0;i<n1;i++){
        st.insert(a[i]);
    }
    for(int i=0;i<n2;i++){
        st.insert(b[i]);
    } 

    vector<int> temp;
    for(auto it : st){
        temp.push_back(it);
    }
    return temp;
}

//Optimal Approach
/*
    We will take advantage of the fact that they are sorted arrays, so we can use '2 pointer technique' array
    1. Keep one pointer on a array and one on b array
    2. Now compare and insert the smallest of two numbers
    3. If they are equal move the pointer further (j)
    4. If anytime it exceeds iteration, then insert the remaining numbers of the other array
*/

vector<int> sortedArray(vector<int> a, vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    int i=0;
    int j=0;
    vector<int> union;

    while(i<n1 && j<n2){
        if(a[i] <= b[j]){
            if(union.size() == 0 || union.back()!=a[i]) {
                // union.size() == 0 --> if we have to check for the first element or type
                //union.back() --> it will check wheter the last element in union array is same or not
                union.push_back(a[i]);
            }
            i++; //incrementing the pointer in any case
        }
        else{
             if(union.size() == 0 || union.back()!=b[j]) {
                union.push_back(b[j]);
            }
            j++;
        }
    }

    return union;
}

int main(){

}