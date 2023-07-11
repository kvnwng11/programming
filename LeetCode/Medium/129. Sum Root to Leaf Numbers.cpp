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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        deque<pair<TreeNode*, int>> d;
        d.push_back(make_pair(root, 0));

        while (!d.empty()) {
            pair<TreeNode*, int> curr = d.front();
            d.pop_front();

            TreeNode* node = curr.first;
            int newSum = curr.second *10 + node->val;
            if (!node->left and !node->right) ans += newSum;

            if (node->right) d.push_back(make_pair(node->right, newSum));
            if (node->left) d.push_back(make_pair(node->left, newSum));
        }

        return ans;
    }
};