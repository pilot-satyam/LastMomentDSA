#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool solve(TreeNode* root, string path,vector<string> &ans){
        if(root == NULL) return false;
        if(!path.empty()){
            path += "->";
        }
        path+=to_string(root->val);
        if(root->left == NULL and root->right == NULL){
            ans.push_back(path);
            return true;
        }
        bool leftPath = solve(root->left, path, ans);
        bool rightPath = solve(root->right, path, ans);
        
        return leftPath || rightPath;
        
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == NULL) return ans;
        solve(root,"",ans);
        return ans;
    }
};

int main(){

}