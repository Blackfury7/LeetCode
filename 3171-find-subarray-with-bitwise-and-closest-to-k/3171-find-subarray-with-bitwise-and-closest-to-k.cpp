class Solution {
public:
    
    
    
    
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> bits(n+1, vector<int>(31));
        
        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j <= 30; j++) {
                bits[i+1][j] += bits[i][j];
                if(nums[i] & (1<<j)) {
                    bits[i+1][j] += 1;
                }
            }
        }
        
//         auto bin = [&](int n1) {
//             int n = n1;
//             string s = "";
//             cout<<n<<" bin --> ";
//             for(;n>0;n>>=1){
//                 if(n&1)
//                  s.push_back('1');
//                 else s.push_back('0');
                
//             }
//             reverse(s.begin(), s.end());
//             cout<<s<<"\n";
//         };
        
        
        auto ANDBits = [&] (int a, int b) {
            int l=a+1, r=b+1;
            int ans = 0;
            // cout<<" l and r inside andBITS "<<l<<" "<<r<<"\n";
            for(int i = 0; i < 31; i++) {
                if(bits[r][i] > 0 and (bits[r][i] - bits[l-1][i]) == (r - l + 1)) {
                    ans |= (1<<i);
                }
            }
            // bin(ans);
            return ans;
        
        };
        
        // binary search function
        auto find = [&] (int i) {
            int lo = i, hi = n-1, ans = n, mid;
            
            while(lo <= hi) {
                mid = (lo + hi) / 2;
                // cout<<" mid "<<mid<<"\n";
                if(ANDBits(i, mid) <= k) {
                    hi = mid-1;
                    ans = mid;
                }
                else lo = mid + 1;
            }
            return ans;
        };
        
        int ans = INT_MAX;
        for(int i = 0 ; i < n; i++) {
            // ans = min(ans, abs(k - nums[i]));
            int f = find(i);
            // cout<<"f "<<f<<"\n";
            if(f < n) ans = min(ans, abs(k - ANDBits(i, f)));
            if(f > i) ans = min(ans, abs(k - ANDBits(i, f - 1)));
        }
        return ans;
    }
};