class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& b) {
        vector<int> item_in(n);
        vector<vector<int>> item_adj(n);
        int gd = m;
        // this is to make negatives their own group
        for (int i  = 0; i < group.size(); i++) {
            if (group[i] == -1) {
                group[i] = gd++;
            }
        }
        vector<int> group_in(gd);
        vector<vector<int>> group_adj(gd);
        for (int i = 0; i < b.size(); i++) {
            for (int j = 0; j < b[i].size(); j++) {
                int item = b[i][j];
                item_in[i]++;
                item_adj[item].push_back(i);
                // if the groups are not the same
                if (group[item] != group[i]) {
                    group_in[group[i]]++;
                    group_adj[group[item]].push_back(group[i]);
                }
            }
        }

        // now topo sort for overall order
        queue<int> q;
        vector<int> item_order;
        for (int i = 0; i < item_in.size(); i++) {
            if (item_in[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            item_order.push_back(cur);
            for (auto it : item_adj[cur]) {
                item_in[it]--;
                if (item_in[it] == 0) q.push(it);
            }
        }
        // topo sort for group order
        vector<int> group_order;
        for (int i = 0; i < group_in.size(); i++) {
            if (group_in[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            group_order.push_back(cur);
            for (auto it : group_adj[cur]) {
                group_in[it]--;
                if (group_in[it] == 0) q.push(it);
            }
        }
        // check if possible
        if (item_order.size() != n) return {};
        if (group_order.size() != gd) return {};
        // sort elements within groups
        unordered_map<int, vector<int>> sorted_groups;
        for (int i = 0; i < item_order.size(); i++) {
            sorted_groups[group[item_order[i]]].push_back(item_order[i]);
        }
        // now append to groups
        vector<int> ret;
        for (int i = 0; i < group_order.size(); i++) {
            for (int j = 0; j < sorted_groups[group_order[i]].size(); j++) {
                ret.push_back(sorted_groups[group_order[i]][j]);
            }
        }
        return ret;
        
    }
};