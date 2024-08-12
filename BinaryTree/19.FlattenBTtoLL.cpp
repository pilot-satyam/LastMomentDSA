#include<bits/stdc++.h>
using namespace std;

/**
 * Ques : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
 * 
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* rightMost = curr->left;
                while(rightMost->right){
                    rightMost = rightMost->right;
                }
                rightMost->right = curr->right;
                //flattening current's left Binary tree
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }    
    }
};
int main(){

}