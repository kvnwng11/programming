struct Node {
    int key;
    int val;
    Node *left;
    Node *right;
    Node(int k, int v) : key{k}, val{v}, left(nullptr), right(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> elts;
    Node *start = new Node(-1, -1);
    Node *end = new Node(-1, -1);
    int size;

    void remove(Node *node) {
        node->left->right = node->right;
        node->right->left = node->left;
    }

    void add(Node *n) {
        Node *prevEnd = end->left;
        prevEnd->right = n;
        n->left = prevEnd;
        n->right = end;
        end->left = n;
    }
    
public:
    LRUCache(int capacity) : size{capacity} {
        start->right = end;
        end->left = start;
    }
    
    int get(int key) {
        if (elts.find(key) == elts.end())
            return -1;

        Node* node = elts[key];
        remove(node);
        add(node);
        return node->val;
    }
    
    void put(int key, int value) {
        // update
        if (elts.find(key) != elts.end()) {
            Node *old = elts[key];
            remove(old);
        }
        
        Node *n = new Node(key, value);
        elts[key] = n;
        add(n);
        
        // evict
        if (elts.size() > size) {
            Node *toRemove = start->right;
            remove(toRemove);
            elts.erase(toRemove->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */