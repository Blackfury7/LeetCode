class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        
        for(auto &i: piles) pq.push(i);
        while(k--){
            int a = pq.top();
            pq.pop();
            a += (a&1);
            a>>=1;
            pq.push(a);
        }

        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};