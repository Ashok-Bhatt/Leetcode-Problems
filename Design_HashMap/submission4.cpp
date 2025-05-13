class MyHashMap {
public:
    vector<int> mapping;

    MyHashMap() {
        for (int i=0; i<=10e6; i++){
            mapping.push_back(-1);
        }
    }
    
    void put(int key, int value) {
        mapping[key] = value;
    }
    
    int get(int key) {
        return mapping[key];
    }
    
    void remove(int key) {
        mapping[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */