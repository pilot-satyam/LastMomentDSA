#include<bits/stdc++.h>
using namespace std;

/*
    Q: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
*/

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

    int findDist(unordered_map<TreeNode*,TreeNode*> &m, TreeNode* target){
        queue<TreeNode*> q;
        unordered_map<TreeNode*,int> vis;
        vis[target] = 1;
        q.push(target);
        int maxi = 0;
        while(!q.empty()){
            int size = q.size();
            int flag = 0;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    flag = 1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    flag = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }

                if(m[node] && !vis[m[node]]){
                    flag = 1;
                    vis[m[node]] = 1;
                    q.push(m[node]);
                }
            }
            //upar se jitni baar bhi flag exist karta hai keep on adding
            if(flag) maxi++;
        }
        return maxi;
    }

    TreeNode* bfsToFindParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &m, int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node = q.front();
            if(node->val == start) res = node;
            q.pop();
            if(node->left){
                m[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                m[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> m;
        TreeNode* target = bfsToFindParent(root,m,start); 
        //after calling the above parent function we will have the 
        //start node's address since function returns res
        int maxi = findDist(m,target);
        return maxi;
    }
};

int main(){

}