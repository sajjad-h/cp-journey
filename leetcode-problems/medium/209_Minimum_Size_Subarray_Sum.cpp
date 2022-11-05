class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long int sum = 0;
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            int lo = 1;
            int hi = i;
            int res = INT_MAX;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                int d = pre[i] - pre[mid - 1];
                if (d >= target) {
                    res = min(res, i - mid + 1);
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
            ans = min(ans, res);
        }
        if (ans == INT_MAX) ans = 0;
        return ans;
    }
};