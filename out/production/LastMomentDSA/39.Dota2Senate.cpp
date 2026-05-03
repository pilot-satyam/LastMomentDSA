#include<bits/stdc++.h>
using namespace std;

//Ques: https://leetcode.com/problems/dota2-senate/description/?envType=study-plan-v2&envId=leetcode-75

/**
 * Problem Statement : Problem Statement: Yeh problem "Dota 2 Senate" ke baare mein hai, 
    jo ek fictional game hai, jisme do groups hote hain: Radiant aur Dire. Har group ke paas apne senators
    hote hain, jo ek dusre ke khilaf vote karte hain.

    Radiant ke senators ko 'R' se represent kiya gaya hai.
    Dire ke senators ko 'D' se represent kiya gaya hai.
    Har senator ko apne group ke opponents ko "ban" karne ka chance milta hai. 
    "Ban" karna ka matlab hai, ek senator ko eliminate kar dena.

    Game ka Rules:

    Har senator apne turn par vote karta hai.
    Har round mein ek senator Radiant group se aur ek senator Dire group se apne opponent ko ban karta hai.
    Jo senator turn pe sabse pehle aata hai (jo pehle queue mein hota hai), woh opponent ko ban karta hai 
    aur apne group ke end mein wapas add kar diya jaata hai, lekin uske index mein ek additional value add
    kar di jaati hai (jisse pata chale ki woh next round mein late move karega).
    Yeh process tab tak chalta hai jab tak ek group ke sare senators eliminate nahi ho jaate.

    example: Agar input mein senate = "RDDRR" diya gaya hai, toh yeh iska matlab hai:

        Radiant group ke paas 3 senators hain (R, R, R).
        Dire group ke paas 2 senators hain (D, D).

        Input: senate = "RDDRR"

    Initial Setup:

    Radiant group (R) ke paas 3 senators hain: [R, R, R]
    Dire group (D) ke paas 2 senators hain: [D, D]
    Round 1:

    Pehle turn mein, Radiant ka senator (R) aur Dire ka senator (D) clash karte hain.
    R ko pehle turn milta hai, isliye R apne opponent D ko eliminate kar deta hai.
    Iske baad, Radiant ka senator (R) ko wapas queue mein add kiya jaata hai (lekin index increment hota hai).
    Round 2:

    Ab Radiant ka next senator (R) aur Dire ka baaki ka senator (D) clash karte hain.
    R jeetega aur D ko eliminate kar dega.
    Radiant ka senator (R) fir se queue mein wapas add ho jayega.
    Round 3:

    Ab Radiant group ke paas sirf ek senator bach gaya hai, aur Dire group ke paas bhi koi senator nahi bachne wale hain.
    Radiant jeet gaya, kyunki Dire ke sare senators eliminate ho gaye hain.

 */

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> rad,dir;
        for(int i=0;i<n;i++){
            if(senate[i] == 'R'){
                rad.push(i);
            }
            else{
                dir.push(i);
            }
        }
        while(!rad.empty() and !dir.empty()){
            int r = rad.front();
            int d = dir.front();
            rad.pop();
            dir.pop();

            //senator wo came first will elemenate other i.e jiska index,
            //chotha hoga for loop mein matlab wo pehele aaya hai
            if(r<d){
                rad.push(r + n);
            }
            else{
                dir.push(d + n);
            }
        }
        return rad.empty() ? "Dire" : "Radiant";
    }
};

int main(){

}