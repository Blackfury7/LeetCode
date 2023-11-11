class Graph {
public:
    vector<vector<array<int, 2>>> al;
    Graph(int n, vector<vector<int>>& edges) {
        al.resize(n);
        for (auto &e : edges)
            al[e[0]].push_back({e[1], e[2]});
    }
    void addEdge(const vector<int> &e) {
        al[e[0]].push_back({e[1], e[2]});
    }
    int shortestPath(int node1, int node2) {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
        vector<int> cost(al.size(), INT_MAX);
        cost[node1] = 0;
        pq.push({0, node1});
        while (!pq.empty() && pq.top()[1] != node2) {
            auto [cost_i, i] = pq.top(); pq.pop();
            if (cost_i != cost[i])
                continue;
            for(auto [j, cost_j] : al[i])
                if (cost_i + cost_j < cost[j]) {
                    cost[j] = cost_i + cost_j;
                    pq.push({cost[j], j});
                }
        }
        return cost[node2] == INT_MAX ? -1 : cost[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */