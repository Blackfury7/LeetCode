// class Solution {
// private:
//     void solve(vector<int>& nums,set<vector<int>> &ans,vector<int> t){
//         if(t.size()==nums.size()){            // Base case-> if temporsry vector size becomes equal to size of given list 
//             ans.insert(t);                // Before returning store the valid permutation inside the ans
//             return ;
//         }
        
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]!=11){            // check if the element is already included
//                 int j=nums[i];
//                 nums[i]=11;        // make the current ele to 11 (which is out of the range) so that we will not insert this element in next call
//                 t.push_back(j);      // store it in the temporary vector
//                 solve(nums,ans,t);  //recursively call to complete the permutations
//                 nums[i]=j;      // backtrack 
//                 t.pop_back();
//             }
//         }
//     }
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         set<vector<int>> s;          //to store unique permutations
//         vector<vector<int>> ans;
        
//         solve(nums,s,{});
        
//         for(auto i:s){
//             ans.push_back(i);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};