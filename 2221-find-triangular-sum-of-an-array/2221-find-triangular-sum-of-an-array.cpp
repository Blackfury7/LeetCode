class Solution {
public:
    
    
    
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        int ar[n+1][n+1];
        for(int i=0;i<n;i++){
            ar[0][i]=nums[i];
        }
        
        for(int i=1; i<n; i++){
            
            for(int j=0;j<n-i;j++){
                ar[i][j] = (ar[i-1][j] + ar[i-1][j+1])%10;
            }
        }
        return ar[n-1][0];
    }
};