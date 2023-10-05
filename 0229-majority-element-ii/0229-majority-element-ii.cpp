
/*

    Time Complexity : O(NlogN), Sorting the array(nums) costs O(NlogN). Where N is the size of the Array(nums).

    Space Complexity : O(1), Constant Space. Because unordered_set(set) and Array(output) will maximum store 2
    element not more than that.

    Solved using Array + Sorting + Hash Table(Unordered set).

*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 1){
            return {nums[0]};
        }
        if(nums.size() == 2 && nums[0] != nums[1]){
            return {nums[0], nums[1]};
        }
        sort(nums.begin(), nums.end());
        int countMajority = nums.size()/3;
        unordered_set<int> set;
        vector<int> output;
        int count = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] == nums[i]){
                count++;
                if(count > countMajority){
                    set.insert(nums[i]);
                }
            }
            else{
                count = 1;
            }
        }
        for(int it : set){
            output.push_back(it);
        }
        return output;
    }
};