class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return mid;
            if (mid + 1 < n && nums[mid] < nums[mid + 1]) {
                if (nums[mid] < nums[n - 1]) {
                    if (nums[mid] <= target && target <= nums[n - 1]) {
                        lo = mid + 1;
                    }
                    else {
                        hi = mid - 1;
                    }
                }
                else {
                    if (nums[0] <= target && target <= nums[mid]) {
                        hi = mid - 1;
                    }
                    else {
                        lo = mid + 1;
                    }
                }
            }
            else {
                if (nums[0] <= target && target <= nums[mid]) {
                    hi = mid - 1;
                }
                else {
                    lo = mid + 1;
                }
            }
        }
        return -1;
    }
};