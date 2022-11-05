class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for (int i =  n - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                int mn = INT_MAX;
                int mni = -1;
                for (int j = i; j < n; j++) {
                    if (nums[j] > nums[i - 1]) {
                        if (mn >= nums[j]) {
                            mn = nums[j];
                            mni = j;
                        }
                    }
                }
                swap(nums[i - 1], nums[mni]);
                reverse(nums.begin() + i, nums.end());
                return ;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};