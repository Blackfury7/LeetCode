class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int top = 0;
        int bot = n - 1;
        int left = 0;
        int right = n - 1;
        int dir = 0; 
        int num = 1;
        
        while(top <= bot && left <= right) {
            if(dir == 0) {
                for(int c = left; c <= right; c++) {
                    matrix[top][c] = num++;
                }
                dir++;
                top++;
            } else if (dir == 1) {
                for(int r = top; r <= bot; r++) {
                    matrix[r][right] = num++;
                }
                dir++;
                right--;
            } else if (dir == 2) {
                for(int c = right; c >= left; c--) {
                    matrix[bot][c] = num++;
                }
                dir++;
                bot--;
            } else if (dir == 3) {
                for(int r = bot; r >= top; r--){
                    matrix[r][left] = num++;
                }
                dir = 0;
                left++;
            }
        }      
        return matrix;
    }
};