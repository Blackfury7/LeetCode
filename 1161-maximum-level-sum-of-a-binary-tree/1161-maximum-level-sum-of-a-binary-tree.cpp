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
    int maxLevelSum(TreeNode* root) {
        int maxSumLevel = 1; // Initialize with the root level
        int maxSum = root->val; // Initialize with the root value

        if (root == nullptr)
            return maxSumLevel;

        queue<TreeNode*> q;
        q.push(root);
        int level = 1;

        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();

                levelSum += current->val;

                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }

            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxSumLevel = level;
            }

            level++;
        }

        return maxSumLevel;
    }
};