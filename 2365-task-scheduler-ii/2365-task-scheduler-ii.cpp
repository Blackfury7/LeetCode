class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long ans = 0;
        map<int, long long> m;
        for (int i : tasks) {
            if (not m.count(i))
                m[i] = ans += 1;
            else
                m[i] = ans = max(ans + 1, m[i] + space + 1);
        }
        return ans;
    }
};