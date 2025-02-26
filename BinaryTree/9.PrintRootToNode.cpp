#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: bool getPath(TreeNode* root,vector<int> &ans,int x){
        if(root == NULL) return false; //it means you have traversed till end and still hasn't found the target leaf node
        if(root->val == x) return true;
        ans.push_back(root->val);
        //if either of them return true return true
        if(getPath(root->left,ans,x) || getPath(root->right,ans,x)) return true;
        //if we can't find any true then remove the element from vector and continue traversal
        ans.pop_back();
        //since can't get any true hence return false
        return false;
    }

    vector<int> Solution::solve(TreeNode* A,int B){
        vector<int> ans;
        if(A == null) return ans;
        getPath(A,ans,B);
        return ans;
    }
};

int main(){

}