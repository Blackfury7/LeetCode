using  ll = long long int ;
class Solution {
public:
    // BFS and Dikeshtra's algorithm 
    void Dikeshtra(int n ,vector<vector<pair<ll,ll>>>& adj, int source , vector<ll>&dp )
    {
        priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>>> pq ; 
       
        pq.push({0 , source});
        dp[source]=0;
        while(!pq.empty())
        {
            ll dis = pq.top().first;
            ll ind = pq.top().second ;
            pq.pop() ;
            for(int j =0 ;j<adj[ind].size() ;j++)
            {
                ll val =adj[ind][j].second;
                ll new_dis= dis+val;
                if(new_dis<dp[adj[ind][j].first])
                {
                    dp[adj[ind][j].first]=new_dis;
                    pq.push({new_dis, adj[ind][j].first});
                } 
            }
        }
    }
    // Converting all -1 edges to max or 1
    //Assigning values when got the destination 
    void assign(vector<vector<int>>& edges , int with )
    {
        for( int i =0 ;i<edges.size(); i++)
        {
            if(edges[i][2]==-1)
            {
                edges[i][2]=with;
            }
        }
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
      // two adjacency list one for minmum and other maximum
        vector<vector<pair<ll,ll>>> adj (n) , r_adj(n);
        for( int i =0 ;i<edges.size() ;i++)
        {
            ll val = edges[i][2] , value= edges[i][2];
            if(edges[i][2]==-1)
            {
                val= 1;
                value =2e9;
            }
            adj[edges[i][0]].push_back({edges[i][1] ,val});
            adj[edges[i][1]].push_back({edges[i][0] , val});
            r_adj[edges[i][0]].push_back({edges[i][1] , value});
            r_adj[edges[i][1]].push_back({edges[i][0] , value});
        } 
        // for storing the paths dp1(from source) && dp1(from destination)
        vector<long long > dp1(n ,INT_MAX) , dp2(n , INT_MAX);

        Dikeshtra(n , adj, source ,dp1);
        //EDGE CASES BEEN handled here 
        if(dp1[destination]>target)
        {
            return {};
        }
        // If dp[destination]== target return edgesy converting them as1 the -1 weight obviously
        if(dp1[destination]==target)
        {
            assign(edges, 1);
            return edges;
        }
        //if_not 
        Dikeshtra(n , r_adj , destination , dp2);
        if(dp2[source]<target)
        {
            return {};
        }
        if(dp2[source]==target)
        {
            assign(edges, 1e9);
            return edges;
        }
        // Edge cases have been taken care above 
        // Rest :
        for(int i =0 ;i<edges.size(); i++)
        {
            if(edges[i][2]==-1)
            {
                ll from_source = min(dp1[edges[i][0]],dp1[edges[i][1]]);
                ll from_destination = min(dp2[edges[i][0]], dp2[edges[i][1]]);
                int val = target -from_source-from_destination;
            // if val>0 ==> target have been reached 
                if(val>0)
                {
                    edges[i][2]=val;
                }
                else
                {
                    // Singly converting him will not make target  so lets take it minimum
                    edges[i][2]=1;
                }
            }
        }
        return edges;
    }
};