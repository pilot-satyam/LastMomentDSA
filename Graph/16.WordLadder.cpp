#include<bits/stdc++.h>
using namespace std;

public:
     int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({startWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(startWord);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == targetWord) return steps;
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch = 'a';ch<='z';ch++){
                    word[i] = ch;
                    //exist in set
                    if(st.find(word) != st.end()){
                        st.erase(word); //in these case marking as visited meaning erasing it from set
                        q.push({word,steps+1});
                    }
                }
                //restoring original
                word[i] = original;
            }
        }
        return 0; //doesn't exist
    }

int main(){

}