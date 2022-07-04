class Solution {
public:
    // int candy(vector<int>& r) {
    //     int n = r.size();
    //     vector<int> c(n, 1);
    //     for (int i = 1; i < n; i++)
    //         if (r[i] > r[i - 1]) c[i] = c[i - 1] + 1;
    //     for (int i = n - 2; ~i; i--)
    //         if (r[i] > r[i + 1]) c[i] = max(c[i], c[i + 1] + 1);
    //     int res = 0;
    //     for (auto t: c) res += t;
    //     return res;
    // }
    
    int candy(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n, 1);
        vector<int> r(n, 1);
        
        for (int i = 1; i < n; i++)
            if (nums[i] > nums[i - 1]) l[i] = l[i - 1] + 1;
        for (int i = n - 2; i>=0; i--)
            if (nums[i] > nums[i + 1]) r[i] = r[i + 1] + 1;
        
        
        int res = 0;
        for (int i =0;i<n;i++){
            res+= max(l[i], r[i]);
        }
        return res;
    }
};