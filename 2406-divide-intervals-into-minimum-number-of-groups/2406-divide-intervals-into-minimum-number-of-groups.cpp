class Solution {
public:
   
    int minGroups(vector<vector<int>>& intervals) {
          int N = 1e6+5;
        vector<int>v(N);
        for(auto &i: intervals) {
            v[i[0]]++;
            v[i[1]+1]--;
        }
        int ans = 0;
        for(int i = 1; i < N; i++) {
            v[i] += v[i-1];
            ans = max(ans, v[i]);
        }
        return ans;
    }
};