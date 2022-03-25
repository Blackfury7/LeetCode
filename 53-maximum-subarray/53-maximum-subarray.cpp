class Solution {
public:
    int maxSubArray(vector<int>& a) {
        long long sum=a[0];
        long long m=a[0];
        int n = a.size();
        
        for(int i=1; i<n ; i++){
           if(sum<=0)sum=a[i];
            else sum +=a[i];
             m = max(m, sum);
        }
        return m;
    }
};