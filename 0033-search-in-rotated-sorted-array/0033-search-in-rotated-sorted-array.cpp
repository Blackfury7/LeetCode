class Solution {
public:
    int binarySearch(vector<int> &arr, function<bool(int)> checker) {
        // Checker should return true if the element is greater than or equal to the target ( Move left )
        int l{}, r = arr.size() - 1;

        while(l < r) {
            int mid = l + (r - l) * 0.5;
            if(checker(mid)) r = mid;
            else l = mid + 1;
        }
        return checker(r) ? r : r + 1;
    }
    int search(vector<int>& nums, int target) {
        int pivot = binarySearch(nums, [&](int x) { return nums[x] < nums[0]; });
        if(pivot == nums.size()) pivot = 0;

        int ans = binarySearch(nums, [&](int x) { 
            return nums[(x + pivot) % nums.size()] >= target; 
        });

        if(ans < nums.size() && nums[(ans + pivot) % nums.size()] == target)
            return (ans + pivot) % nums.size();
        else return -1;
    }
};