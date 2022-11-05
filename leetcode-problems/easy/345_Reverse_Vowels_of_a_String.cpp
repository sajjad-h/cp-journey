class Solution {
public:

    int isVowel(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A') + 'a';
        }
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;
        return 0;
    }

    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            while (i < s.size() && !isVowel(s[i])) i++;
            while (j >= 0 && !isVowel(s[j])) j--;
            if (i <= j) {
                swap(s[i], s[j]);
            }
            i++;
            j--;
        }
        return s;
    }
};