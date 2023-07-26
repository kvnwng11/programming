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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        deque<TreeNode *> nodes;
        nodes.push_back(root);
        int level = 0;
        while (!nodes.empty())
        {
            vector<int> v;
            ans.push_back(v);
            int size = nodes.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *curr = nodes.front();
                nodes.pop_front();
                if (level % 2 == 0)
                {
                    ans[ans.size() - 1].push_back(curr->val);
                }
                else
                {
                    ans[ans.size() - 1].insert(ans[ans.size() - 1].begin(), curr->val);
                }

                if (curr->left)
                    nodes.push_back(curr->left);
                if (curr->right)
                    nodes.push_back(curr->right);
            }

            level++;
        }

        return ans;
    }
};