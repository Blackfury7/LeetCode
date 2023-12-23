struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        return h1 ^ h2;
    }
};

class Solution {
public:
    bool isPathCrossing(std::string path) {
        int x = 0, y = 0;
        std::unordered_set<std::pair<int, int>, pair_hash> visited;
        visited.insert({0, 0});

        for (char direction : path) {
            x += (direction == 'E') ? 1 : ((direction == 'W') ? -1 : 0);
            y += (direction == 'N') ? 1 : ((direction == 'S') ? -1 : 0);

            if (visited.find({x, y}) != visited.end()) {
                return true;
            }

            visited.insert({x, y});
        }

        return false;
    }
};