class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        
        int i,j;i=j=0;
        int maxx =0, sum=0;
        
        while(i<n && j<n){
            
            if(m[nums[i]]==0){
                m[nums[i]]++;
                sum += nums[i];
                maxx = max(maxx,sum);
                i++;
            }
            else{
                while(j<n && j<i && m[nums[i]]>0){
                    m[nums[j]]--;
                    sum -= nums[j];
                    j++;
                }
            }
        }
        return maxx;
    }
};