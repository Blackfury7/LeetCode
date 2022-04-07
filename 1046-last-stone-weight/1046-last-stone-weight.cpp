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
        // Naive approach
        // time complexity : O(N * NlogN)
        // space complexity : O(1)
        
        // sort(stones.begin(),stones.end());
        // int a=stones.size()-1;
        // if(a==0){
        //     return stones[a];
        // }
        // for(int i=0;i<stones.size();i++){
        //     sort(stones.begin(),stones.end());
        //     if(stones[a]>0 && stones[a-1]>0){
        //         stones[a]=stones[a]-stones[a-1];
        //         stones[a-1]=0;
        //     }
        //     else{
        //         break;
        //     }
        // }
        // return stones[a];
        //******************************************************************************************
        
        // Recursion solution
        
        if(stones.size() == 0)
            return 0;
        if(stones.size() == 1)
            return stones.front();
        
        sort(stones.begin(),stones.end());
        
        int a = stones[stones.size()-1];
        int b = stones[stones.size()-2];
        
        stones.pop_back();
        stones.pop_back();
        
        if(a == b)
            return  lastStoneWeight(stones);
        stones.push_back(a-b);
        return lastStoneWeight(stones);
    
        //******************************************************************************************
    }
};