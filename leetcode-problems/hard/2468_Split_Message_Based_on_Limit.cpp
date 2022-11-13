class Solution {
public:
    
    int sizeOfInteger(int x) {
        int cnt = 0;
        while (x != 0) {
            cnt++;
            x /= 10;
        }
        return cnt;
    }
    
    vector<string> splitMessage(string message, int limit) {
        vector<int> needDigits(10004 + 5, 0);
        for (int i = 1; i <= 10000; i++) {
            needDigits[i] = needDigits[i - 1] + sizeOfInteger(i);
        }
        vector<string> ret;
        for (int ans = 1; ans <= 10000; ans++) {
            long long int total_chars = message.size();
            total_chars += (ans * 3);
            total_chars += (ans * sizeOfInteger(ans));
            total_chars += (needDigits[ans]);
            long long int partition = total_chars / limit;
            long long int barti = total_chars % limit;
            if (barti > 0) {
                if (barti < 2 * sizeOfInteger(ans) + 2) continue;
            }
            if (barti != 0) partition++;
            if (partition == ans) {
                int j = 0;
                for (int i = 1; i <= ans; i++) {
                    string s = "<" + to_string(i) + "/" + to_string(ans) + ">";
                    int need = limit - s.size();
                    string t = "";
                    while (need-- && j < message.size()) {
                        t.push_back(message[j++]);
                    }
                    ret.push_back(t + s);
                }
                return ret;
            }
        }
        return ret;
    }
};