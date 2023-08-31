class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n + 1, n + 2); 
        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
            int tapRange = ranges[i];
            int left = max(0, i - tapRange);
            int right = min( i + tapRange,n);

            for (int j = left; j <= right; j++) {
                dp[j] = min(dp[j], dp[left] + 1);
            }
        }

        return dp[n] <= n + 1 ? dp[n] : -1;
    }
};