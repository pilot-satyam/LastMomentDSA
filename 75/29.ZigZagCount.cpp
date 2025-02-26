#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/editorial/?envType=study-plan-v2&envId=leetcode-75

class Solution {
private:
    void dfs(TreeNode* root,int length, bool isLeft, int &ans){
        if(root == NULL) return;
        ans = max(ans,length);
        //if we are moving left next move should be towards right
        if(isLeft){
            dfs(root->left,length + 1, false, ans);
            dfs(root->right,1,true,ans);
        }
        else{
            dfs(root->right, length + 1, true, ans);
            dfs(root->left, 1, false, ans);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        dfs(root,0,true,ans); //for moving left(true)
        dfs(root,0,false,ans); //for moving right(false)
        return ans;
    }
};



int main(){

}