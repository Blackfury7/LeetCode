class Solution {
public:
    int n,m,k,dp[55][105][55],mod=1e9+7;
    
    int sol(int id,int mx,int inv)
    {
  
        if(id==n) return (inv==k);
        if(inv>k) return 0;
        
        long ans=dp[id][mx][inv];
        if(ans!=-1) return ans;
        ans=0;
        
        for(int l=1;l<=m;l++)
        {
            if(l<=mx) ans+=sol(id+1,mx,inv);
            else ans+=sol(id+1,l,inv+1);
            ans%=mod;
        }
        return dp[id][mx][inv]=ans;
    }
    
    int numOfArrays(int nn, int mm, int kk) 
    {
        n=nn; m=mm; k=kk;
        memset(dp,-1,sizeof(dp));
        return sol(0,0,0);
    }
};