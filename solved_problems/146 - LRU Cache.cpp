class LRUCache{
private:
    list<pair<int, int>> l;                     // key, value
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int cap;
    
public:
    LRUCache(int capacity) {
        cap = capacity;    
    }
    
    int get(int key) {
        int val = -1;
        if (m.count(key)) {
            set(key, val = m[key]->second);     // update list
        }
        return val;
    }
    
    void set(int key, int value) {
        if (m.count(key)) {
            l.erase(m[key]);
        } else if (l.size() == cap) {
            m.erase(l.back().first);
            l.pop_back();
        }
        
        l.push_front({key, value});
        m[key] = l.begin();
    }
};