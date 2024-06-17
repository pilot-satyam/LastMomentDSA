#include<bits/stdc++.h>
using namespace std;

//2nd Variety 
//Link : https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbEJBMm9IekxxZWpsY2RtbmROalhVMXhJcXRnUXxBQ3Jtc0ttR0IwQjZMUXpyVkk0ZEgtaFZSSERiNEZxRlJzSDBxVUhNMFROanFvcEJvSWtUNmtYOGxxR1d5OWhGcXA0Q2NEWElCM0Z3XzJKcE1lNGh4M1I0OWotXzJfd1A0MUliR290aWttU1d5YnlfdlE5dEhZYw&q=https%3A%2F%2Fbit.ly%2F3QloXof&v=h4aBagy4Uok

vector<int> alternateNumbers(vector<int> &a)
{
    vector<int> pos,neg;
    for(int i=0;i<n;i++){
        if(a[i] > 0){
            pos.push_back(a[i]);
        }
        else{
            neg.push_back(a[i]);
        }
    }
    if(pos.size() > neg.size()){
        for(int i=0;i<neg.size();i++){
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        int idx = neg.size() * 2;
        for(int i = neg.size();i<pos.size();i++){
            a[idx] = pos[i];
            idx++;
        }
    }
    else{
         for(int i=0;i<pos.size();i++){
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        int idx = pos.size() * 2;
        for(int i = pos.size();i<neg.size();i++){
            a[idx] = neg[i];
            idx++;
        }
    }
    return a;
}

int main(){
    
}