class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            mn = min(mn, prices[i]);
            ans = max(ans, prices[i] - mn);
        }
        return ans;
    }
};