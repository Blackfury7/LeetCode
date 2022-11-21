
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance){
        int m=maze.size();
        int n=maze[0].size();
        queue<pair<int,int>> q;
        int ans=0;
        q.push(make_pair(entrance[0],entrance[1]));
        maze[entrance[0]][entrance[1]]='+';  //marking as visited
        while(!q.empty()){
            ans++;
            int elements=q.size();
            while(elements--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(i+1<m and maze[i+1][j]!='+'){
                    if((i+1)==(m-1) or (i+1)==0 or j==0 or j==(n-1)){return ans;}
                    q.push(make_pair(i+1,j));
                    maze[i+1][j]='+';}
                if(i-1>(-1) and maze[i-1][j]!='+'){
                    if((i-1)==(m-1) or (i-1)==0 or j==0 or j==(n-1)){return ans;}
                    q.push(make_pair(i-1,j));
                    maze[i-1][j]='+';}
                if(j+1<n and maze[i][j+1]!='+'){
                    if((i)==(m-1) or (i)==0 or (j+1)==0 or (j+1)==(n-1)){return ans;}
                    q.push(make_pair(i,j+1));
                    maze[i][j+1]='+';}
                if(j-1>(-1) and maze[i][j-1]!='+'){
                    if((i)==(m-1) or (i)==0 or (j-1)==0 or (j-1)==(n-1)){return ans;}
                    q.push(make_pair(i,j-1));
                    maze[i][j-1]='+';}

            }
        }
        return -1;

        
    }
};