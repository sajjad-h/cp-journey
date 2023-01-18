class Solution {
public:

    int orientation(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
        auto [ax, ay] = a;
        auto [bx, by] = b;
        auto [cx, cy] = c;
        int d = (ay - by) * (bx - cx) - (ax - bx) * (by - cy);
        if (d == 0) return 0; // collinear
        else if (d > 0) return 1; // clockwise
        else return 2; // counter-clockwise
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        int l = 0;
        for (int i = 0; i < n; i++) {
            if (trees[i][0] == trees[l][0] && trees[i][1] < trees[l][1]) {
                l = i;
            }
            else if (trees[i][0] < trees[l][0]) {
                l = i;
            }
        }
        int p = l;
        vector<int> used(n, 0);
        vector<vector<int>> hull;
        vector<int> pp;
        do {
            pp.push_back(p);
            hull.push_back(trees[p]);
            int q = (p + 1) % n;
            for (int i = 0; i < n; i++) {
                if (used[i]) continue;
                if (orientation( { trees[p][0], trees[p][1] }, { trees[i][0], trees[i][1] }, {trees[q][0], trees[q][1]} ) == 2) {
                    q = i;
                }
            }
            p = q;
            used[p] = 1;
        } while (p != l);
        pp.push_back(l);
        for (int i = 1; i < pp.size(); i++) {
            for (int j = 0; j < n; j++) {
                if (used[j]) continue;
                if (orientation( {trees[pp[i - 1]][0], trees[pp[i - 1]][1]}, {trees[j][0], trees[j][1]}, {trees[pp[i]][0], trees[pp[i]][1]} ) == 0) {
                    hull.push_back(trees[j]);
                    used[j] = 1;
                }
            }
        }
        return hull;
    }
};