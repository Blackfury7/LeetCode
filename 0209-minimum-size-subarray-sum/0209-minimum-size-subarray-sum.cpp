class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = 0;
        int mini = INT_MAX;

        int sum = 0;

        while(s < n && e < n)
        {
            sum += nums[e];
            if(sum >= target)
            {
                while(sum >= target)
                {
                    int val = (e - s) + 1;
                    mini = min(mini, val);
                    sum -= nums[s];
                    ++s;
                }
            }
            ++e;
            
        }
        if(mini == INT_MAX)
            return 0;
        return mini;

    }
};