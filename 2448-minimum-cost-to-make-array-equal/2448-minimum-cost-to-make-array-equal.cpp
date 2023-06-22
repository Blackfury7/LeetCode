class Solution {
public:
    long long calc(vector<int>&nums, vector<int>& cost, long long median){
        long long ans = 0;
         for(int i=0;i<nums.size();i++)
           ans += abs(nums[i]-median)*(cost[i]);
         return ans;  
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {

        long long tot = 0,sum = 0,n = nums.size();

        vector<pair<int,int>> vec;

        for(int i=0;i<nums.size();i++)
           { vec.push_back({nums[i],cost[i]});
            sum += cost[i]; }
        sort(vec.begin(),vec.end());
        long long median,i=0;
        while(tot < (sum+1)/2){
            if(i==n) break;
             tot += vec[i].second;
             median = vec[i].first;
             i++;
        }    
        
        return calc(nums,cost,median);
    }
};