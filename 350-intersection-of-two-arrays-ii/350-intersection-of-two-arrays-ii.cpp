class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        // Using Map without sort
        unordered_map<int,int>freq;
        vector<int>ans;
        int n = nums1.size();
        int m = nums2.size();
        for(int i =0; i<n; i++) freq[nums1[i]]++;
        
        for(int i=0; i<m; i++) {
            if(freq[nums2[i]] > 0 ) {
                freq[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
        
        
        // Two pointer Approach
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());
        
//         int n = nums1.size();
//         int m = nums2.size();
//         vector<int> v;
//         int i,j;i=j=0;
//         while(i<n && j<m){
//             if(nums1[i] == nums2[j]){
//                 v.push_back(nums1[i]);
//                 i++;j++;
//             }else if(nums1[i]>nums2[j]){
//                 j++;
//             }
//             else{
//                 i++;
//             }
//         }
//         return v;
//     }
};