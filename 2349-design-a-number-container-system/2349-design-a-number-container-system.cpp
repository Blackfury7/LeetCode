class NumberContainers {
public:
    //**********************************************************************************************************************
//     map<int,int>v;
//     NumberContainers() {
        
//     }
    
//     void change(int index, int number) {
//         v[index]=number;
//     }
    
//     int find(int number) {
//         for(auto it: v)
//             if(it.second == number)
//                 return it.first;
//         return -1;
//     }
    //**********************************************************************************************************************
    //**********************************************************************************************************************
   
    map<int, set<int>>m;
    map<int, int> A;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        set<int>::iterator it = m[A[index]].find(index);
        if(it != m[A[index]].end()) m[A[index]].erase(it);
        A[index] = number;
        m[number].insert(index);
    }
    
    int find(int number){
        if(m[number].size()) return *(m[number].begin());
        return -1;
    }
    
    //**********************************************************************************************************************
    
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */