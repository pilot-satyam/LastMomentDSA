#include<bits/stdc++.h>
using namespace std;

/*
Ques: https://leetcode.com/problems/validate-binary-search-tree/description/
*/

/*
    
*/

class Solution{
    public: bool isValidBST(TreeNode* root){
        return solve(root, LONG_MIN, LONG_MAX);
    }

    public: bool solve(TreeNode* root, long minVal, long maxVal){
        if(root == NULL) return true;
        if(root->val <= minVal or root->val >= maxVal) return false;
        return solve(root->left,minVal,root->val) and solve(root->right,root->val,maxVal);
    }
};

int main(){

}