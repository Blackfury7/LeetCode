class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
  {
        vector<vector<int>> res;
        vector<pair<int, int>> height;
        multiset<int> m;
        int pre = 0, cur = 0;
        for (auto a : buildings)
        {
          height.push_back({a[0], -a[2]});
          height.push_back({a[1], a[2]});
        }
        sort(height.begin(), height.end());
        m.insert(0);
        for (auto h : height)
        {
          if (h.second < 0)
            m.insert(-h.second);
          else
            m.erase(m.find(h.second));
          cur = *m.rbegin();
          if (cur != pre)
          {
            res.push_back({h.first, cur});
            pre = cur;
          }
        }
        return res;
  }
};
