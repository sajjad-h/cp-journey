class Solution {
public:
    
    string numberToString(int num) {
        string res = "";
        while (num != 0) {
            res.push_back(((num % 10) + '0'));
            num /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    string nextTerm(string s) {
        int n = s.size();
        int c = 1;
        char pre = s[0];
        string ans = "";
        for (int i = 1; i < n; i++) {
            if (pre == s[i]) c++;
            else {
                ans += numberToString(c);
                ans += pre;
                pre = s[i];
                c = 1;
            }
        }
        if (c) {
            ans += numberToString(c);
            ans += pre;
        }
        return ans;
    }
    
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 2; i <= n; i++) {
            ans = nextTerm(ans);
        }
        return ans;
    }
};