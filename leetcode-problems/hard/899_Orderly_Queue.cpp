class Solution {
public:
    string orderlyQueue(string s, int k) {
        int index = 0;
        if (k == 1) {
            for (int i = 0; i < s.size(); i++) {
                int l = i;
                for (int j = 0; j < s.size(); j++) {
                    if (l == s.size()) l = 0;
                    if (s[l] < s[(index + j) % s.size()]) {
                        index = i;
                        break;
                    }
                    else if (s[l] > s[(index + j) % s.size()]) {
                        break;
                    }
                    else {
                        l++;
                    }
                }
            }
            s = s.substr(index, s.size() - index) + s.substr(0, index);
        }
        else {
            sort(s.begin(), s.end());
        }
        return s;
    }
};