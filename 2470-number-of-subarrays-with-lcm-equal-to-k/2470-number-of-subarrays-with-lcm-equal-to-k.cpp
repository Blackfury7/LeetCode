class Solution {
public:
    #define ll long long
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        long long a = 1;

        int ans = 0;
        for(int i = 0; i < n ;i++) {
            a = nums[i];
            for(int j = i; j< n; j++) {
                a = lcm(a, nums[j]);
                if(a == k) ans++;
                else if(a > k) break;
            }
        }
        return ans;
    }
};