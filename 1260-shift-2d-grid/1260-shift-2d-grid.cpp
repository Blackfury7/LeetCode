class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans = grid;
        int rows = grid.size(), cols = grid[0].size(), n = rows*cols; 
        for(int curr = 0; curr < n;curr++) { 
            int next = (curr+k)%n;
            ans[next/cols][next%cols]= grid[curr/cols][curr%cols];
        }
        return ans;
    } 
};