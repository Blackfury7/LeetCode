class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int ans = 1;
        unordered_set<int> s;
        for (int i:rolls){
            s.insert(i);
            if(s.size() == k) {
                ans++;
                s.clear();
            }
        }
        return ans;
    }
};