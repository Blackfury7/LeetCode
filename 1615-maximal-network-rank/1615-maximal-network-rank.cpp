class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> cityRank;
        unordered_map<int, unordered_set<int>> connectedCities;
        for (const auto& road : roads) {
            cityRank[road[0]]++;
            cityRank[road[1]]++;
            connectedCities[road[0]].insert(road[1]);
            connectedCities[road[1]].insert(road[0]);
        }
        int maxRank = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int rank = cityRank[i] + cityRank[j];
                if (connectedCities[i].count(j) > 0) {
                    rank--;
                }
                maxRank = max(maxRank, rank);
            }
        }
        return maxRank;
    }
};