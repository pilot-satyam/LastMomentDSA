#include<bits/stdc++.h>
using namespace std;

//Q: https://leetcode.com/problems/implement-trie-prefix-tree/?envType=study-plan-v2&envId=leetcode-75

struct TrieNode{
    unordered_map<char,TrieNode*> children; //for storing children nodes
    bool isEndOfWord; //to check if this is end of word
    TrieNode(){
        isEndOfWord = false;
    }
};

class Trie {
public:
     TrieNode *root; //root node of trie
    public:
    Trie(){
        root = new TrieNode(); //creating root node
    }
    
    void insert(string word) {
        TrieNode* curr = root; 
        for(auto c : word){
            //if character is not present in map then create new node
            if(curr->children.find(c) == curr->children.end()){
                curr->children[c] = new TrieNode();
            }
            //move to child node
            curr = curr->children[c];
        }
        curr->isEndOfWord = true; //marking end of word
    }
    
    bool search(string word) {
         TrieNode* curr = root;
        for(auto c : word){
            //if char not found return false
            if(curr->children.find(c) == curr->children.end()){
                return false;
            }
            //else moving to child node
            curr = curr->children[c];
        }
        return curr->isEndOfWord; //returning true if current node is the end
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto c : prefix){
            //if char not found, return false
            if(curr->children.find(c) == curr->children.end()){
                return false;
            }
            //moving to child node
            curr = curr->children[c];
        }
        return true; //returning true if prefix is found
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){

}