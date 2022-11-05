class Solution {
public:
    struct Node {
        Node *child[26];
        string word;
        bool end;
        Node()
        {
            end = false;
            word = "";
            for(int i = 0; i < 26; i++)
                child[i] = NULL;    
        }
    };
    
    Node *root = new Node();
    void insert(string &s)
    {
        Node *curr = root;
        for(int i = 0 ; i < s.size(); i++)
        {
            int idx = s[i] - 'a';
            if(curr -> child[idx] == NULL)
            {
                curr -> child[idx] = new Node();
            }
            curr = curr -> child[idx];
        }
        curr -> end = true;
        curr -> word = s;
    }
    vector<string> ans;
    
    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n, Node *curr)
    {
        if(i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == '#')
            return;
        int idx = grid[i][j] - 'a';
        if(curr -> child[idx] == NULL)
            return;
        curr = curr -> child[idx];
        if(curr -> end == true)
        {
            ans.push_back(curr -> word);
            curr -> end = false;
        }
        char val = grid[i][j];
        grid[i][j] = '#';
        dfs(grid, i + 1, j, m, n, curr);
        dfs(grid, i, j + 1, m , n, curr);
        dfs(grid, i - 1, j, m , n , curr);
        dfs(grid, i, j - 1, m, n, curr);
        grid[i][j] = val;
    }
    vector<string> findWords(vector<vector<char>>& grid, vector<string>& words) {
        int m = grid.size();
        int n = grid[0].size();
        for(auto word : words)
        {
            insert(word);
        }
        for(int i = 0 ; i < m; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                dfs(grid, i, j, m ,n , root);
            }
        }
        return ans;
    }
};