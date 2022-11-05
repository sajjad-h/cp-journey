class Solution {
public:
    
    pair<int, int> getPoint(int n, int m, int p) {
        int x = p / m;
        int y = p % m;
        return {x, y};
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int lo = 0;
        int hi = n * m - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            auto [x, y] = getPoint(n, m, mid);
            if (matrix[x][y] == target) return true;
            if (matrix[x][y] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
    }
};