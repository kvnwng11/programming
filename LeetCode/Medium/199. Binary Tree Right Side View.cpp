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
  private:
    vector<int> ans;

    void helper(TreeNode *node, int level)
    {
        if (!node)
            return;
        if (level == ans.size())
            ans.push_back(node->val);
        if (node->right)
            helper(node->right, level + 1);
        if (node->left)
            helper(node->left, level + 1);
    }

  public:
    vector<int> rightSideView(TreeNode *root)
    {
        helper(root, 0);
        return ans;
    }
};