class Solution {
public:
    int M, N, Len;
    vector<int> dm = {0, -1, 0, 1};
    vector<int> dn = {1, 0, -1, 0};

    bool exist(vector<vector<char>>& board, string word) {
        M = board.size();
        N = board[0].size();
        Len = word.size();

        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(board[i][j] == word[0]){
                    vector<vector<bool>> viz(M, vector<bool>(N, false));

                    if(DFS(i,j, 1, board, word, viz)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool DFS(int i, int j, int count,
             vector<vector<char>>& board, string& word,
             vector<vector<bool>>& viz){

        if(count == Len){
            return true;
        }

        viz[i][j] = true;

        bool retVal = false;
        
        for(int k=0;k<4;k++){
            if(isInside(i + dm[k], j + dn[k])
               && !viz[i + dm[k]][j + dn[k]] &&
               board[i + dm[k]][j + dn[k]] == word[count]){
                retVal = DFS(i + dm[k], j + dn[k], count + 1, board, word, viz);
                if(retVal){
                    break;
                }
                viz[i + dm[k]][j + dn[k]] = false;
            }
        }

        return retVal;
    }

    bool isInside(int m, int n){
        return ( m >=0 && m < M && n >= 0 && n < N);
    }
};