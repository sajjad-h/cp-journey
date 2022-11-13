class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        vector< vector<pair<int, int>> > divs;
        for (auto x : nums) {
            vector< pair<int, int> > div;
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    int c = 0;
                    while (x % i == 0) {
                        c++;
                        x /= i;
                    }
                    div.push_back({i, c});
                }
            }
            if (x > 1) {
                div.push_back({x, 1});
            }
            divs.push_back(div);
        }
        map<int, int> freq;
        int x = k;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                int c = 0;
                while (x % i == 0) {
                    c++;
                    x /= i;
                }
                freq[i] = c;
            }
        }
        if (x > 1) {
            freq[x] = 1;
        }
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int okay = 1;
            map<int, int> mp;
            for (int j = i; j >= 0; j--) {
                for (int k = 0; okay && k < divs[j].size(); k++) {
                    int x = divs[j][k].first;
                    int c = divs[j][k].second;
                    mp[x] = max(mp[x], c);
                    if (freq.find(x) == freq.end()) {
                        okay = 0;
                        break;
                    }
                    else if (freq[x] < mp[x]) {
                        okay = 0;
                        break;
                    }
                }
                int flag = 1;
                if (freq.size() != mp.size()) flag = 0;
                for (auto it : freq) {
                    int x = it.first;
                    int c = it.second;
                    if (mp.find(x) == mp.end()) {
                        flag = 0;
                        break;
                    }
                    else if (mp[x] != freq[x]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) ans++;
            }
        }
        return ans;
    }
};