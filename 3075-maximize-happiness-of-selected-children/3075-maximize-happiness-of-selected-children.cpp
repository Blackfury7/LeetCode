class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        sort(happiness.begin(), happiness.end());
        for(int i = happiness.size() - 1, j = 0; i >= 0 && k > 0; --i, j++, k--){
            if(happiness[i] - j > 0) ans += happiness[i] - j;
        } 
        return ans;
    }
};