class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int>&a, const vector<int>&b){
            return (a[0] - a[1]) < (b[0] - b[1]);
        });
        int price=0;
        int n=costs.size();
        for(int i=0; i<n/2; i++)price += costs[i][0];
        for(int i=n/2; i<n; i++)price += costs[i][1];
        
        return price;
    }
};
        
        