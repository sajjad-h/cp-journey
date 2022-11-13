class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int> st;
        for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
            st.insert(nums[i] + nums[j]);
        }
        return st.size();
    }
};