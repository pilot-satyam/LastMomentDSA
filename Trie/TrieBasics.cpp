#include<bits/stdc++.h>
using namespace std;

/**
 * Explanation of the Trie Class:
    1)Insert Function (insert):

    We loop through each character in the word.
    For each character, we check if it exists as a child of the current node.
    If it doesn't exist, we create a new node.
    Finally, after processing all characters, we mark the last node as the end of a word.


    2)Search Function (search):

    We check if we can follow the sequence of characters in the Trie.
    If any character is not found, we return false.
    At the end, we check if the last node marks the end of a word.

    3)Prefix Function (startsWith):

    This is useful for checking if there is any word in the Trie that starts with a given prefix.
    We traverse through the prefix characters, and if we can follow them, we return true. 
 */

struct TrieNode{
    unordered_map<char,TrieNode*> children; //for storing children nodes
    bool isEndOfWord; //to check if this is end of word
    TrieNode(){
        isEndOfWord = false;
    }
};

class Trie{
    TrieNode *root; //root node of trie
    public:
    Trie(){
        root = new TrieNode(); //creating root node
    }

    //inserting word in trie
    void insert(const string &word){
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

    //searching for a word

    bool search(const string &word){
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

    bool startsWith(const string &prefix){
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

int main(){

    Trie trie;

    trie.insert("apple");
    trie.insert("app");

    cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search 'appl': " << (trie.search("appl") ? "Found" : "Not Found") << endl;
    cout << "Starts with 'app': " << (trie.startsWith("app") ? "Yes" : "No") << endl;

    return 0;

}