
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));

        int ans = (int)fun(0,0,houses,cost,target);
        return ans == INT_MAX ? -1 : ans;
    }
    int dp[101][21][101];
protected:
    long long fun(int idx, int last, vector<int>&arr,vector<vector<int>>&cost,int target){
        if(target==0 and idx>=arr.size()) return 0;
        if(idx>=arr.size()) return INT_MAX;
        if(target<0) return INT_MAX;
        
        if(arr[idx]!=0){ 
            if(last==arr[idx]) return fun(idx+1,last,arr,cost,target);
            else return fun(idx+1,arr[idx],arr,cost,target-1);
        }
        
        if(dp[idx][last][target]!=-1) return dp[idx][last][target];
        
        long long ans = INT_MAX;
        for(int i = 0; i<cost[0].size(); i++){
            if(i+1==last) ans = min(ans,cost[idx][i]+fun(idx+1,last,arr,cost,target));
            else ans = min(ans,cost[idx][i]+fun(idx+1,i+1,arr,cost,target-1));
        }
        return dp[idx][last][target] = ans;
    }
};