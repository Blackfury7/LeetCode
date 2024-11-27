class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<int>> adj(n);
        vector<int> dist(n);

        iota(dist.begin(), dist.end(), 0); //fills the array with 0,1,2,3...
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        
        for (auto it : queries) {

            int src = it[0], des = it[1];
            adj[src].push_back(des);

            if (dist[src] + 1 < dist[des]) {
                //BFS
                queue<int> q;
                q.push(des);
                dist[des] = dist[src] + 1;

                while (q.size()) {

                    int idx = q.front();
                    q.pop();

                    for (auto e : adj[idx]) {

                        if (dist[idx] + 1 < dist[e]) {
                            dist[e] = dist[idx] + 1;
                            q.push(e);
                        }

                    }
                }
            }

            ans.emplace_back(dist.back());
        }
        return ans;
    }
};