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
    unordered_map<int, int> m;
    int post_idx;

    TreeNode *helper(vector<int> & inorder, vector<int> & postorder, int left, int right) {
        if (left > right) return nullptr;

        int k = postorder[post_idx];
        int index = m[k];

        TreeNode *new_node = new TreeNode(k);
        post_idx--;
        new_node->right = helper(inorder, postorder, index+1, right);
        new_node->left = helper(inorder, postorder, left, index-1);
        return new_node;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i=0; i<inorder.size(); ++i) {
            m[inorder[i]] = i;
        }
        post_idx = postorder.size()-1;
        return helper(inorder, postorder, 0, postorder.size()-1);
    }
};