class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> one(max(n,m), vector<int>(2)), zero(max(n,m), vector<int>(2));
         vector<vector<int>> diff(n, vector<int>(m));
        for(int i = 0 ; i < n; i++) {
            int onee= 0;
            int zeroo=0;
            for(int j = 0; j < m; j++) {
                onee += (grid[i][j] == 1);
                zeroo += (grid[i][j] == 0);
            }
            one[i][0] = onee;
            zero[i][0] = zeroo;
        }
        for(int i = 0 ; i < m; i++) {
            int onee= 0;
            int zeroo=0;
            for(int j = 0; j < n; j++) {
                onee += (grid[j][i] == 1);
                zeroo += (grid[j][i] == 0);
            }
            one[i][1] = onee;
            zero[i][1] = zeroo;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                diff[i][j] = one[i][0] + one[j][1] - zero[i][0] - zero[j][1];
            }
        }
        
        return diff;
        
    }
};