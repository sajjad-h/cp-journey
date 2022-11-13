class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
        int i = 0, j = 0;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        j = i + 1;
        while (j < s.size()) {
            if (s[j] == ' ') {
                if (i < j) {
                    reverse(s.begin() + i, s.begin() + j);
                    i = j;
                    while (i < s.size() && s[i] == ' ') {
                        i++;
                    }
                }
            }
            j++;
        }
        if (i < j) {
            reverse(s.begin() + i, s.begin() + j);
        }
        i = 0, j = 0;
        int okay = 0;
        while (j < s.size()) {
            while (j < s.size() && s[j] == ' ') j++;
            if (okay && i < s.size()) {
                s[i++] = ' ';
            }
            okay = 0;
            while (j < s.size() && s[j] != ' ') {
                s[i++] = s[j++];
                okay = 1;
            }
        }
        if (s[i - 1] == ' ') i--;
        return s.substr(0, i);
    }
};