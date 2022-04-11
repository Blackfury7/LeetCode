class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int total = ROWS * COLS;
        
        vector<vector<int>> ans(ROWS, vector<int>(COLS, 0));
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                int flatI = r * COLS + c;
                
                int newFlatI = (flatI + k) % total;
                
                int nr = newFlatI / COLS;
                int nc = newFlatI % COLS;
                ans[nr][nc] = grid[r][c];
            }
        }
        
        return ans;
    }
};