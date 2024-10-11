class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int t_arrival = times[targetFriend][0];
        sort(begin(times), end(times));
        multimap<int, int> reserved;
        set<int> avail;
        for (auto &t : times) {
            while (!reserved.empty() && begin(reserved)->first <= t[0]) {
                avail.insert(begin(reserved)->second);
                reserved.erase(begin(reserved));
            }
            if (t[0] == t_arrival)
                break;
            if (avail.empty())
                reserved.insert({t[1], reserved.size()});
            else {
                reserved.insert({t[1], *begin(avail)});
                avail.erase(begin(avail));
            }
        }
        return avail.empty() ? reserved.size() : (*begin(avail));
    }
};