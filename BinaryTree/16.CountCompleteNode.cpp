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
 int countLeft(TreeNode* root){
    int height = 0;
    while(root){
        height++;
        root=root->left;
    }
    return height;
}

int countRight(TreeNode* root){
    int height = 0;
    while(root){
        height++;
        root=root->right;
    }
    return height;
}

int countNodes(TreeNode* root){
    if(root == NULL) return 0;
    int lh = countLeft(root);
    int rh = countRight(root);
    if(lh == rh) return (1 << lh) - 1; 
    //agar dono lh and rh equal nai hai to again give a recursion call to left and right subtree
    //we are adding 1 because in Binary tree as 1st node is root node so there (lh != rh) and hence we
    //1 for that root node and give subtree call, and if subtree is are also not equal then this 
    //recursion will get called again.
    return 1 + countNodes(root->left) + countNodes(root->right);
}
};

int main(){

}