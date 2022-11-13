
class Solution {
public:
    
    int checkPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return 0;
            l++;
            r--;
        }
        return 1;
    }
    
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = k - 1; i < n; i++) {
            dp[i + 1] = dp[i];
            if (checkPalindrome(s, i - k + 1, i)) dp[i + 1] = max(dp[i + 1], 1 + dp[i + 1 - k]);
            if (i - k >= 0 && checkPalindrome(s, i - k, i)) dp[i + 1] = max(dp[i + 1], 1 + dp[i - k]);
        }
        return dp[n];
    }
};