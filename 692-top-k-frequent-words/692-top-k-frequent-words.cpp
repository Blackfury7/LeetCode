class Solution {
public:
    // struct myComp
    // {
    //     constexpr bool operator()(
    //         pair<int, int> const &a,
    //         pair<int, int> const &b)
    //         const noexcept
    //     {
    //         return a.second < b.second;//max heap
    //     }
    // };
    
    public: static bool myComp(pair<int,string> a, pair<int,string> b) {
        if(a.first == b.first)
            return ((a.second).compare(b.second) < 0);
        else
            return (a.first > b.first);
    }
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
         unordered_map<string,int> m;
        vector<pair<int,string>> v;
        
        for(auto i:words)m[i]++;
        for(auto i:m){v.push_back(make_pair(i.second,i.first));}
        sort(v.begin(), v.end(), myComp);

        // int n = v.size();
         vector<string> v1;
        for(int i=0;i<k;i++){
            v1.push_back(v[i].second);
        }
       

        
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//         for(auto i:m){
//             pq.push(make_pair(i.second,i.first));
//             if(pq.size()>k)pq.pop();
//         }
        
//         while(!pq.empty()){
//             v1.push_back(pq.top().second);
//             pq.pop();
//         }
        
        
        return v1;
    }
    
};