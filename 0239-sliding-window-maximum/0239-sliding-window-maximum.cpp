class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int, greater<int> > st;

        for(int i=0; i<k; i++){
            st.insert(nums[i]);
        }

        ans.push_back(*st.begin());

        for(int i=k; i<nums.size(); i++){
            st.erase(st.find(nums[i-k]));
            st.insert(nums[i]);
            ans.push_back(*st.begin());
        }

        return ans;
    }
};