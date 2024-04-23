class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // Special case with only one node
        vector<int> degree(n, 0);
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> leafQueue;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) leafQueue.push(i);
        }

        int remainingNodes = n;
        while (remainingNodes > 2) {
            int leafCount = leafQueue.size();
            remainingNodes -= leafCount;
            for (int i = 0; i < leafCount; i++) {
                int leaf = leafQueue.front();
                leafQueue.pop();
                for (int neighbor : graph[leaf]) {
                    if (--degree[neighbor] == 1) {
                        leafQueue.push(neighbor);
                    }
                }
            }
        }

        vector<int> minHeightTrees;
        while (!leafQueue.empty()) {
            minHeightTrees.push_back(leafQueue.front());
            leafQueue.pop();
        }
        return minHeightTrees;
    }
};