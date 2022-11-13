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

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root != NULL) q.push(root);
        while (!q.empty()) {
            vector<int> us;
            vector<TreeNode*> vs;
            while (!q.empty()) {
                auto root = q.front(); q.pop();
                us.push_back(root->val);
                if (root->left != NULL) vs.push_back(root->left);
                if (root->right != NULL) vs.push_back(root->right);
            }
            for (auto x : vs) {
                q.push(x);
            }
            ans.push_back(us);
        }
        return ans;
    }
};