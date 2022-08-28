class Solution {
public:
    int n, m;
    bool isValid(int x, int y, vector<vector<char>>&v) {
        return (x >=0 && x<m && y>=0 && y <n && v[x][y] =='O');
    }
    
    void dfs(vector<vector<char>>& v, int i, int j) {
        if(!isValid(i, j, v)) return;
        v[i][j] = '#';
        dfs(v, i - 1, j);
        dfs(v, i + 1, j);
        dfs(v, i, j + 1);
        dfs(v, i, j - 1);
    }
    
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if(m == 0) return;
        n = board[0].size();
        
        // moving over firsts and last column
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][n-1] == 'O') dfs(board, i, n - 1);
        }
        
        // moving over first and last row
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[m-1][j] == 'O') dfs(board, m - 1, j);
        }
        
        for (int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};