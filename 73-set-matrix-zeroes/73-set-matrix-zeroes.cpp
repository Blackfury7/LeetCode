class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        
        vector<pair<int,int>> v;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n; i++)
            for(int j=0; j<m; j++) 
                if(matrix[i][j] == 0) 
                    v.push_back(make_pair(i,j));
        
        int v1 = v.size();
        for(int vi = 0; vi<v1; vi++) {
            for(int j =0; j<m; j++)matrix[v[vi].first][j] = 0;
            for(int i =0; i<n; i++)matrix[i][v[vi].second] = 0;
        }
        return;
    }
    
};