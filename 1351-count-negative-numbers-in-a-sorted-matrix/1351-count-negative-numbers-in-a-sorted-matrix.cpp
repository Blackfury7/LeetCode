class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();

        int rowindex = 0;
        int colindex = col-1;
        
        int ans = 0;
        
        while(rowindex < row && colindex >=0)
        {
            int element = grid[rowindex][colindex];
            if(element < 0)
            {   
                ans += (row-rowindex);
                colindex--;
            }
            else
            {
                rowindex++;
            }
            
        }
        return ans;
    }
};