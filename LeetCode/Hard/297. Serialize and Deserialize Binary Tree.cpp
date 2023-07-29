/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    deque<string> d;

    TreeNode* helper() {
        string s = d.front();
        d.pop_front();
        if (s == "NULL") return nullptr;
        TreeNode* curr = new TreeNode(stoi(s));
        curr->left = helper();
        curr->right = helper();
        return curr;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "NULL,";
        string left = "," + serialize(root->left);
        string right = serialize(root->right);
        return to_string(root->val) + left + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s;
        for (int i=0; i<data.size(); ++i) {
            if (data[i] == ',') {
                d.push_back(s);
                s = "";
                continue;
            }
            s += data[i];
        }
        if (s.size()) d.push_back(s);
        TreeNode* ans = helper();
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));