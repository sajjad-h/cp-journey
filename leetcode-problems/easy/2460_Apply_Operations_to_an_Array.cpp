class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) {
                nums[i - 1] *= 2;
                nums[i] = 0;
            }
        }
        vector<int> ans;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) count++;
            else {
                ans.push_back(nums[i]);
            }
        }
        while (count--) {
            ans.push_back(0);
        }
        return ans;
    }
};