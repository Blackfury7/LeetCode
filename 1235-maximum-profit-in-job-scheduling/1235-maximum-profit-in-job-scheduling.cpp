class Solution {
private:
    int dp[50001];
	int f(vector<pair<pair<int,int>, int>> &v, int i, int endTime) {
		if (i == v.size()) return 0;
		if (v[i].first.first < endTime) return f(v, i + 1, endTime);
        if(dp[i] != -1) return dp[i];
		return dp[i] = max(v[i].second + f(v, i + 1, v[i].first.second), f(v, i + 1, endTime));
	}
public:
	int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        memset(dp, -1, sizeof(dp));
		vector<pair<pair<int,int>, int>> v;
		int n = e.size();
		for (int i = 0; i < n; ++i) v.push_back({{s[i], e[i]}, p[i]});
		sort(v.begin(), v.end());
		return f(v, 0, 0);
	}
};