class Solution {
public:
     void makeset(vector<int> &parent,vector<int> &rank)
    {
        
        for(int i=0;i<parent.size();i++)
        {
           rank[i]=0;
           parent[i]=i;
        }
    }
    int findpar(int node,vector<int> &parent,vector<int> &rank)
    {
        if(node==parent[node]) return node;
        return parent[node]=findpar(parent[node],parent,rank);
    }
    bool Union(int u,int v,vector<int> &parent,vector<int> &rank)
    {
        int par_u=findpar(u,parent,rank);
        int par_v=findpar(v,parent,rank);
       if(par_u==par_v) return false;
         
        else if(rank[par_u]>rank[par_v])
        {
            parent[par_v]=par_u;
        }
        else if(rank[par_u]<rank[par_v])
        {
            parent[par_u]=par_v;
        }
        else{
             parent[par_v]=par_u;
             rank[par_u]++;
        }
       return true;
    }
    int BuildMST(int edgeno, int n, vector<vector<int>>& edges, bool include ) {
       
        vector<int> parent(n);
        vector<int> rank(n);
        makeset(parent,rank);
        int ans=0;
        if(include && Union(edges[edgeno][0],edges[edgeno][1],parent,rank)) 
          ans+=edges[edgeno][2];
        for(int i = 0; i < edges.size(); i++)
        {
            
            if(i!=edgeno && Union(edges[i][0],edges[i][1],parent,rank))
            {

                ans+=edges[i][2];
            }
        }
        //check if all nodes are in one component or not
        int par_u=findpar(0,parent,rank);
        for(int i=1;i<n;i++)
        {
           int par_v=findpar(i,parent,rank);
           if(par_u!=par_v) return INT_MAX;
        } 
        
        return ans;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](vector<int>& e1,vector<int>& e2) {
            return e1[2] < e2[2];
        });
        int mstwt=BuildMST(-1,n, edges,false);
        
        vector<int> critical, pseudo_critical;
        for (int i = 0; i < edges.size(); i++) {
            if (mstwt < BuildMST(i,n, edges,false)) {
                critical.push_back(edges[i][3]);
            } else if (mstwt == BuildMST(i,n, edges,true)) {
                pseudo_critical.push_back(edges[i][3]);
            }
        }
        return {critical, pseudo_critical};
    }
};