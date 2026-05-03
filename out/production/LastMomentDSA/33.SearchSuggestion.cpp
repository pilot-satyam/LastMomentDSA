#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    vector<string> suggestions;  // List of words with this prefix
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a product into the Trie
    void insert(const string& product) {
        TrieNode* node = root;
        for (char c : product) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            
            // Maintain a sorted list of products at each node
            node->suggestions.push_back(product);
            sort(node->suggestions.begin(), node->suggestions.end());
            if (node->suggestions.size() > 3) {
                node->suggestions.pop_back();
            }
        }
    }
    
    // Get suggestions for a given prefix
    vector<string> getSuggestions(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children.count(c)) {
                return {};  // No suggestions if this prefix doesn't exist
            }
            node = node->children[c];
        }
        return node->suggestions;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // Step 1: Insert all products into the Trie
        Trie trie;
        for (const string& product : products) {
            trie.insert(product);
        }

        // Step 2: Generate suggestions for each prefix of searchWord
        vector<vector<string>> result;
        string prefix = "";
        for (char c : searchWord) {
            prefix += c;
            result.push_back(trie.getSuggestions(prefix));
        }
        
        return result;
    }
};

int main(){

}