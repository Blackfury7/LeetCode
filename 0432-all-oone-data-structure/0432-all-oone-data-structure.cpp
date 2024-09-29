struct Node {
    int freq;
    unordered_set<string> keys;
    Node *next, *prev;
    Node(int x, Node* next = NULL, Node* prev = NULL)
        : freq(x), next(next), prev(prev) {}
};

void remove(Node* curr) {// remove the Node from the list
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
}

class AllOne {
    Node* dummy; // dummy node for a circular doubly linked list
    unordered_map<string, Node*> mp; // Maps keys to the corresponding Node*

public:
    AllOne() {
        dummy = new Node(-1); // Create a dummy node
        dummy->next = dummy->prev = dummy;
        mp.reserve(50000);
    }

    void inc(string&& key) {
        if (!mp.count(key)) {
            // Key is new, insert into the first node (frequency 1)
            Node* node0 = dummy->next;
            if (node0 == dummy || node0->freq > 1) {
                Node* newNode = new Node(1, node0, dummy);
                newNode->keys.insert(key);

                dummy->next = newNode;
                node0->prev = newNode;
                mp[key] = newNode;
            } 
            else {
                node0->keys.insert(key);
                mp[key] = node0;
            }
        } 
        else {
            // Key exists, move it to the next node (frequency+1)
            Node* curr = mp[key];
            int freq = curr->freq;
            curr->keys.erase(key); // Remove key from the current node
            Node* nextNode = curr->next;

            if (nextNode == dummy || nextNode->freq > freq + 1) {
                // Create a new node for freq + 1
                Node* newNode = new Node(freq + 1, nextNode, curr);
                newNode->keys.insert(key);
                curr->next = newNode;
                nextNode->prev = newNode;
                mp[key] = newNode;
            } 
            else {
                // Insert key into the next node
                nextNode->keys.insert(key);
                mp[key] = nextNode;
            }

            if (curr->keys.empty()) {
                // Remove the current node
                remove(curr);
            }
        }
    }

    void dec(string&& key) {
        if (!mp.count(key))
            return; // Key doesn't exist

        Node* curr = mp[key];
        int freq = curr->freq;
        curr->keys.erase(key); // Remove key from the current node

        if (freq == 1) {
            // Remove the key entirely if the frequency is 1
            mp.erase(key);
        } 
        else {
            Node* prevNode = curr->prev;
            if (prevNode == dummy || prevNode->freq < freq - 1) {
                // Create a new node for freq - 1
                Node* newNode = new Node(freq - 1, curr, prevNode);
                newNode->keys.insert(key);
                prevNode->next = newNode;
                curr->prev = newNode;
                mp[key] = newNode;
            } 
            else {
                // Insert key into the previous node
                prevNode->keys.insert(key);
                mp[key] = prevNode;
            }
        }

        if (curr->keys.empty()) {
            // Remove the current node
            remove(curr);
        }
    }

    string getMaxKey() {
        return (dummy->prev == dummy) ? "" : *(dummy->prev->keys.begin());
    }

    string getMinKey() {
        return (dummy->next == dummy) ? "" : *(dummy->next->keys.begin());
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();


/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */