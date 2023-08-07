class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0,right = col-1;
        while(left < row && right > -1)
        {
            int curr = matrix[left][right];
            if(curr == target) return true;
            if(target > curr) left++;
            else{
                right--;
            }
        }
        return false;
    }
};