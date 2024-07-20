class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
		int n = colSum.size();
        vector<vector<int>> mat(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0 ; j < n; j++) {
                mat[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= mat[i][j];
                colSum[j] -= mat[i][j];
            }
        }
        return mat;
    }
};