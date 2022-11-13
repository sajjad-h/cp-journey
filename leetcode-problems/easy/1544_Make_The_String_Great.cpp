class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (stk.empty()) {
                stk.push(s[i]);
                continue;
            }
            if (abs(stk.top() - s[i]) == 32) {
                stk.pop();
            }
            else {
                stk.push(s[i]);
            }
        }
        string ans = "";
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};