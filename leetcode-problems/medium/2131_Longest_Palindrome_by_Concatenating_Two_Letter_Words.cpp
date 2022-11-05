class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> diffs, sames;
        for (auto word : words) {
            if (word[0] == word[1]) {
                sames[word]++;
            }
            else {
                diffs[word]++;
            }
        }
        int ans = 0;
        for (auto [word, count] : diffs) {
            string back_word = "";
            back_word += word[1];
            back_word += word[0];
            if (diffs.count(word) == 0) continue;
            if (diffs.count(back_word) == 0) continue;
            int mn = min(diffs[word], diffs[back_word]);
            ans += (mn * 4);
            diffs[word] -= mn;
            diffs[back_word] -= mn;
        }
        for (auto [word, count] : sames) {
            if (count % 2 == 0) ans += (count * 2);
            else                ans += ((count - 1) * 2);
            sames[word] = sames[word] % 2;
        }
        for (auto [word, count] : sames) {
            if (count == 1) {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};