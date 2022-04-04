class Solution {
public:
    
    long long numberOfWays(string s) {
        
        //Logic: "010" or "101", select the middle element and count number of 1's or 0's on both sides
        //prefix sum can be used to calculate the number of 1's & 0's
        
        
        int n = s.size();
        long long ans = 0;
        vector<int> prez(n,0), preo(n,0);
        for(int i=0; i<n; i++) {
            if(i == 0){
                prez[i] = s[i]=='0'?1:0;
                preo[i] = s[i]=='1'?1:0;
                continue;
            }
            prez[i] = prez[i-1] + (s[i]=='0');
            preo[i] = preo[i-1] + (s[i]=='1');
        }
        for(int i=1; i<n-1; i++) {
            if(s[i] == '1') {
                long long x = prez[i-1];
                long long y = prez[n-1] - prez[i];
                ans += (x*y);
            }
            else {
                long long x = preo[i-1];
                long long y = preo[n-1] - preo[i];
                ans += (x*y);
            }
        }
        return ans;
            
    }
    
    
    
    
    //*********************************************************************************************************************
    //3D DP
//     long long dp[100001][4][3];
//     long long solve(string &s, int index, int selection, int prevBuilding) {
//         int n = s.size();
//         //base condition
//         if(selection == 0){
//             return 1;
//         }
//         if(index >= n){
//             return 0;
//         }
//         //memoize
//         if(dp[index][selection][prevBuilding+1] != -1) return dp[index][selection][prevBuilding+1];
        
//         //choices
//         if((s[index]-'0') != prevBuilding) {
//             return dp[index][selection][prevBuilding+1] = solve(s,index+1, selection-1,s[index] - '0') + 
//                 solve(s, index+1, selection, prevBuilding);
            
//         } else {
//             return dp[index][selection][prevBuilding+1] = solve(s, index+1, selection, prevBuilding);
//         }
//         return 0;
//     }
    
//     long long numberOfWays(string s){
//         for(int i=0; i<100001; i++){
//             for(int j=0; j<4;j++){
//                 for(int k=0; k<3; k++){
//                     dp[i][j][k] = -1;
//                 }
//             }
//         }
//         return solve(s,0,3,-1); 
//     }
    //*********************************************************************************************************************
};