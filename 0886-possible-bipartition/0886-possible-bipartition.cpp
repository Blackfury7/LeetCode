class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(n);
        for (const auto &dl: dislikes) {
            int u = dl[0] - 1;
            int v = dl[1] - 1;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<bool> visited(n);
        vector<int> color(n, 0);

        for (int i = 0; i < n; ++i) {
            if (!visited[i] && !dfs(g, i, i, visited, color, 1)) {
                return false;
            }
        }

        return true;
    }

    bool dfs(const vector<vector<int>> &g, int p, int s, vector<bool> &visited, vector<int> &color, int pc) {
        if (visited[s]) {
            if (s != p && color[s] == color[p]) {
                return false;
            }
            return true;
        }

        visited[s] = true;
        color[s] = -pc;

        for (auto u: g[s]) {
            if (!dfs(g, s, u, visited, color, -pc)) {
                return false;
            }
        }

        return true;
    }
};