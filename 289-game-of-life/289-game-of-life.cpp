class Solution {
public:
    int m,n;
    bool isvalid(int i,int j)
    {
        if(i>=0&&i<m&&j>=0&&j<n)
            return 1;
        return 0;
    }
    void check(vector<vector<int>>&board,int i,int j)
    {
        int count=0;

        if(isvalid(i,j+1)&&(board[i][j+1]==1||board[i][j+1]==5))
            count++;
        if(isvalid(i,j-1)&&(board[i][j-1]==1||board[i][j-1]==5))
            count++;
        if(isvalid(i+1,j+1)&&(board[i+1][j+1]==1||board[i+1][j+1]==5))
            count++;
        if(isvalid(i+1,j-1)&&(board[i+1][j-1]==1||board[i+1][j-1]==5))
            count++;
        if(isvalid(i-1,j-1)&&(board[i-1][j-1]==1||board[i-1][j-1]==5))
            count++;
        if(isvalid(i-1,j+1)&&(board[i-1][j+1]==1||board[i-1][j+1]==5))
            count++;
        if(isvalid(i+1,j)&&(board[i+1][j]==1||board[i+1][j]==5))
            count++;
        if(isvalid(i-1,j)&&(board[i-1][j]==1||board[i-1][j]==5))
            count++;
        
        
        if(board[i][j]==1) 
        {
           if(count<2)
             board[i][j]=5; 
           if(count>3)
             board[i][j]=5;
        }
        else if(board[i][j]==0) 
        {
            if(count==3)
            board[i][j]=6; 
    }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        m=board.size(),n=board[0].size(); 
        for(int i=0;i<m;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                check(board,i,j);
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==5)
                    board[i][j]=0;
                if(board[i][j]==6)
                    board[i][j]=1;
            }
        }
    }
};