class Solution {
public:
    bool dfs(int x, int y, vector<vector<bool>>& vis, vector<vector<int>>& grid, int& row, int& col){
        if(x<0 or y<0 or x>=row or y>=col or vis[x][y]==true or grid[x][y]==1){
            return false;
        }
        if(x==row-1) return true;
        vis[x][y]=true;

        return dfs(x-1,y,vis,grid,row,col)||dfs(x,y-1,vis,grid,row,col)||dfs(x+1,y,vis,grid,row,col)||
               dfs(x,y+1,vis,grid,row,col);

    }
    bool helper(vector<vector<int>>& cells, int limit, int& row, int& col){
        vector<vector<int>> grid(row,vector<int>(col,0));
        for(int i=0;i<=limit;i++){
            int x = cells[i][0]-1;
            int y = cells[i][1]-1;
            grid[x][y] = 1;
        }

        vector<vector<bool>> vis(row,vector<bool>(col,false));

        for(int i=0;i<col;i++){
            if(grid[0][i]==0 and vis[0][i]==false){
                if(dfs(0, i, vis, grid, row, col)==true){
                    return true;
                }
            }
        }

        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int s = 0;
        int e = cells.size()-1;
        int ans = -1;

        while(s<=e){
            int mid = s+(e-s)/2;

            if(helper(cells, mid, row, col)){
                ans = mid;
                s = mid+1;
            }
            else{
                e=mid-1;
            }
        }

        return ans+1;
    }
};