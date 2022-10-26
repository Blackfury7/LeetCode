class Solution {
public:
    bool checkSubarraySum(vector<int>& A, int k) {
        unordered_map<int, int> seen = {{0, -1}};
        int cur = 0;
        for (int i = 0; i < A.size(); ++i) {
            cur =  k ? (cur + A[i]) % abs(k) : cur + A[i];
            seen.insert({cur, i});
            if (i - seen[cur] > 1) return true;
        }
        return false;
    }
};