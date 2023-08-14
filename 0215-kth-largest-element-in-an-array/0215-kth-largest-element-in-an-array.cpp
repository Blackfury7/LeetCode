class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto i:nums){
            pq.push(i);
            if(pq.size() > k){
                if(!(pq.empty()))
                pq.pop();
            }
        }
        int n=0;
        if(!(pq.empty()))
           n= pq.top();
        return n;
    }
};