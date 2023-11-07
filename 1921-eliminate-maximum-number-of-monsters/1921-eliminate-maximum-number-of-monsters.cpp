class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        for (int i = 0; i < dist.size(); ++i)
            dist[i] = (dist[i] - 1) / speed[i];
        sort(begin(dist), end(dist));
        for (int i = 0; i < dist.size(); ++i)
            if (i > dist[i])
                return i;
        return dist.size();
    }
};