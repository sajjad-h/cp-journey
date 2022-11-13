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
    int ans = 0;
    
    int solve(TreeNode* root) {
        if (root == NULL) return 0;
        int p1 = max(0, solve(root->left));
        int p2 = max(0, solve(root->right));
        ans = max(ans, p1 + p2 + root->val);
        return root->val + max(p1, p2);
    }

    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        solve(root);
        return ans;

    }
};