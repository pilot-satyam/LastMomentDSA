#include<bits/stdc++.h>
using namespace std;

//Q : https://leetcode.com/problems/balance-a-binary-search-tree/description/?envType=daily-question&envId=2026-02-09

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

/** 
 * 
 *  Do an in-order traversal to get all nodes in sorted order
 *  Build a new balanced tree by recursively picking the middle element as root
 * 
 * what makes a tree balanced:

    A balanced BST means every node's left and right subtrees have heights differing by at most 1
    The best way to achieve this is to make the tree as "bushy" as possible (wide rather than tall)
 * 
 */

class Solution {

private: 
    void inorderBST(TreeNode* root, vector<int> &inorder){
        if(root == NULL) return;
        inorderBST(root->left,inorder);
        inorder.push_back(root->val);
        inorderBST(root->right,inorder);
    }

TreeNode* buildBST(vector<int> &inorder, int low, int high){
    if(low > high) return NULL;
    int mid = low + (high - low)/2;
    TreeNode* newNode = new TreeNode(inorder[mid]);
    newNode->left = buildBST(inorder,low,mid-1);
    newNode->right = buildBST(inorder,mid+1,high);
    return newNode;
}

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorderBST(root,inorder);
        int n = inorder.size();
        return buildBST(inorder,0,n-1);
    }
};

int main(){}