class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
    //**************************************************************************************************
        
        unordered_set<int> hashSet(nums.begin(), nums.end());
        int res = 0;
        for(int i:nums){
            if(hashSet.find(i) == hashSet.end()) continue;
            hashSet.erase(i);
            int prev = i - 1, next = i + 1;
            while(hashSet.find(prev) != hashSet.end()) hashSet.erase(prev--);
            while(hashSet.find(next) != hashSet.end()) hashSet.erase(next++);
            res = max(res, next - prev - 1);
        }
        return res;
    }
        
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
        
    //     unordered_map<int, int> m;
    //     int r = 0;
    //     for (int i : nums) {
    //         if (m[i]) continue;
    //         r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
    //     }
    //     return r;
    // }
    //**************************************************************************************************
};