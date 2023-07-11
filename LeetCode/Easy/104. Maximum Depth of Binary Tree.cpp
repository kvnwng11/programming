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
private:

public: 
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        deque<pair<TreeNode*, int>> nodes;
        nodes.push_back(make_pair(root, 1));
        int ans = 1;

        while (!nodes.empty()) {
            pair<TreeNode*, int> curr = nodes.front();
            nodes.pop_front();

            ans = max(curr.second, ans);

            if (curr.first->left)
                nodes.push_back(make_pair(curr.first->left, curr.second+1));
            if (curr.first->right)
                nodes.push_back(make_pair(curr.first->right, curr.second+1));
        }

        return ans;
    }
};