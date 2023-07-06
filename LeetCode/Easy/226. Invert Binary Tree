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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return nullptr;

        deque<TreeNode*> nodes;
        nodes.push_back(root);

        while (!nodes.empty()) {
            TreeNode* curr = nodes.front();
            nodes.pop_front();

            TreeNode* tmp = curr->left;
            curr->left = curr->right;
            curr->right = tmp;

            if (curr->left) nodes.push_back(curr->left);
            if (curr->right) nodes.push_back(curr->right);
        }

        
        return root;
    }
};