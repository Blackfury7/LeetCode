class Solution {
public:
    
    long long dp[100001][4][3];
    long long solve(string &s, int index, int selection, int prevBuilding) {
        int n = s.size();
        //base condition
        if(selection == 0){
            return 1;
        }
        if(index >= n){
            return 0;
        }
        //memoize
        if(dp[index][selection][prevBuilding+1] != -1) return dp[index][selection][prevBuilding+1];
        
        //choices
        if((s[index]-'0') != prevBuilding) {
            return dp[index][selection][prevBuilding+1] = solve(s,index+1, selection-1,s[index] - '0') + solve(s, index+1, selection, prevBuilding);
            
        } else {
            return dp[index][selection][prevBuilding+1] = solve(s, index+1, selection, prevBuilding);
        }
        
        return 0;
        
        
    }
    
    long long numberOfWays(string s){
        for(int i=0; i<100001; i++){
            for(int j=0; j<4;j++){
                for(int k=0; k<3; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(s,0,3,-1); 
    }
};