class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i:stones)pq.push(i);
        
        while(!pq.empty()){
            int a = pq.top();pq.pop();
            if(pq.empty())return a;
            int b = pq.top();pq.pop();
            a = a-b;
            if(pq.empty())return a;
            if(a)pq.push(a);
        }
        return 0;
    }
};