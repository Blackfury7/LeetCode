class Solution {
public:
    int pivotInteger(int n) {
        int l = 1, r = n, sum = n * (n + 1) / 2;
        while (l < r) {
            int m = (l + r) / 2;
            if (m * m - sum < 0)
                l = m + 1;
            else
                r = m;
        }
        return l * l - sum == 0 ? l : -1;
    }
};