class Solution {
public:
    /*
    First we transpose the matrix and then reverse every row:
    */
    
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        
        //transpose of a matrix
        
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < i; j++)
                swap(m[i][j], m[j][i]);
        
        for(int i = 0; i < n; i++)
            reverse(m[i].begin(), m[i].end());
    }
};