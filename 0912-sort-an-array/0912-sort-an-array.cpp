class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> p;
        for(auto i : nums)
        p.push(i);
        for(int i=nums.size()-1;i>=0;i--)
            {nums[i]=p.top();p.pop();}
        return nums;
    }
};