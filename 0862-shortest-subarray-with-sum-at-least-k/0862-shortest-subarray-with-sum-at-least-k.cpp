class Solution {
public:
    #define ll long long
    int shortestSubarray(vector<int>& A, int K) {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>> > pq;
        ll sum = 0;
        ll ans = 1e18;
        for( ll i = 0; i<A.size(); i++){
            sum += (ll)A[i];
            if( sum >= K ){
                ans = min(ans, i+1);
            }
            while( pq.size() && sum - pq.top().first >= K ){
                auto &p = pq.top();
                ans = min(ans, i-p.second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        return ans == 1e18?-1:ans;
    }
};