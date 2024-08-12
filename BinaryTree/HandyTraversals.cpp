#include <iostream>
#include <stack>
using namespace std;

/*
Time Complexity for all traversals (recursive and iterative): O(n), where n is the number of nodes in the tree.
Space Complexity:
Recursive:
O(h), where h is the height of the tree. This is due to the space used on the call stack during recursion.
Iterative:
O(h), where h is the height of the tree. In the worst case, the stack can contain all nodes on the longest path from the root to a leaf.
*/

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

/*
*   To Store traversals in vector : 
    1) always make a helper function with vector<int> res, getting passed by reference, otherwise trvaersal will not be correct.
    2) make the helper function as void, so that it is easy for us to write the base case
    3) eg . In inorder traversal , we traver left, then we push (root->val) in vector and then again we traverse right.
*/

//Eg. of inorder traversal to store in vector

    void findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inorderTraversal(root,inorder);
    }

    void inorderTraversal(TreeNode* root, vector<int> &inorder){
        if(root == NULL) return;
        inorderTraversal(root->left,inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right,inorder);
    }

// Recursive Traversals

void inorderRecursive(Node* root) {
    if (root == nullptr) return;
    inorderRecursive(root->left);
    cout << root->data << " ";
    inorderRecursive(root->right);
}

void preorderRecursive(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

void postorderRecursive(Node* root) {
    if (root == nullptr) return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    cout << root->data << " ";
}

// Iterative Traversals

void inorderIterative(Node* root) {
    stack<Node*> s;
    Node* curr = root;
    while (curr != nullptr || !s.empty()) {
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void preorderIterative(Node* root) {
    if (root == nullptr) return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        cout << curr->data << " ";
        if (curr->right) s.push(curr->right);
        if (curr->left) s.push(curr->left);
    }
}

void postorderIterative(Node* root) {
    if (root == nullptr) return;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);
        if (curr->left) s1.push(curr->left);
        if (curr->right) s1.push(curr->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main() {
    // Construct a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder Recursive: ";
    inorderRecursive(root);
    cout << endl;

    // Add other traversals here 

    return 0;
}