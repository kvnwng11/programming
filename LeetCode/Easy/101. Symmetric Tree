/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // easy cases
        if (!root) return 1;
        if (!root->left and !root->right) return 1;
        if (!root->right and root->left) return 0;
        if (!root->left and root->right) return 0;
        
        // deque approach
        deque<TreeNode*> lefts;
        deque<TreeNode*> rights;
        lefts.push_back(root->left);
        rights.push_back(root->right);

        while (!lefts.empty() and !rights.empty()) {
            // check two nodes at a time
            TreeNode* left = lefts.front();
            TreeNode* right = rights.front();
            lefts.pop_front();
            rights.pop_front();

            // symmetry check
            if (left->val != right->val) return 0;
            if (!left->left and right->right) return 0;
            if (!left->right and right->left) return 0;
            if (left->left and !right->right) return 0;
            if (left->right and !right->left) return 0;

            // add new nodes to queue
            if (left->left) lefts.push_back(left->left);
            if (right->right) rights.push_back(right->right);

            if (left->right) rights.push_back(left->right);
            if (right->left) lefts.push_back(right->left);
        }

        if (!lefts.empty() or !rights.empty()) return 0;

        return 1;
    }
};