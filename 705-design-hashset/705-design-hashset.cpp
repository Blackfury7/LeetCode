class MyHashSet {
    vector<vector<int>> map;
public:
    MyHashSet() {
        map.resize(1000001/100 + 1, vector<int> (100, -1));
    }
    
    void add(int key) {
        int num = key/100;
        int remain = key%100;
        map[num][remain] = 1;
    }
    
    void remove(int key) {
        int num = key/100;
        int remain = key%100;
        map[num][remain] = -1;
    }
    
    bool contains(int key) {
        int num = key/100;
        int remain = key%100;
        return map[num][remain] != -1;
    }
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */