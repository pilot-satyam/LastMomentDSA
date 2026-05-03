#include<bits/stdc++.h>
using namespace std;

//storing leaf nodes in a vector and then comparing it

class Solution {
    void solve(TreeNode* root, vector<int> &leaves){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) leaves.push_back(root->val);
        solve(root->left,leaves);
        solve(root->right,leaves);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l,r;
        solve(root1,l);
        solve(root2,r);
        return l == r;
    }
};


int main(){

}