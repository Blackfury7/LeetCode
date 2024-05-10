class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double low = 0, high = 1.0;

        while (low < high) {
            double mid = (low + high) / 2;
            vector<int> count = helper(arr, mid);

            if (k < count[0]) {
                high = mid;
            } else if (k > count[0]) {
                low = mid;
            } else {
                return {count[1], count[2]};
            }
        }
        return {};
    }

    vector<int> helper(vector<int>& arr, double target) {
        int count = 0, i = 0, n = arr.size(), num = arr[0], den = arr[n - 1];

        for (int j = 1; j < n; j++) {
            while (i < j && arr[i] <= arr[j] * target) {
                i++;
            }
            count += i;
            if (i > 0 && arr[i - 1] * den > arr[j] * num) {
                num = arr[i - 1];
                den = arr[j];
            }
        }
        return {count, num, den};
    }
};