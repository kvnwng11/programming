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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p and !q)
            return 1;
        if (!p or !q)
            return 0;
        if (p->val != q->val)
            return 0;
        
        deque<TreeNode*> nodes1;
        deque<TreeNode*> nodes2;

        nodes1.push_back(p);
        nodes2.push_back(q);

        while (!(nodes1.empty() and nodes2.empty())) {
            TreeNode* curr1 = nodes1.front();
            TreeNode* curr2 = nodes2.front();

            nodes1.pop_front();
            nodes2.pop_front();

            // check if equal
            if (curr1->val != curr2->val)
                return 0;
            
            // add left
            if (curr1->left and curr2->left) {
                nodes1.push_back(curr1->left);
                nodes2.push_back(curr2->left);
            }
            else if (curr1->left or curr2->left) {
                return 0;
            }

            // add right
            if (curr1->right and curr2->right) {
                nodes1.push_back(curr1->right);
                nodes2.push_back(curr2->right);
            }
            else if (curr1->right or curr2->right) {
                return 0;
            }
        }

        return 1;
    }
};