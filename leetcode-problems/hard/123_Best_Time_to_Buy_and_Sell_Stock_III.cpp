class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> suffixProfit(n + 2, 0);
        int mx = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixProfit[i] = max(suffixProfit[i + 1], mx - prices[i]);
            mx = max(mx, prices[i]);
        }
        int ans = 0;
        int mn = prices[0];
        for (int i = 1; i < n; i++) {
            ans = max(ans, prices[i] - mn + suffixProfit[i + 1]);
            mn = min(mn, prices[i]);
        }
        return ans;
    }
};