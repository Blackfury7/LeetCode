class Solution {
public:
    double knightProbability(int n, int k, int startRow, int startColumn) {
        
        vector<vector<double>> dp(n, vector<double>(n, 0));
        dp[startRow][startColumn] = 1;
        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

        auto isInside = [&] (int row, int col) {
            return row >= 0 && col >= 0 && row < n && col < n;
        };

        for(int turn = 0; turn < k; turn++) {
            vector<vector<double>> ndp(n, vector<double>(n, 0));

            for(int row = 0; row < n; row++) {
                for(int col = 0; col < n; col++) {

                    double nextProb = dp[row][col] / 8;

                    for(int move = 0; move < 8; move++) {
                        int newRow = row + dx[move];
                        int newCol = col + dy[move];

                        if(!isInside(newRow, newCol)) continue;

                        double &next = ndp[newRow][newCol];

                        next += nextProb;

                    }


                }
            }
            dp = ndp;
        }

        double ans = 0;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                ans += dp[row][col];
            }
        }

        return ans;

    }
};