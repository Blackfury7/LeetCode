class Solution {
public:
    
    int dp[310][10010];

    int func2(int ind, int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        if(ind < 0) return 0;
        if(dp[ind][amount] != -1) return dp[ind][amount];

        int ways = 0;
        for(int i = 0; i <=ind; i++) {
            if(amount >= coins[i])
                ways += func2(i, amount - coins[i], coins);
        }
        return dp[ind][amount] = ways;
    }
    
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return func2(coins.size()-1, amount, coins);
    }
    
    
    
 // *******************************************************************************   
    
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<int>dp(amount+1, 0);
    //     dp[0] = 1;
    //     for(int i=0; i<n; i++){
    //         for(int j=1; j<=amount; j++){
    //             if((j-coins[i])>=0){
    //                 dp[j] = dp[j] + dp[j-coins[i]];
    //             }
    //         }
    //     }
    //     return dp[amount];
    // }
};