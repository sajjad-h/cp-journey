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
    bool isValidBST(TreeNode* root, long long int min = INT_MIN, long long int max = INT_MAX) {
        if (root == NULL) return true;
        if (!(root->val >= min && root->val <= max) || min > max) return false;
        return (isValidBST(root->left, min, root->val - 1LL) && isValidBST(root->right, root->val + 1LL, max));
    }
};