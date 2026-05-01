class MyHashSet {
public:
    vector<int> set;
    
    MyHashSet() {
    }
    
    void add(int key) {
        if(contains(key)) {
            return;
        } else {
            set.push_back(key);
        }
    }
    
    void remove(int key) {
        for(int i=0; i<set.size(); i++) {
            if(set[i] == key) set.erase(set.begin()+i);
        }
    }
    
    bool contains(int key) {
        for(int i=0; i<set.size(); i++) {
            if(set[i] == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */