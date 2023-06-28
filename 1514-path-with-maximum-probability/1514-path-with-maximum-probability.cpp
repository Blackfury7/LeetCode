class Solution {
public:
     double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int,double>> adj[n];
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        
        double prob[10001] = {0};
        prob[start] = 1.0;

        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});

        while(!pq.empty()){
            double p = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node == end) return prob[end];

            for(auto it : adj[node]){
                int nbr = it.first;
                double np = it.second;

                if(prob[nbr] < p * np){
                    prob[nbr] = p * np;
                    pq.push({prob[nbr],nbr});
                }

            }
        }

        return prob[end];

    }
};