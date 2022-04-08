class KthLargest {
public:
   
    int id;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    KthLargest(int k, vector<int>& nums) {
        id = k;
        
        for(auto i:nums){
            pq.push(i);
            if(pq.size()>k)pq.pop();
        }
        
    }
    
    int add(int val) {
       
       
        pq.push(val);
        while(pq.size() > id){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */