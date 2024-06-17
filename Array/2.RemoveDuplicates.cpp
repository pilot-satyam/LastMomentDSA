//Removing duplicates in an array
//first approach (my) --> take a set , insert the elements into it and then iterate it
//so in this case T.C --> NlogN + N --> Nlogn for insertion and N for iteration 
//S.C --> O(N) --> if we imagine all unique elements, then in that case there will be an iteration of 'n' elements

/*
Optimzation --> 2 Pointer Approach
*/
#include<bits/stdc++.h>
int removeDuplicates(vector<int> v,int n){
    int i = 0;
    for(int j=1;j<n;j++){
        if(a[j] != a[i]){
            a[i+1] = a[j];
            i++;
        }
    }
    return i+1; // i+1 since the i is the index, and suppose i is at 2 then it means there are 3 elements
}