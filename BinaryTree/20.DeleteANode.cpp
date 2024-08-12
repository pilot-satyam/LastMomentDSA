#include<bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * Ques: https://leetcode.com/problems/delete-node-in-a-bst/description/
 * 
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            return helper(root);
        }

        TreeNode* dummy = root;
        while(root!=NULL){
            if(key < root->val){
                if(root->left and root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else{
                if(root->right and root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        return dummy;
    }

    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL){
            return root->left;
        }
        TreeNode* rightChild = root->right;
        TreeNode* rightMostOfLeftSubtree = findRightMostOfLeftSubtree(root->left);
        rightMostOfLeftSubtree->right = rightChild;
        return root->left;
    }

    TreeNode* findRightMostOfLeftSubtree(TreeNode* root){
        if(root->right == NULL) return root;
        return findRightMostOfLeftSubtree(root->right);
    }
};

int main(){

}