#include <bits/stdc++.h>
using namespace std;
//Brute force

// void solve(vector<int> &a, int target){
//     for(int i=0;i<a.size();i++){
//         for(int j=i+1;j<a.size();j++){
//             if(a[i] + a[j] == target){
//                 cout << "(" << a[i] << "," << a[j] << ")";
//             }
//         }
//     }
// }

//optimial 
void solveIm(vector<int> &a, int target){
    unordered_map<int,bool> m;
    for(auto it : a){
        int com = target - it;
        if(m[com]){
            cout<< "(" << com << "," << it << ")";
        }
        m[it] = true;
    }
}


//a [] = [1,7,3,6,5,6] 

int findIdx(vector<int> &a){
    int totalSum = 0, leftSum = 0;
    for(int i=0;i<a.size();i++){
        totalSum += a[i];
    }
    
    for(int i=0;i<a.size();i++){
        //rightSum = totalSum - leftSum - a[i]
        
        if(leftSum == totalSum - leftSum - a[i]){
            return i;
        }
        leftSum += a[i];
    }
    return -1;
}

int main()
{
    vector<int> a = {1,7,3,6,5,6};
    int idx = findIdx(a);
    cout<<"Found the dividing idx" << " " << idx << endl;
}



public static void main(String[] args){
    String json = "{\"name\" : \"Satyam\", \"age\" : 25}";
    //creating an objet mappert
    ObjectMappr objectMappr = new ObjectMappr();
    //converting json string to hashmap
    Map<String,Object> map = ObjectMappr.readValue(json,Hashmap.class);
    System.out.println(map);
}






