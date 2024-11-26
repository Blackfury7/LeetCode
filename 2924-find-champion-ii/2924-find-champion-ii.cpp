class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> lost(n);
        for (const auto &e : edges)
            lost[e[1]] = true;
        int j = find(begin(lost), end(lost), false) - begin(lost);
        return count(begin(lost), end(lost), false) == 1 ? j : -1;
    }
};