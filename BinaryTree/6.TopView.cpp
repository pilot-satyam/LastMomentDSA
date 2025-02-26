#include<bits/stdc++.h>
using namespace std;

//https://takeuforward.org/data-structure/top-view-of-a-binary-tree/

class Solution{
    vector<int> topView(Node* root){
        vector<int> ans;
        if(root == NULL) return ans;
        map<int,int> m;
        queue<pair<Node*,int>> q;
        q.push({root,0}); // pushing node->data , line
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            if(m.find(line) == m.end()) m[line] = node->data; //agar map me wo line nai hai pehele se
            if(node->left!=NULL){
                q.push({node->left,line-1});
            }
            if(node->right!=NULL){
                q.push({node->right,line+1});
            }
        }
        for(auto it : m){
            ans.push_back(it.second);
        }
        return ans;
    }
};

int msin(){

}