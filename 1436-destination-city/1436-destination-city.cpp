class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string des;
        for(int i=0;i<paths.size();i++){ 
                int t=0; // 0: w/o outlet; 1: w output
                string& tmp=paths[i][1];
                for(int j=0;j<paths.size();j++)
                    if(paths[j][0]==tmp){
                        t=1;break;
                    }
                if(t==0){
                    des=tmp;
                    break;
                }
        }
        return des;
    }
};