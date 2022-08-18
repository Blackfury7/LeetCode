class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int>mp;
        priority_queue<int> pq;
		for(auto num : arr) mp[num]++;                  
        for(auto [num, freq] : mp) pq.push(freq);
        for(int deleted{}, ans{}; ;pq.pop()) {
            deleted += pq.top(), ans++;
            if(deleted >= size(arr) / 2) return ans;    
        }
        return -1;
    }
};