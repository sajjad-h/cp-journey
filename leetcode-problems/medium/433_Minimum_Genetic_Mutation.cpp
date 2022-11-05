class Solution {
public:
    
    int grid[11][11];
    map<string, int> mp;
    const int inf = 1e8;
    
    int isPossibleEdge(string a, string b) {
        int c = 0;
        for (int i = 0; i < 8; i++) {
            if (a[i] != b[i]) c++; 
        }
        return (c == 1);
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        mp.clear();
        for (int i = 0; i <= bank.size(); i++) {
            for (int j = 0; j <= bank.size(); j++) {
                grid[i][j] = inf;
            }
            grid[i][i] = 0;
        }
        for (int i = 0; i < bank.size(); i++) {
            mp[bank[i]] = i;
        }
        for (int i = 0; i < bank.size(); i++) {
            for (int j = i + 1; j < bank.size(); j++) {
                if (isPossibleEdge(bank[i], bank[j])) {
                    grid[i][j] = 1;
                    grid[j][i] = 1;
                }
            }
        }
        if (start == end) return 0;
        if (mp.count(end) == 0) return -1;
        for (int k = 0; k < bank.size(); k++) {
            for (int i = 0; i < bank.size(); i++) {
                for (int j = 0; j < bank.size(); j++) {
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                }
            }
        }
        if (mp.count(start)) return grid[mp[start]][mp[end]];
        string choices = "ACGT";
        int ans = inf;
        for (int i = 0; i < 8; i++) {
            for (auto ch : choices) {
                if (ch == start[i]) continue;
                char tmp = start[i];
                start[i] = ch;
                if (mp.count(start)) {
                    ans = min(ans, 1 + grid[mp[start]][mp[end]]);
                }
                start[i] = tmp;
            }
        }
        if (ans == inf) ans = -1;
        return ans;
    }
};