#include "../includes.h"

using namespace std;


class TrieNode {
    public:
    TrieNode * children[26]{}; // specify to not intialize it to garbage
    bool eow;

    TrieNode(): eow{false} {}


class Trie{
    public:
    TrieNode * root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {

        TrieNode *node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new TrieNode();
            }

            node = node->children[c - 'a'];
        }
        
        // marking eow (end of word) does not mean that this is a leaf node
        // e.g. "app" is a prefix of "apple", so node for 'p' in "app" is not a leaf, but is still marked as eow
        node->eow = true;


    }

    bool search(string word) {
        TrieNode * node = root;

        for (char c : word) {
            if (!node->children[c - 'a']) {
                return false;
            }
            node = node->children[c - 'a'];
        }

        return node->eow;
    }

    // function is used to find the smallest word in the trie that is a prefix of the given word 
    string check(string word){
        TrieNode *t = root;
        string s = "";
        
        for(auto i : word){
            if(!t->children[i-'a']) break;
            s += i;
            t = t->children[i-'a'];
            if(t->eow) return s;
        }
        return word;
    }
};
