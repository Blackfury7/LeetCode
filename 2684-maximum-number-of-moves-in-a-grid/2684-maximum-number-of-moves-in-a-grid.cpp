class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {1, 1}, {-1, 1}};
        vector<vector<int>> cache(m, vector<int>(n, -1));

        function<int(int, int)> dp = [&](int i, int j) {
            if (cache[i][j] != -1) return cache[i][j];
            int ans = 0;
            for (auto [x, y] : dirs) {
                int ni = i + x, nj = j + y;
                if (ni >= 0 && ni < m && nj < n && grid[i][j] < grid[ni][nj])
                    ans = max(ans, 1 + dp(ni, nj));
            }
            return cache[i][j] = ans;
        };
        int res = 0;
        for (int i = 0; i < m; i++)
            res = max(res, dp(i, 0));
        return res;
    }
};