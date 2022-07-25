class Solution {
public:
   
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas=0, total_cost=0; 
        for(auto i: gas)total_gas += i;
        for(auto i: cost)total_cost += i;
        
        if(total_gas < total_cost)return -1;
        
        int tank = 0;
        int n = gas.size();
        int ans =0;
        for(int i = 0; i < n; i++){
            tank += gas[i] - cost[i];
            if(tank < 0){
                tank = 0;
                ans = i + 1;
            }
        }
        return ans;
    }
};