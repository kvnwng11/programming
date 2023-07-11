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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // easy case
        if (!root) return 0;

        // iterative approach
        deque<pair<TreeNode*, int>> d;
        d.push_back(make_pair(root, targetSum));
        while (!d.empty()) {
            pair<TreeNode*, int> curr = d.front();
            d.pop_front();

            // if path sum found
            TreeNode* node = curr.first;
            int newSum = curr.second - node->val;
            if (!node->left and !node->right and newSum == 0) return 1;

            // add to deque
            if (node->left) d.push_back(make_pair(node->left, newSum));
            if (node->right) d.push_back(make_pair(node->right, newSum));
        }

        return 0;
    }
};
 