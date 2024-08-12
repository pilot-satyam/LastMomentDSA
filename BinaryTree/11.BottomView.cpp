#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
    public:
        vector<int> bottomView(Node* root){
            vector<int> ans;
            if(root == NULL) return ans;
            map<int,int> m;
            queue<pair<Node*,int>> q;
            q.push({root,0});
            while(!q.empty()){
                auto it = q.front();
                auto node = it.first; //0 --> root
                auto line = it.second; //0 --> line
                m[line] = node->data; 
                q.pop();
                if(node->left){
                    q.push({node->left,line-1});
                }
                if(node->right){
                    q.push({node->right,line+1});
                }
            }
            for(auto it : m){
                ans.push_back(it.second);
            }
            return ans;
        }
};

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    // Get the Bottom View traversal
    vector<int> bottomView =
                    solution.bottomView(root);

    // Print the result
    cout << "Bottom View Traversal: "<< endl;
    for(auto node: bottomView){
        cout << node << " ";
    }

    return 0;
}