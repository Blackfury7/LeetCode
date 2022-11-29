class RandomizedSet {
public:
    vector<int>vec;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        auto itr = find(vec.begin(),vec.end(),val); 
        if(itr != vec.end())return false;
        else
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        auto itr = find(vec.begin(),vec.end(),val);
        if(itr == vec.end())return false;
        else
        vec.erase(itr);
        return true;
    }
    
    int getRandom() {
        int num = rand() % vec.size();
        return vec[num];
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */