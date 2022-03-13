class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto i:nums)m[i]++;
        vector<int> v1;
        
        
//********************************** sort Vector approach  *******************************************        
        // vector<pair<int,int>> v;
        // for(auto i:m){v.push_back(make_pair(i.second,i.first));}
        // sort(v.begin(), v.end(), greater<>());
        // // int n = v.size();
        // for(int i=0;i<k;i++){
        //     v1.push_back(v[i].second);
        // }
//****************************************************************************************************        
       

        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto i:m){
            pq.push(make_pair(i.second,i.first));
            if(pq.size()>k)pq.pop();
        }
        
        while(!pq.empty()){
            v1.push_back(pq.top().second);
            pq.pop();
        }
        
        
        return v1;
    }
};