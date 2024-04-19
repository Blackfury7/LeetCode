class Solution {
public:
    int n,m;
    const int moves[4][2] = {{1,0}, {0,1},{-1,0},{0,-1}};
    bool isValid(int i, int j){
        return (i>=0 && i<n && j>=0 && j < m);
    }
    void dfs(vector<vector<char>>& grid, int i , int j) {
        if(!isValid(i,j))return;
        if(grid[i][j]=='0')return;
        grid[i][j]='0';
        for(int z = 0; z < 4; z++) {
            dfs(grid, i+moves[z][0], j+moves[z][1]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j < m ; j++) {
                if(grid[i][j]=='1'){
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};