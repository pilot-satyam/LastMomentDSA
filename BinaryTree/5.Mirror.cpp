#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool isSymmetric(TreeNode* root){
        return root==NULL || isHelp(root->left,root->right); 
    }

    bool isHelp(TreeNode* left,TreeNode* right){
        if(left == NULL || right == NULL) return left == right;
        if(left->val!=right->val) return false;
        return isHelp(left->left,right->right) && isHelp(left->right,right->left);
    }

};

int main(){

}