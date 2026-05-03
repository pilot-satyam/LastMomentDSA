#include<bits/stdc++.h>
using namespace std;

//https://www.naukri.com/code360/problems/allocate-books_1090540?leftPanelTabValue=PROBLEM

//A: This is same as previous problem, still go through the problem statement

int distributeBook(vector<int> &arr, int pages){
    int students = 1;
    long long pagesStudent = 0;
    for(int i=0;i<arr.size();i++){
        //it means we are allocating to same student & hence we don't need to increase student
        if(pagesStudent + arr[i] <= pages){
            pagesStudent += arr[i];
        }
        else{
        // allocating to next student
            students += 1;
            pagesStudent = arr[i];
        }
    }
    return students;
}

// number of students ==> m
int findPages(vector<int>& arr, int n, int m) {
    if(m > n) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low <= high){
        int mid = low + (high - low) / 2;
        int students = distributeBook(arr,mid);
        if(students > m) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int main(){
}