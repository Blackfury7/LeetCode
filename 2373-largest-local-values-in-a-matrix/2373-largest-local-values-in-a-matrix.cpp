class Solution {
public:
    
    int max_ele (int a, int b, vector<vector<int>>& grid) {
        int ans = INT_MIN;
        
        for(int i = a - 1; i <= a + 1; i++)
            for (int j = b - 1; j <= b + 1; j++ ) 
                ans = max(ans, grid[i][j]);

        return ans;
    }
    
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>v(n-2, vector<int>(n-2));
        
        for (int i = 0; i < n - 2; i++)
            for (int j = 0; j < n - 2; j++) 
                v[i][j] = max_ele(i+1, j+1, grid);

        return v;
    }
};