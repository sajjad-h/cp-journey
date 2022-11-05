class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> ends(10004, 0);
        sort(intervals.begin(), intervals.end());
        vector<int> v;
        for (auto range : intervals) {
            int x = range[0];
            int y = range[1];
            if (v.size() == 0 || v.back() < x) {
                v.push_back(y);
                ends[y] = x;
            }
            else if (v.back() < y) {
                int y_dash = v.back();
                v.pop_back();
                v.push_back(y);
                ends[y] = ends[y_dash];
            }
        }
        vector<vector<int>> ans;
        for (auto x : v) {
            ans.push_back({ends[x], x});
        }
        return ans;
    }
};