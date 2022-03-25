class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int>&a, const vector<int>&b){
            return (a[0] - a[1]) < (b[0] - b[1]);
        });
        
        int price = 0;
        for(int i = 0; i < costs.size() / 2; i++){
            price += costs[i][0];
        }
        for(int i = costs.size() / 2; i < costs.size(); i++){
            price += costs[i][1];
        }
        return price;
    }
};










// class Solution {
// public:
//     int twoCitySchedCost(vector<vector<int>>& costs) {
//         vector<pair<int,int>> a,b;
//         int n=costs.size();
//         for(int i=0;i<n;i++){
//             a.push_back(make_pair(costs[i][0],i));
//             b.push_back(make_pair(costs[i][1],i));   
//         }
//     sort(a.begin(),a.end());
//     sort(b.begin(), b.end());
//         for(auto i:a)cout<<i.first<<" "<<i.second<<endl;
//         cout<<"\n\nBBBB\n\n";
//         for(auto i:b)cout<<i.first<<" "<<i.second<<endl;
      
//        vector<int> flag (n);
//         int sum=0;
//         int i,j,c1,c2;
//     for( i=0,j=0,c1=0,c2=0;c1<n/2 && c2<n/2 && i<n && j<n;){
       
//         if(a[i].first <= b[j].first) {
//             sum+=a[i].first;
//             flag[a[i].second]=1;
//             i++; c1++;
//         }
//            else{
//                sum+=b[j].first;
//             flag[b[j].second]=1;
//                j++; c2++;
//            }
//          while(flag[a[i].second])i++;
//        while(flag[b[j].second])j++;
//     }
//     if(c1<n/2){
//         while(c1<n/2){
            
//         while(flag[a[i].second])i++;
//         sum+=a[i].first;
//        flag[a[i].second]=1;
//         i++;c1++;
//        }
//     }else if(c2<n/2){
//         while(c2<n/2){
            
//         while(flag[b[j].second])j++;
//         sum+=b[j].first;
//        flag[b[j].second]=1;
//         j++;c2++;
//        }
//     }
//  return sum;
//     }
// };