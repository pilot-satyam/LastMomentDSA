#include<bits/stdc++.h>
using namespace std;

/*
Ques: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
*/

//BruteForce : doing inorder ==> gets sorted array ==> perform 2 pointer
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inorderTraversal(root,inorder);
        int l = 0, r = inorder.size()-1;
        while(l < r){
            int sum = inorder[l] + inorder[r];
            if(sum == k){
                return true;
            }
            else if(sum < k){
                l++;
            }
            else{
                r--;
            }
        }
        return false;
    }

    void inorderTraversal(TreeNode* root, vector<int> &inorder){
        if(root == NULL) return;
        inorderTraversal(root->left,inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right,inorder);
    }

};

//Optimized: using BST iterator concept

class BSTIterator{
    stack<TreeNode*> st;
    //reverse --> true --> before
    //reverse --> false --> next
    bool reverse = true;

    public: 
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    
    bool hasNext(){
        return !st.empty();
    }

    /** @return the next smallest number */
    int next(){
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse) pushAll(temp->right);
        else{
            pushAll(temp->left);
        }
        return temp->val;
    }

    private:
    void pushAll(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            if(reverse == true){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
    }
};

class Solution{
    public:
    bool findTarget(TreeNode* root, int k){
        if(!root) return false; 
        BSTIterator l(root,false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();
        while(i < j){
            if(i + j ==k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};
int main(){

}