class Solution {
public:
     int minCost(string s, vector<int>& cost) {
        int res = 0, max_cost = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i] != s[i - 1])
                max_cost = 0;
            res += min(max_cost, cost[i]);
            max_cost = max(max_cost, cost[i]);
        }
        return res;
    }
};