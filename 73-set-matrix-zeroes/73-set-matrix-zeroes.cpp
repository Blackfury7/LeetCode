class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        bool row = 0, col = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!matrix[i][j]) {
                    if(!i) row = true;
                    if(!j) col = true;
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i <n; i++)
            for(int j = 1; j < m; j++)
                if(!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
            
        
        if(col)
            for(int i = 0; i < n; i++) matrix[i][0] = 0;
        
        if(row)
            for(int j = 0; j < m; j++) matrix[0][j] = 0;
        
    }
};
        
        
        
//         vector<pair<int,int>> v;
        
//         for(int i=0;i<n; i++)
//             for(int j=0; j<m; j++) 
//                 if(matrix[i][j] == 0) 
//                     v.push_back(make_pair(i,j));
        
//         int v1 = v.size();
//         for(int vi = 0; vi<v1; vi++) {
//             for(int j =0; j<m; j++)matrix[v[vi].first][j] = 0;
//             for(int i =0; i<n; i++)matrix[i][v[vi].second] = 0;
//         }
//         return;
//     }
    
// };