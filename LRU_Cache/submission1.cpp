class LRUCache {
public:
    deque<int> dq;
    unordered_map<int, int> mapping, count;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {

        dq.push_back(key);
        count[key]++;

        if (mapping.find(key) == mapping.end()){
            return -1;
        } else {
            return mapping[key];
        }
    }
    
    void put(int key, int value) {
        if (mapping.find(key) != mapping.end()){
            dq.push_back(key);
            count[key]++;
            mapping[key] = value;
        } else if (mapping.size() < capacity){
            dq.push_back(key);
            count[key]++;
            mapping[key] = value;
        } else {
            while (mapping.size() >= capacity){
                int front = dq.front();
                dq.pop_front();
                count[front]--;
                if (count[front] == 0){
                    mapping.erase(front);
                }
            }

            dq.push_back(key);
            count[key]++;
            mapping[key] = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */