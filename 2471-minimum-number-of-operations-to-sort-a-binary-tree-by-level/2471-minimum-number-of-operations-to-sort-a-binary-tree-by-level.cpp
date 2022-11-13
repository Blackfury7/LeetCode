/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void swap(vector<int> &arr, int i, int j)
    {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
    int minSwaps(vector<int>&arr,
             int N)
    {
      int ans = 0;
      vector<int>temp = arr;
      map <int, int> h;
      sort(temp.begin(), temp.end());
      for (int i = 0; i < N; i++)
      {
        h[arr[i]] = i;
      }
      for (int i = 0; i < N; i++)
      {
        if (arr[i] != temp[i])
        {
          ans++;
          int init = arr[i];

          swap(arr, i, h[temp[i]]);
          h[init] = h[temp[i]];
          h[temp[i]] = i;
        }
      }
      return ans;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            vector<int>level;
            int level_size = q.size();
            for(int i = 0; i < level_size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        vector<vector<int>> v = levelOrder(root);
        int ans = 0;
        for(auto &i: v) {
            vector<int> v1(i.begin(), i.end());
            int f = 0;
            int n = v1.size();
            ans += minSwaps(v1, n);
        }
        return ans;
    }
};