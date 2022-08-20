class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int n = blocks.size();
        vector<int>ar(n+1);
        int ans = k;
        for(int i = 0 ;i<n; i++) {
            ar[i+1] = ar[i]+(bool)(blocks[i]=='W');
            if(i>=k-1){
                ans = min(ans, ar[i+1] - ar[i+1-k]);
            }
            
        }
        return ans;
    }
};