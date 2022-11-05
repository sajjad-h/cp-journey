class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for (auto x : nums) {
            mp[x]++;
        }
        vector<int> ans;
        for (auto [x, c] : mp) {
            if (c > (n / 3)) ans.push_back(x);
        }
        return ans;
    }
};