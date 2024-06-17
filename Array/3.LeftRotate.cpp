#include<bits/stdc++.h>
using namespace std;

//Here T.C--> O(N)
//S.C--> O(1) because we are not using extra space although it is O(N) for complete algo, since the given array 
//space is already O(N), but since we are not any extra space it should be O(1), explain it to interviewer.

//To rotate by 1 place
vector<int> leftRotate(vector<int> v,int n){
    int temp = v[0];
    //i starts with 1 since index can't be -ve if we consider for 0th idx
    for(int i=1;i<n;i++){
        v[i-1] = v[i];
    }
    v[n-1] = temp;
    return v;   
}
//This will be the follow up Ques

// Q2. Left Rotate the array by 'd' place 
// eg d=2
// a[6] = {1,2,3,4,5,6} ==> {3,4,5,6,1,2}

/*
Sol: 
Intituiton when ever d = size of array it will always come to its original position
eg: d = 6 ==> {1,2,3,4,5,6} ==> back to original
sly if d = 9 rotations then ==> we can break it like d = 6 + 3 rotations
*/

/*
BRUTE --> Like in the first case we were storing first element in temp, here we can store first 'd' elements in 
          temp array and then we can iterate over array, like:
          for(int i=d;i<n;i++){
            a[i-d] = a[i];
          }

        now since the elements are filled we are left with last 'd' spaces in array, inorder to fill it 
        we iterate over the temp array

        int j = 0;
        for(int i = n-d;i<n;i++){
            a[i] = temp[j];
            j++;
        }

        // Now Replacing 'j' for Better solution
        a[] = {4,5,6,7,_,_,_}
        the position after 7 will be the base idx to replace and fit the integer it will be (n-d), sly it's corresponding
        idx would be (n-d+1) and (n-d+2), so the for loop iteration for 'temp' can be modified to

        eg: temp[] = {1,2,3}

        for(int i=n-d;i<n;i++){
            a[i] = temp[i-(n-d)];
        }
*/

//Now our 'Best' Solution
//T.C => O(d) to store d elements + O(n-d) for shifting + O(d) --> to put it back,
// hence T.C ==> O(d) + O(n-d) +O(d) ==> O(n+d)
//Extra Space ==> O(d) ==> using extra space to store array

void leftRotateByD(vector<int> a,int n,int d){
    d = d%n; //return the remainder as discussed above
    int temp[d]; 
    //storing d elements in temp array
    for(int i=0;i<d;i++){
        temp[i] = a[i];
    }

    for(int i=d;i<n;i++){
        a[i-d] = a[i]; //shifting 
    }

    for(int i=n-d;i<n;i++){
        a[i] = temp[i - (n-d)];
    }
}

/*
Now to optmize the S.C --> O(1), if we observe here,
if we reverse 1st d elements ==> 1,2,3 ==> 3,2,1,
&& now reverse rest (n-d) elements ==> 4,5,6,7 ==> 7,6,5,4,
&& now reverse the whole array ==> 3,2,1,7,6,5,4 ==> 4,5,6,7,1,2,3

in this case T.C ==> O(d) + O(n-d) + O(d) ==> O(2d)
S.C ==> O(1)
*/

void leftRotateByD(vector<int> a,int n,int d){
    reverse(a,a+d);
    reverse(a+d,a+n);
    reverse(a,a+n);
}

int main(){

}