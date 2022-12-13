class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int row=A.size();
        int column=A[0].size();
        for(int i=1;i<row;i++){
            for(int j=0;j<column;j++){
                if(j==0)                                                    //Leftmost or first column
                A[i][j]+=min(A[i-1][j],A[i-1][j+1]);
                else if(j==column-1)A[i][j]+=min(A[i-1][j],A[i-1][j-1]);     //Rightmost or last column
                else A[i][j]+=std::min({A[i-1][j],A[i-1][j+1],A[i-1][j-1]}); //Remaining cases
            }
        }
        int sum=INT_MAX;
        for(int i=0;i<column;i++){
            sum=min(sum,A[row-1][i]);                                      //Last row scan
        }
        return sum;
    }
};