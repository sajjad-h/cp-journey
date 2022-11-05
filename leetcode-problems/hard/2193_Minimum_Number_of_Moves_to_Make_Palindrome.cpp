class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ans = 0;
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
                continue;
            }
            
            int way1 = INT_MAX;
            int i1 = -1;
            for (int k = i + 1; k < j; k++) {
                if (s[k] == s[j]) {
                    i1 = k;
                    way1 = k - i;
                    break;
                }
            }
            
            int way2 = INT_MAX;
            int j1 = -1;
            for (int k = j - 1; k > i; k--) {
                if (s[k] == s[i]) {
                    j1 = k;
                    way2 = j - k;
                    break;
                }
            }
            
            if (way1 < way2) {
                for (int k = i1 - 1; k >= i; k--) {
                    swap(s[k], s[k + 1]);
                }
                ans += way1;
            }
            else {
                for (int k = j1 + 1; k <= j; k++) {
                    swap(s[k], s[k - 1]);
                }
                ans += way2;
            }
            i++;
            j--;
        }
        return ans;
    }
};