class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res = 0;
        priority_queue<int> pq(begin(nums), end(nums));
        while (k-- && !pq.empty()) {
            int n = pq.top(); pq.pop();
            res += n;
            if ((n + 2) / 3)
                pq.push((n + 2) / 3);
        }
        return res;
    }
};