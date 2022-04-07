class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        //******************************************************************************************
        //Complexity
        // Time O(NlogN)
        // Space O(N)
        
        // priority_queue<int> pq(begin(stones), end(stones));
        // while (pq.size() > 1) {
        //     int x = pq.top(); pq.pop();
        //     int y = pq.top(); pq.pop();
        //     if (x > y) pq.push(x - y);
        // }
        // return pq.empty() ? 0 : pq.top();
        
        //******************************************************************************************
        
//         priority_queue<int> pq;
//         for(auto i:stones)pq.push(i);
        
//         while(!pq.empty()){
//             int a = pq.top();pq.pop();
//             if(pq.empty())return a;
//             int b = pq.top();pq.pop();
//             a = a-b;
//             if(pq.empty())return a;
//             if(a)pq.push(a);
//         }
//         return 0;
        
        //******************************************************************************************
        
        sort(stones.begin(),stones.end());
        int a=stones.size()-1;
        if(a==0){
            return stones[a];
        }
        for(int i=0;i<stones.size();i++){
            sort(stones.begin(),stones.end());
            if(stones[a]>0 && stones[a-1]>0){
                stones[a]=stones[a]-stones[a-1];
                stones[a-1]=0;
            }
            else{
                break;
            }
        }
        return stones[a];
        //******************************************************************************************
    }
};