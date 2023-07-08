class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        int m = n-1;  
        vector<int> pairSum(m, 0);
        for(int i=0; i<m; i++){
            pairSum[i] = weights[i]+weights[i+1];
        }
        sort(pairSum.begin(), pairSum.end());
        long long minSum=0, maxSum=0;
        for(int i=0; i<k-1; i++){
            minSum += pairSum[i];
            maxSum += pairSum[m-i-1];
        }
        return maxSum-minSum;
    }
};