/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> checked;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        if (checked.find(node) != checked.end()) return checked[node];
        
        vector<Node*> neighbors;
        Node* ans = new Node(node->val, neighbors);
        checked[node] = ans;
        for (Node* neighbor : node->neighbors) {
            ans->neighbors.push_back(cloneGraph(neighbor));
        }

        return ans;
    }
};