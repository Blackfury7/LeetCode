class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& m) {
        long long sum = 0, zeros = 0, negs = 0, min_abs = INT_MAX;
        for (int i = 0; i < m.size(); ++i)
            for (int j = 0; j < m[i].size(); ++j) {
                sum += abs(m[i][j]);
                zeros += m[i][j] == 0;
                negs += m[i][j] < 0;
                min_abs = min(min_abs, (long long)abs(m[i][j]));
            }
        return sum - (zeros || negs % 2 == 0 ? 0 : 2 * min_abs);
    }
};