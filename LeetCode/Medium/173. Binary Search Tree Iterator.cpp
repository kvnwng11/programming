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
class BSTIterator {
private:
    deque<TreeNode*> nodes;

    void getLeftmost(TreeNode* p) {
        while (p) {
            nodes.push_back(p);
            p = p->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        getLeftmost(root);
    }
    
    int next() {
        TreeNode* p = nodes.back();
        nodes.pop_back();
        if (p->right) getLeftmost(p->right);
        return p->val;
    }
    
    bool hasNext() {
        return nodes.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */