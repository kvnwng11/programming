
class Trie {
private:
    struct TrieNode {
        bool isEnd = false;
        vector<TrieNode*> links = vector<TrieNode*>(26, nullptr);
        TrieNode() {}
    };

    TrieNode *root = new TrieNode;

public:
    Trie() {}
    
    void insert(string word) {
        TrieNode *node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->links[idx])
                node->links[idx] = new TrieNode;
            node = node->links[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->links[idx])
                return false;
            node = node->links[idx];
        }
        return node and node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->links[idx])
                return false;
            node = node->links[idx];
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */