class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        
        
    //**************************************************************************************************
    //     unordered_set<long long> hashSet;
    //     for(long long num:nums)
    //         hashSet.insert(num);
    //     int longestStreak = 0;
    //     for(long long i: nums){
    //         if(!hashSet.count(i-1)){
    //             int currentStreak = 1;
    //             long long currentNum = i;
    //             while(hashSet.count(currentNum+1)){
    //                 currentStreak++;
    //                 currentNum++;
    //             }
    //             longestStreak = max(longestStreak, currentStreak);
    //         }
    //     }
    //     return longestStreak;
    // }
    //**************************************************************************************************
        unordered_map<int, int> m;
        int r = 0;
        for (int i : nums) {
            if (m[i]) continue;
            r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
        }
        return r;
    }
};