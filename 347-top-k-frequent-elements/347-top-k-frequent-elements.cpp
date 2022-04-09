class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_map<int,int>m;
        for(auto i:nums)m[i]++;
        for(auto i:m){
            pq.push(make_pair(i.second,i.first));
            if(pq.size() > k)pq.pop();
        }
        vector<int>v;
        while(!pq.empty()){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};