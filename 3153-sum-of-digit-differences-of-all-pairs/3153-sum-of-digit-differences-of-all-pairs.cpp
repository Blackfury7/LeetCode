class Solution {
public:
    #define ll long long int
    long long sumDigitDifferences(vector<int>& nums) {
        ll n = nums.size();
        
        vector<vector<ll>> v(20, vector<ll>(10));
        int c = nums[0];
            int mx_size = 0;
            if(c==0)mx_size=1;
            while(c>0){
                c/=10;
                mx_size++;
            }
        for(int i = 0; i < n ; i++) {
            if(nums[i] == 0) {
                v[0][0]++;
                continue;
            }
            int r = 0;
            int pos = 0;
            
            while(nums[i] > 0) {
                r = nums[i] % 10;
                nums[i] /= 10;
                v[pos][r]++;
                pos++;
            }
        }
       
            ll ans = 0;
        for(int pos = 0; pos<mx_size; pos++){
            ll ans1=0;
            for(int i = 0; i < 10; i++) {
                ans1 += v[pos][i] * (n - v[pos][i]);
              
            }
            ans += (ans1)/2;
        }
        
        return ans;
    }
};