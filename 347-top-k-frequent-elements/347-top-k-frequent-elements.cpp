class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<pair<int,int>> v;
        
        for(auto i:nums)m[i]++;
        for(auto i:m){v.push_back(make_pair(i.second,i.first));}
        sort(v.begin(), v.end(), greater<>());
        vector<int> v1;
        // int n = v.size();
        for(int i=0;i<k;i++){
            v1.push_back(v[i].second);
        }
        return v1;
    }
};