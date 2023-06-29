class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dir[5] = {0, -1, 0, 1, 0};
        queue<vector<int>> q;
        int sr = -1, sc = -1;
        int allKeysMask = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f'){
                    allKeysMask += (1 << (grid[i][j] - 'a'));
                }else if (grid[i][j] == '@'){
                    sr = i;
                    sc = j;
                }
            }
        }
        vector<vector<vector<bool>>> visited(allKeysMask+1, vector<vector<bool>>(m, vector<bool>(n, false)));
        q.push({sr, sc, 0, 0});
        visited[0][sr][sc] = true;
        while(!q.empty()){
            vector<int> cur = q.front();
            q.pop();
            int curR = cur[0], curC = cur[1], curKeyMask = cur[2], dist = cur[3];
            for(int i=0; i<4; i++){
                int nxtR = curR + dir[i], nxtC = curC + dir[i+1];
                if (nxtR >= 0 && nxtR < m && nxtC>=0 && nxtC<n && grid[nxtR][nxtC] != '#'){
                    char cell = grid[nxtR][nxtC];
                    if (cell >= 'a' && cell <= 'f'){
                        if (((1<< (cell-'a')) & curKeyMask) != 0){
                            continue;
                        }
                        int newKeyMask = (curKeyMask | (1 << (cell - 'a')));
                        if (newKeyMask == allKeysMask){
                            return dist+1;
                        }
                        visited[newKeyMask][nxtR][nxtC] = true;
                        q.push({nxtR, nxtC, newKeyMask, dist+1});
                    }
                    if (cell >= 'A' && cell <= 'F' && (((1<< (cell-'A')) & curKeyMask) == 0)){
                        continue;
                    }else if (!visited[curKeyMask][nxtR][nxtC]){
                        visited[curKeyMask][nxtR][nxtC] = true;
                        q.push({nxtR, nxtC, curKeyMask, dist+1});
                    }
                }
            }
        }
        return -1;
    }
};