class Solution {
public:
        vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> order1 = GenerateTopologicalSort(rowConditions, k);
        vector<int> order2 = GenerateTopologicalSort(colConditions, k);
        if (order1.size() < k || order2.size() < k) return {};
        unordered_map<int, int> m;
        for (int i = 0; i < k; i++) m[order2[i]] = i;
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++)
            ans[i][m[order1[i]]] = order1[i];
        return ans;
    }
vector<int> GenerateTopologicalSort(vector<vector<int>> &A, int k) {
        vector<int> deg(k, 0), order;
        vector<vector<int>> graph(k, vector<int>(0));
        queue<int> q;
        for (auto &c: A) {
            graph[c[0] - 1].push_back(c[1] - 1);
            deg[c[1] - 1]++;
        }
        for(int i = 0; i < k; i++) 
            if (!deg[i]) q.push(i);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            order.push_back(x + 1);
            for (int& y: graph[x]) 
                if (--deg[y] == 0) 
                    q.push(y);
        }
        return order;
    }
};