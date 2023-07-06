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
    unordered_map<int, int> m;

    TreeNode* helper(vector<int> &inorder, int left, int right) {
        if (left == right-1) return new TreeNode(inorder[left]);
        if (left >= right) return nullptr;

        int num;
        int idx = INT_MAX;
        int a = INT_MAX;
        for (int i=left; i<right; ++i) {
            if (m[inorder[i]] < idx) {
                idx = m[inorder[i]];
                num = inorder[i];
                a = i;
            }
        }

        TreeNode* new_root = new TreeNode(num);
        new_root->left = helper(inorder, left, a);
        new_root->right = helper(inorder, a+1, right);
        return new_root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0; i<preorder.size(); ++i) {
            m[preorder[i]] = i;
        }

        return helper(inorder, 0, inorder.size());
    }
};