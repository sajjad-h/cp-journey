class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (st.find(nums[i]) == st.end()) {
                st.insert(nums[i]);
                continue;
            }
            return nums[i];
        }
        assert(false);
        return 0;
    }
};