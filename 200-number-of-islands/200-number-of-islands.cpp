class Solution {
public:
    
         int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty()) {
                        pair<int, int> p = todo.front();
                        todo.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                todo.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
        
        
        
        
    // void island(vector<vector<char>>& grid,int i,  int j, int flag[], int sum) {
//         flag[i][j] = 1;
//         if(grid[0]=='0' || i>=grid.size() || j >= grid[0].size())return ;
        
//         for(int x = 0; x<grid.size(); x++){
//             for(int y = 0;y<grid[0].size(); y++){
                
//                 if(!flag[i][j]){
            
//         if(grid[i][j] == '1'){
//            int l =  island(grid, x, y,flag,sum);
//            int r = island(grid, x, y,flag,sum); 
//         }
//                      sum++;
            
//         }
//             }
//         }
        
//     }
    
//     int numIslands(vector<vector<char>>& grid) {
//         int ar[grid.size()][grid[0].size()];
//         int sum=0;
//          island(grid, 0,0,ar, sum);
//         reutrn sum;
    // }
};