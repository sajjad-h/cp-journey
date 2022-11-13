#define  ll   long long int
class Solution {
public:
    
int mod = 1000000007;
vector<int> dp;
    int solve(int at, int low, int high, int zero, int one) {
        if (at == high) return 1;
        if (at > high) return 0;
        if (dp[at] != -1) return dp[at];
        int ans = 0;
        if (at >= low) {
            ans = 1;
        }
        ans += solve(at + zero, low, high, zero, one); ans %= mod;
        ans += solve(at + one, low, high, zero, one); ans %= mod;
        return dp[at] = ans;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        dp = vector<int>(high + 5, -1);
        return solve(0, low, high, zero, one);
    }
};