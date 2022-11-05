class Solution {
    vector<int> dp[2];
public:
    int solve(vector<int>& prices, int at, int flag) {
        //cout << at << " " << last << " " << flag << "\n";
        if (at == prices.size()) {
            return 0;
        }

        if (dp[flag][at] != -1) return dp[flag][at];
        int ans = INT_MIN;
        if (flag == 0) {
            ans = max(ans, solve(prices, at + 1, 0));
            ans = max(ans, -prices[at] + solve(prices, at + 1, 1));
        }
        else {
            ans = max(ans, solve(prices, at + 1, 1));
            ans = max(ans, prices[at] + solve(prices, at + 1, 0));
        }
        return dp[flag][at] = ans;
    }
    
    int maxProfit(vector<int>& prices) {
        dp[0] = vector<int>(prices.size(), -1);
        dp[1] = vector<int>(prices.size(), -1);
        return solve(prices, 0, 0);
    }
};