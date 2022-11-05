class Solution {
public:
    
    int solve(int x, int y, int n, int m, vector<vector<int>>& grid) {
        if (x == n) return y;
        if (grid[x][y] == 1 && y + 1 < m && grid[x][y + 1] == 1) 
            return solve(x + 1, y + 1, n, m, grid);
        else if (grid[x][y] == -1 && y - 1 >= 0 && grid[x][y - 1] == -1) 
            return solve(x + 1, y - 1, n, m, grid);
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            ans[i] = solve(0, i, n, m, grid);
        }
        return ans;
    }
};