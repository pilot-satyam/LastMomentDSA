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
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || solve(root->left,root->right);
    }

    bool solve(TreeNode* leftNode, TreeNode* rightNode) {
    // If both nodes are NULL, they are symmetric
    if (leftNode == nullptr && rightNode == nullptr) {
        return true;
    }
    // If only one of the nodes is NULL, they are not symmetric
    if (leftNode == nullptr || rightNode == nullptr) {
        return false;
    }
    // If values are not equal, it's not symmetric
    if (leftNode->val != rightNode->val) {
        return false;
    }
    // Recursively check the symmetry of the subtrees
    return solve(leftNode->left, rightNode->right) && solve(leftNode->right, rightNode->left);
}


};

int main(){

}