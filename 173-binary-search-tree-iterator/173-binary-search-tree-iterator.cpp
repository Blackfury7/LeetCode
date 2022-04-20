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
class BSTIterator {
public:
    
    TreeNode* inorder(TreeNode *cur, TreeNode *pre) {
        if (cur == nullptr) return pre;
        TreeNode *now = inorder(cur->left, pre);
        now->right = cur;
		now->left = nullptr;
        return inorder(cur->right, now->right);
    }
    
    BSTIterator(TreeNode* root) {
        inorder(root, node);
    }
    
    int next() {
        node = node->right;
        return node->val;
    }
    
    bool hasNext() {
        return node->right != nullptr;
    }
private:
    TreeNode *node = new TreeNode(0);
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */