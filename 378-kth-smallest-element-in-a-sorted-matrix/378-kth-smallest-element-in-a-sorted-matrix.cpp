class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        priority_queue<int> pq;
        
        if(!k)return 0;
        
        for(auto i:matrix) {
            for(auto j: i){
                pq.push(j);
                if(pq.size() >k){pq.pop();if(pq.top()<=j)break;}
            }
        }
       
        return pq.top();
    }
};