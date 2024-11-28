class Solution {
public:
    vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minimumObstacles(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> vis(m, vector<int>(n, INT_MIN));
        priority_queue<array<int, 3>> pq;
        pq.push({0, 0, 0});
        vis[0][0] = 0;
        while (!pq.empty() && (pq.top()[1] != m - 1 || pq.top()[2] != n - 1)) {
            auto [obs, i, j] = pq.top(); pq.pop();
            if (obs > vis[i][j])
                continue;
            for (auto [dx, dy] : dirs) {
                int x = i + dx, y = j + dy;
                if (min(x, y) >= 0 && x < m && y < n)
                    if (vis[x][y] < obs - g[x][y]) {
                        vis[x][y] = obs - g[x][y];
                        pq.push({obs - g[x][y], x, y});
                    }
            }
        }
        return -vis[m - 1][n - 1];
    }
};