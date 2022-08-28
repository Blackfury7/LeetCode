class Solution {
public:
     // Approach 
     //We will use boundary DFS to solve this problem
        
      // Let's analyze when an 'O' cannot be flipped,
      // if it has atleast one 'O' in it's adjacent,
    // AND ultimately this chain of adjacent 'O's is connected to some 'O' which lies on boundary of board
        
      //consider these two cases for clarity :
      /*
        O's won't be flipped          O's will be flipped
        [X O X X X]                   [X X X X X]     
        [X O O O X]                   [X O O O X]
        [X O X X X]                   [X O X X X] 
        [X X X X X]                   [X X X X X]
      
      So we can conclude 
      if a chain of adjacent O's is connected some O on boundary then they cannot be flipped
      
      */
        
      //Steps to Solve :
      //1. Move over the boundary of board, and find O's 
      //2. Every time we find an O, perform DFS from it's position
      //3. In DFS convert all 'O' to '#'     
    // (why?? so that we can differentiate which 'O' can be flipped and which cannot be)   
      //4. After all DFSs have been performed, board contains three elements,#,O and X
      //5. 'O' are left over elements which are not connected to any boundary O, so flip them to 'X'
      //6. '#' are elements which cannot be flipped to 'X', so flip them back to 'O'
    
    
    
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