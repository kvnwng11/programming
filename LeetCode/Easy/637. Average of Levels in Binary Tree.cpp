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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (!root) return ans;

        deque<TreeNode*> nodes;
        nodes.push_back(root);

        double sum = 0;
        while (!nodes.empty()) {
            int size = nodes.size();
            for (int i=0; i<size; ++i) {
                TreeNode* curr = nodes.front();
                nodes.pop_front();
                sum += curr->val;

                if (curr->left) nodes.push_back(curr->left);
                if (curr->right) nodes.push_back(curr->right);
            }

            ans.push_back(sum / size);
            sum = 0;
        }
        return ans;
    }
};