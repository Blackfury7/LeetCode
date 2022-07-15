class Solution {
public:
    int dfs(vector<vector<int>>&grid, int i, int j, int n, int m){
        if(i >= 0 and i < n and j>= 0 and j<m and grid[i][j]){
            grid[i][j] = 0;
            
            return 1 + 
                dfs(grid, i+1, j, n, m) + 
                dfs(grid, i-1, j, n, m) + 
                dfs(grid, i, j+1, n, m) + 
                dfs(grid, i, j-1, n, m);
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx_area = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    int area = dfs(grid, i,j,n,m);
                    mx_area = max(mx_area, area);
                }
            }
        }
        return mx_area;
    }
};