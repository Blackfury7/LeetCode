/*

    Time Complexity : O(N), Boyer-Moore performs constant work exactly N times, so the algorithm runs in
    linear time. Where N is the size of the Array(nums).

    Space Complexity : O(1), Constant Space. Because we are creating Array(output) as per the demand of
    program so it doesnot count as auxilary space also Array(output) will maximum store 2 element not more than
    that which is a constant. 

    Solved using Boyer-Moore Voting Algorithm.

*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = INT_MIN, num2 = INT_MIN;
        int count1 = 0, count2 = 0;
        for(auto element : nums){
            if(num1 == element){
                count1++;
            }
            else if(num2 == element){
                count2++;
            }
            else if(count1 == 0){
                num1 = element;
                count1 = 1;
            }
            else if(count2 == 0){
                num2 = element;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int> output;
        int countMajority = nums.size()/3;
        count1 = 0, count2 = 0;
        for(auto element : nums){
            if(num1 == element){
                count1++;
            }
            if(num2 == element){
                count2++;
            }
        }
        if(count1 > countMajority){
            output.push_back(num1);
        }
        if(count2 > countMajority){
            output.push_back(num2);
        }
        return output;
    }
};

















// Aproach 2


/*

    Time Complexity : O(NlogN), Sorting the array(nums) costs O(NlogN). Where N is the size of the Array(nums).

    Space Complexity : O(1), Constant Space. Because unordered_set(set) and Array(output) will maximum store 2
    element not more than that.

    Solved using Array + Sorting + Hash Table(Unordered set).

*/

// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         if(nums.size() == 1){
//             return {nums[0]};
//         }
//         if(nums.size() == 2 && nums[0] != nums[1]){
//             return {nums[0], nums[1]};
//         }
//         sort(nums.begin(), nums.end());
//         int countMajority = nums.size()/3;
//         unordered_set<int> set;
//         vector<int> output;
//         int count = 1;
//         for(int i=1; i<nums.size(); i++){
//             if(nums[i-1] == nums[i]){
//                 count++;
//                 if(count > countMajority){
//                     set.insert(nums[i]);
//                 }
//             }
//             else{
//                 count = 1;
//             }
//         }
//         for(int it : set){
//             output.push_back(it);
//         }
//         return output;
//     }
// };