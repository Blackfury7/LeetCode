class Solution {
public:
    int dp[12][(1<<12)];
    
    int job_time(int mask, vector<int>& jobs) {
        int n = jobs.size();
        int time = 0;
        for(int i = 0; i < n; i++) {
            if((mask & (1<<i))){
                time+=jobs[i];
            }
        }
        return time;
    }
    
    int solve(int i, int mask, vector<int>& jobs, int k , int n){
        if(i==k) return 0;
        if(dp[i][mask] != -1) return dp[i][mask];
        
        if(i == k-1){
            return dp[i][mask] = job_time(mask,jobs);
        }
        
        int ans = INT_MAX;
        int d = 0;
        // Iterate over all subsets of the available jobs (cool trick)
        for(int submask=mask; submask > 0; submask = (submask-1)&mask) {
                ans = min(ans, 
                          max(solve(i+1, mask ^ (submask), jobs, k, n), 
                              job_time(submask, jobs)));
        }
       
        return dp[i][mask] = ans;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        memset(dp, -1, sizeof(dp));
        int n = jobs.size();
        return solve(0, (1<<n)-1, jobs, k , n);
        
    }
};