class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0}); // (t, r, c)
        while (!pq.empty()) {
            auto cur = pq.top();
            int t = cur[0], r = cur[1], c = cur[2];
            pq.pop();
            if (r == m - 1 && c == n - 1) {
                return t;
            }
            if (visited[r][c]) {
                continue;
            }
            visited[r][c] = true;
            for (const auto& dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]) {
                    continue;
                }
                bool wait = (grid[nr][nc] - t) % 2 == 0;
                int nt = max(grid[nr][nc] + wait, t + 1);
                pq.push({nt, nr, nc});
            }
        }
        return -1;
    }
};