class Solution {
public:
    int mod = pow(10,9)+7;
    int solve(vector<int>& locations, int start, int finish, int fuel,vector<vector<int>>&dp){
      
       if( start >= locations.size() ) return 0;
       if(dp[start][fuel] != -1) return dp[start][fuel];
       
       int count = 0;
       if(start == finish ) count++;

       for(int i = 0 ;i<locations.size();i++){
           if(i == start ) continue;
           int new_fuel = fuel - abs(locations[start] - locations[i]);
           if(new_fuel  >= 0){
             count = (count + solve(locations,i,finish,new_fuel,dp))%mod; 
           }
       }

       return dp[start][fuel] = (count%mod);
   }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>>dp(n+1,vector<int>(fuel+1,-1));
        return solve(locations,start,finish,fuel,dp);   
    }
};