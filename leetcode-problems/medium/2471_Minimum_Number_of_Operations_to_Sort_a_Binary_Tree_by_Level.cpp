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
   
    int minimumSwaps(vector<int>& ara) {
        int n = ara.size();
        int ans = 0;
        vector<int>temp = ara;
        map<int, int> mp;
        sort(temp.begin(), temp.end());
        for (int i = 0; i < n; i++) {
            mp[ara[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            if (ara[i] != temp[i]) {
                ans++;
                int init = ara[i];
                swap(ara[i], ara[mp[temp[i]]]);
                mp[init] = mp[temp[i]];
                mp[temp[i]] = i;
            }
        }
        return ans;
    }
    
    void dfs(TreeNode* root, int level, int& maxLevel, vector<vector<int>>& vals) {
        if (root == NULL) return ;
        if (level == maxLevel) {
            vals.push_back({root->val});
            maxLevel++;
        }
        else {
            vals[level].push_back(root->val);
        }
        dfs(root->left, level + 1, maxLevel, vals);
        dfs(root->right, level + 1, maxLevel, vals);
    }
    
    int minimumOperations(TreeNode* root) {
        vector<vector<int>> vals;
        int maxLevel = 0;
        dfs(root, 0, maxLevel, vals);
        int ans = 0;
        for (int i = 0; i < maxLevel; i++) {
            ans += minimumSwaps(vals[i]);
        }
        return ans;
    }
};