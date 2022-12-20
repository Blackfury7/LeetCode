class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        for(int i = 0;i < rooms[0].size();i++){
            q.push(rooms[0][i]);
        }
        vector<int>vis(rooms.size());
        vis[0] = 1;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            vis[temp] = 1;
            for(int i = 0;i < rooms[temp].size();i++)
                if(vis[rooms[temp][i]] == 0)
                    q.push(rooms[temp][i]);
            }
        for(int i = 0;i < vis.size();i++){
            if(vis[i] == 0)
                return false;
        }
        return true;
    }
};