class LRUCache {
    using list_value_type = pair<int, int>;
    using list_type = list<list_value_type>;
    size_t m_capacity = 0;
    unordered_map<int, list_type::iterator> m_key_to_node;
    list_type m_nodes;
public:
    LRUCache(int capacity) : m_capacity(capacity) {}
    
    int get(int key) {
        auto it = m_key_to_node.find(key);
        if (it == end(m_key_to_node))
            return -1;
        
        m_nodes.splice(begin(m_nodes), m_nodes, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        // If key doesn't exist -> insert at back
        // Else update value and update LRU cache
        // At end, check for capacity and remove the tail from both collections
        auto it = m_key_to_node.find(key);
        if (it != end(m_key_to_node)) {
            it->second->second = value;
            m_nodes.splice(begin(m_nodes), m_nodes, it->second);
            return;
        }

        m_nodes.emplace_front(key, value);
        m_key_to_node[key] = begin(m_nodes);
        if (m_key_to_node.size() > m_capacity) {
            m_key_to_node.erase(m_nodes.back().first);
            m_nodes.pop_back();
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */