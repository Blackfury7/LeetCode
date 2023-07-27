class Solution {
public:
    bool good(long long x, vector<int> &batteries, int n) {
        long long sum = 0;
        for(int i : batteries) {
            if(i >= x) n--;
            else sum += i;
        }
        return n ? sum / x >= n : true;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        if(n > batteries.size()) return 0;
        long long s = 1, e = 1e15, ans;

        while(s <= e) {
            long long m = (s + e) / 2;

            if(good(m, batteries, n)) {
                s = m + 1;
                ans = m;
            }
            else e = m - 1;
        }
        return ans;
    }
};