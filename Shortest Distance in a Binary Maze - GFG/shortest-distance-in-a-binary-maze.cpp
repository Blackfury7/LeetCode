//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    
    bool isSafe(int i, int j, vector<vector<int>> &v) {
        if(i >= 0 && i < v.size() && j >= 0 && j < v[0].size() && v[i][j])
            return true;
            
        return false;
    }
    
    int shortestPath(vector<vector<int>> &v, pair<int, int> src,
                     pair<int, int> dest) {
                         
        if(v[src.first][src.second] == 0) return -1;
        if(src == dest) return 0;
        
        queue<vector<int>> q;
    
        q.push({src.first,src.second});
        v[src.first][src.second] = 0;
        int ans = 0;
        
        while(!q.empty()) {
            int n = q.size();
            ans++;
            while(n--) {
                vector<int> cur = q.front();
                q.pop();
                
                 for(auto x: dir) {
                    int i = cur[0] + x.first;
                    int j = cur[1] + x.second;
                    
                    if(isSafe(i,j,v)){
                        if(i == dest.first && j == dest.second)
                            return ans;
                            
                        q.push({i,j,cur[2]+1});
                        v[i][j] = 0;
                    }
                }
                
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends