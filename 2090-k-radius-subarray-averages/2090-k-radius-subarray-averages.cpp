class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans;
        deque<long long > sample;
        int count =0;
        long long sum =0;

        if(k>nums.size()||2*k>nums.size()){
            for(int i =0;i<nums.size();i++){
                ans.push_back(-1);
            }
            return ans;
        }
        for(int i =0;i<k;i++){
            ans.push_back(-1);
        }

        int j = nums.size() - 1 -k;
        

        for(int i =0 ;i<nums.size();i++){
           
            if(count>=2*k+1){
                sum-=sample.front();
                
                sample.pop_front();
                sample.push_back(nums[i]);
                sum+=nums[i];
                
                count++;
            }
            if(count<2*k+1){
                sample.push_back(nums[i]);
                sum+=nums[i];
                count++;
            } 
            if(sample.size()==2*k+1){
                
                ans.push_back(sum/(2*k+1));
            }
        }

        for(int i=1;i<=k;i++){
            ans.push_back(-1);
        }
        return ans;
    }
};