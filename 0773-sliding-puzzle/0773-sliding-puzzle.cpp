class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        string target = "123450";
        set<string> vis; 
        queue<string> q;
        string start = "";

        
        for (auto row : board) {
            for (auto col : row) {
                start += col + '0';
            }
        }

        q.push(start);
        vis.insert(start);
        int step = 0;

        // Perform BFS
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string current = q.front();
                q.pop();

                
                if (current == target) return step;

                int zero = current.find('0'); 

                // Generate next moves
                for (auto move : dir[zero]) {
                    string next = current;
                    swap(next[move], next[zero]);
                    if (!vis.count(next)) { 
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};