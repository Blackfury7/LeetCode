class Solution {
public:
    typedef long long ll;
    long long continuousSubarrays(vector<int>& nums) {
        ll totalSubarrays = 0;
        int i = 0, j = 0;
        multiset<int> ms;
        while(j < nums.size()) {
            while (!ms.empty()) {
                auto lastElement = ms.rbegin();
                auto firstElement = ms.begin();
                if (abs(*lastElement - nums[j]) <= 2 && abs(*firstElement - nums[j]) <= 2) {
                    break;
                }
                auto erasingElement = ms.find(nums[i]);
                ms.erase(erasingElement);
                i++;
            }
            ms.insert(nums[j]);
            totalSubarrays += j - i + 1;
            j++;
        }
        return totalSubarrays;
    }
};