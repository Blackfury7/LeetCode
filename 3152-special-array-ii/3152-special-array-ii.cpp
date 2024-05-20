class Solution {
public:
    
    #define ll long long
    
    ll bit[100000];
    void add(int i) {
        
    }
    
    vector<bool> isArraySpecial(vector<int>& num, vector<vector<int>>& q) {
        int n = num.size();
        int qn = q.size();
        if(n == 1){
            return vector<bool>(qn,true);
            // return [true];
        }
        
        vector<int> pre(n+5);
        pre[1] = 1;
        // if(nums[0])
        for(int i = 1; i < n; i++) {
            pre[i+1] = (((int)(num[i]&1) == (num[i-1]&1)) ^ 1);
        }
        for(int i = 1; i <= n; i++) pre[i] += pre[i-1];
        vector<bool> ans(qn, false);
        for(int i = 0; i < qn; i++){
            int len = q[i][1] - q[i][0];
            if(q[i][1] == q[i][0]){
                ans[i]= true;
                continue;
            }
            if(pre[q[i][1] + 1] - pre[q[i][0] + 1] == len) ans[i] = true;
        }
        return ans;
    }
};