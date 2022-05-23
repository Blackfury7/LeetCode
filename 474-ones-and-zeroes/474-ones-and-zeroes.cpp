class Solution {
public:
  int dp[601][101][101] = {};
    
    int sub(vector<pair<int,int>> &a, int index , int nOnes , int nZeros)
    {
        int n = a.size();
        if(index == n or (nZeros ==0 and nOnes == 0))   return 0;
        
        // if we already know answer for this index with current nZeros , nOnes then no need to recompute return the saved answer
        if(dp[index][nOnes][nZeros] != -1)
            return dp[index][nOnes][nZeros];
        
        // we dont have available no of zeros or ones to build this curent string, so we dont have any other option but to skip this index
        if(a[index].first > nOnes or a[index].second > nZeros)  
            return dp[index][nOnes][nZeros] = sub(a , index+1 , nOnes , nZeros);
        // NOTE : we are also saving corrensponding values
        
        int include = 1 + sub(a , index+1, nOnes - a[index].first , nZeros - a[index].second);
        int exclude = sub(a , index+1 , nOnes , nZeros);
        
        // save these values and return the answer
        return dp[index][nOnes][nZeros] = max(include , exclude);
    }
    
    int findMaxForm(vector<string>& strs, int nZeros, int nOnes) 
    {
        vector<pair<int,int>> a;
        memset(dp , -1 , sizeof(dp));
        
        for(auto i : strs)
        {
            int one = 0 , zero = 0;
            for(auto j : i)
                (j == '1') ? one ++ : zero++;
            a.push_back({one , zero});
        }
        
        int ans = sub(a , 0 , nOnes , nZeros);
        return ans;
    }
};