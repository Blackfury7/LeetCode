class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        set<int> m;
        for(int i=0;i<arr.size()-1;i++){
            int different = arr[i]-arr[i+1];
            m.insert(different);
        }
        if(m.size()==1)
            return true;
        return false;
    }
};