class Solution {
public:
    
    
    long long countExcellentPairs(vector<int>& A, int k) {
        long long cnt[30] = {}, ans = 0;
        for(int a : unordered_set<int>(begin(A), end(A)))
            ++cnt[__builtin_popcount(a)];
        for(int i = 1; i < 30; i++)
            for(int j = 1; j < 30; j++ )
                if(i + j >= k)
                ans += cnt[i] * cnt[j];
        
        return ans;
    }
    
    
    
    
    
    /*
    struct myCompare {
     bool operator()(const pair<int, int>& value,
            const int& key)
     {
      return (value.first < key);
     }
     bool operator()(const int& key,
         const pair<int, int>& value)
     {
      return (key < value.first);
     }
    };
    long long countExcellentPairs(vector<int>& arr, int k) {
        long long freq=0,f=0;

        set<int> nums(arr.begin(), arr.end());

        int n = nums.size();
        set<int>::iterator i,j;
        vector<pair<int,int>>v;
        for(auto i:nums){
            v.push_back({__builtin_popcount(i), i});
        }
        sort(v.begin(), v.end());
        // binary_search(vect.begin(),vect.end(),n,comp());
         pair<int, int> p = { k, 0 };
        int x = (lower_bound(v.begin(), v.end(), p) - v.begin());
        cout<<x<<endl;
        
        freq = max(2*n*(n-x) - (n-x), 0) ;
        cout<<freq<<endl;
        
        for(int i=0;i<x;i++){
            int a = v[i].second;
            if((v[i].first * 2) >= k){
                    freq++;
                }
            for(int j=i+1;j<x;j++){
                int b = v[j].second;
                if(__builtin_popcount((a&b)) + __builtin_popcount((a|b)) >= k){
                    f++;
                }
            }
        }
        return freq + (f * 2);
    }
    */
};