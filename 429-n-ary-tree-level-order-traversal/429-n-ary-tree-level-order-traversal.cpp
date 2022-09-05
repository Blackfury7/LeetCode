/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
     vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            vector<int> tmp;
            int n = que.size();
            while(n--){
                auto it = que.front();
                que.pop();
                tmp.push_back(it->val);
                for(auto child: it->children){
                    que.push(child);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};