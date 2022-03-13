class Solution {
public:
    struct myComp
    {
        constexpr bool operator()(
            pair<int, string> const &a,
            pair<int, string> const &b)
            const noexcept
        {
            // return a.first < b.first; //max heap
            if(a.first == b.first)
                return ((a.second).compare(b.second) < 0);
            else
                return (a.first > b.first);
        }
    };
    
    // public: static bool myComp(pair<int,string> a, pair<int,string> b) {
    //     if(a.first == b.first)
    //         return ((a.second).compare(b.second) < 0);
    //     else
    //         return (a.first > b.first);
    // }
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
         unordered_map<string,int> m;
        // vector<pair<int,string>> v;
        
        for(auto i:words)m[i]++;
        // for(auto i:m){v.push_back(make_pair(i.second,i.first));}
        // sort(v.begin(), v.end(), myComp);

        // int n = v.size();
         vector<string> v1;
        // for(int i=0;i<k;i++){
        //     v1.push_back(v[i].second);
        // }
       

        
        priority_queue<pair<int,string>, vector<pair<int,string>>, myComp> pq;
        for(auto i:m){
            pq.push(make_pair(i.second,i.first));
            if(pq.size()>k)pq.pop();
        }
        
        while(!pq.empty()){
            v1.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(v1.begin(), v1.end());
        
        
        return v1;
    }
    
};