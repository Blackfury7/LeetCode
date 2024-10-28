class Solution {
public:
    int longestSquareStreak(vector<int>& A) {
        unordered_map<int, int> dp;
        int res = 0;
        sort(begin(A), end(A));
        for(auto i : A){
            int root = sqrt(i);
            if(root * root == i)
               dp[i] = 1 + dp[root];
            else 
               dp[i] = 1;
            res = max(res, dp[i]);
        }
        return res < 2 ? -1 : res;
    }
};