class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) {
                continue;
            }
            nums[j++] = nums[i];
        }
        return j;
    }
};