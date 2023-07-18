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
class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        deque<TreeNode *> nodes;
        nodes.push_back(root);
        while (!nodes.empty())
        {
            vector<int> lvl;
            ans.push_back(lvl);
            int size = nodes.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *curr = nodes.front();
                nodes.pop_front();
                ans[ans.size() - 1].push_back(curr->val);
                if (curr->left)
                    nodes.push_back(curr->left);
                if (curr->right)
                    nodes.push_back(curr->right);
            }
        }

        return ans;
    }
};