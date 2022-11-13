class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (stk.empty()) {
                stk.push(s[i]);
            }
            else if (stk.top() == s[i]) {
                stk.pop();
            }
            else {
                stk.push(s[i]);
            }
        }
        s = "";
        while (!stk.empty()) {
            s.push_back(stk.top()); stk.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};