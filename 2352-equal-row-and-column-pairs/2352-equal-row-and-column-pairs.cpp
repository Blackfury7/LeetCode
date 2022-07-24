class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<ll>row(n),col(n);
        int p=0;
        for(int k =0;k<n;k++){
        for(int i=0;i<n;i++){
            int flag =0;
            for(int j=0;j<n;j++){
                // row[i] += grid[i][j];
                // col[i] += grid[j][i];
                if(grid[k][j] != grid[j][i]){
                    flag=1;
                    break;
                }
            }
            if(!flag)p++;
        }
        }
        return p;
    }
};