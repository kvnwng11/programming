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
    int getDepth(TreeNode *p) {
        int depth = 0;
        while (p->left) {
            ++depth;
            p = p->left;
        }
        return depth;
    }

    bool exists(int idx, int depth, TreeNode* p) {
        int left = 0, right = pow(2, depth)-1;

        for (int i=0; i<depth; ++i) {
            int mid = left + (right-left)/2;
            if (idx <= mid) {
                p = p->left;
                right = mid;
            }
            else {
                p = p->right;
                left = mid+1;
            }
        }

        return p;
    }

public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        if (!root->left and !root->right) return 1;
        int depth = getDepth(root);
        int left = 1, right = pow(2, depth) - 1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (exists(mid, depth, root)) left = mid+1;
            else right = mid-1;
        }
        return pow(2, depth) - 1 + left;
    }
};