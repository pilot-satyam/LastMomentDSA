#include<bits/stdc++.h>
using namespace std;
/*
    Ques: In an array every number is appearing twice you need to find a number that will appear only once eg [1,1,2,3,3]
*/

/*
    Sol : Brute Force : Use two for loops and do linear search and maintain a variable counter, the element 
    where count == 1 return that element.

    Better: Use Hashing, use a hash array initialized with 0 and then increment the value in hash array while
    you are iterating the the array. 
    Problem: Only works if all the stored elements are positive, if any negative then it will be hard to hash,
             if any bigger integer is given like 10^12 then in that case array cannot store such large numbers
    
    Hence : Use Map in case of large numbers use like unorderd_map<long long> 

    Optimal: The Optimal solution is to use XOR so that SC -> O(1) and T.C -> O(N)
*/

int SingleNumber(vector<int> a, int n){
    int xor = 0;
    for(int i=0;i<n;i++){
        xor = xor ^ a[i];
    }
    return xor;
}

int main()
{

}