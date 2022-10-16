class Solution {
public:
    int rev(int a) {
        int r=0;
        while(a) {
            r = r*10 + a%10;
            a/=10;
        }
        return r;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for(auto &i:nums) {
            s.insert(i);
            int x = rev(i);
            s.insert(x);
        }
        return s.size();
    }
};