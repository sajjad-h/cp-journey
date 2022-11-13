class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        set<int> st;
        vector<int> freq(100005, 0);
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            st.insert(nums[i]);
            sum += nums[i];
            freq[nums[i]]++;
        }
        long long ans = 0;
        if (st.size() == k) {
            ans = max(ans, sum);
        }
        for (int i = k; i < nums.size(); i++) {
            freq[nums[i - k]]--;
            if (freq[nums[i -  k]] == 0) st.erase(nums[i - k]);
            st.insert(nums[i]);
            freq[nums[i]]++;
            sum -= nums[i - k];
            sum += nums[i];
            if (st.size() == k) {
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};