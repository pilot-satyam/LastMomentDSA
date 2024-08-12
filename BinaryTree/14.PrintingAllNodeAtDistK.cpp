#include<bits/stdc++.h>
using namespace std;

/*
Ques : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    //using BFS to mark Parent for a node

    void markParent(TreeNode* root, TreeNode* target, unordered_map<TreeNode*,TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            } 
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        markParent(root,target,parent);    
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr = 0;
        //2nd BFS to go from target node and finding k
        while(!q.empty()){
            int size = q.size();
            if(curr == k) break;
            curr++;
            for(int i=0;i<size;i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left and !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right and !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(parent[current] and !visited[parent[current]]){
                    q.push(parent[current]);
                    visited[parent[current]] = true;
                }
            }
        }

        vector<int> res;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            res.push_back(current->val);
        }
        return res;
    }
};

int main(){

}