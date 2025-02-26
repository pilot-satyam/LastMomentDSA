#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "#";
        return to_string(root->val) + "," +serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* deserializeHelper(istringstream &iss){
        string val;
        //reading until next comma
        getline(iss,val,',');
        if(val == "#") return NULL;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(iss);
        node->right = deserializeHelper(iss);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserializeHelper(iss);
    }

};

int main(){

}