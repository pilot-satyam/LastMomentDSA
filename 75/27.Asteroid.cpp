#include<bits/stdc++.h>
using namespace std;
// *** IMP
//Q: https://leetcode.com/problems/asteroid-collision/?envType=study-plan-v2&envId=leetcode-75

//we are using stack here since we need to continous comparison of current asteroid with coming asteroid

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(int i=0;i<asteroids.size();i++){
            bool destroyed = false;
            while(!st.empty() && st.back() > 0 && asteroids[i] < 0){
                //collision happens
                if(abs(st.back()) < abs(asteroids[i])){
                    //remove smaller 
                    st.pop_back();
                    //conitnue checking for other collisions
                    continue;
                }
                else if(abs(st.back()) == abs(asteroids[i])){
                    st.pop_back(); //both are destroyed
                    destroyed = true;
                }
                destroyed = true;
                break; //eg 5,10,-5 since 10 > abs(-5) hence (-5) is destroyed
                // and we will break from here since nothing is to be added 
                //in stack as 10 is already present in stack, hence bool == true
            }
            if(!destroyed){
                st.push_back(asteroids[i]);
            };
        }
        return st;
    }
};

int main(){

}