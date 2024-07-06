class Solution {
public:
    #define ll long long int
     const int MX = (1LL << 31) - 1;

    struct Node {
        int mx = (1LL << 31) - 1;
        ll val;
        Node(): val(mx) {}
        Node(ll v): val(v){}

        friend Node merge(Node l, Node r) {return Node(l.val & r.val);} // may change
        void update(ll v) {val = v;} // may change
    };

    // Never change this
    struct SegmentTree {
        int n;
        vector<Node> seg;
        SegmentTree(int _n): n(_n), seg(2 * _n) {}
        template <typename Type>
        SegmentTree(vector<Type> a) {
            n = int(a.size());
            seg.resize(2 * n);
            for(int i = 0; i < n; i++) seg[i + n] = Node(a[i]);
            for(int i = n - 1; i > 0; i--) seg[i] = merge(seg[i<<1], seg[i << 1 | 1]);

        }
        void update(int i, ll v) {
            for(seg[i += n].update(v); i >>=1; ) seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
        }
        Node query(int l, int r) {
            Node resl, resr;
            for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
                if(l & 1) resl = merge(resl, seg[l++]);
                if(r & 1) resr = merge(seg[--r], resr);
            }
            return merge(resl, resr);
        }
    };

    long long countSubarrays(vector<int>& a, int k) {
        SegmentTree sg(a);
        
        int n = a.size();
        ll ans = 0;
        
        // binary search
        auto find = [&] (int i) {
            int start = i, end = n - 1; 
            ll res = n;
        
            while(start <= end) {
                int mid = (start + end) >> 1;
                if(sg.query(i, mid).val <= k) res = mid, end = mid - 1;
                else start = mid + 1;
            }
            return res;
        };
        auto find1 = [&] (int i) {
            int start1 = i, end1 = n - 1;
            ll res1 = n;
        
            while(start1 <= end1) {
                int mid = (start1 + end1) >> 1;
                if(sg.query(i, mid).val >= k) res1 = mid, start1 = mid + 1;
                else end1 = mid - 1;
            }
            return res1;
        };
        
        for(int i = 0 ; i < n; i++) {
            int a1 = find(i);
            int b = find1(i);
            if(a1 < n and b < n){
                if((sg.query(i,a1).val == k) and (sg.query(i,b).val == k))
                    ans += b-a1+1;
            } 
        }
        
     
        return ans;
    }
};