/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    Node* leftmost;
    Node* prev;

    void helper(Node *p) {
        if (p) {
            if (prev) prev->next = p;
            else leftmost = p;

            prev = p;
        }
    }

public:
    Node* connect(Node* root) {
        if (!root) return root;

        leftmost = root;
        Node* curr = leftmost;

        while (leftmost) {
            prev = nullptr;
            curr = leftmost;
            leftmost = nullptr;

            while (curr) {
                helper(curr->left);
                helper(curr->right);

                curr = curr->next;
            }
        }

        return root;
    }
};