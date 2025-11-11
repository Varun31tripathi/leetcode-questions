#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
    static const int B = 10007;
    vector<vector<pair<int,int>>> table;
    int idx(int key) const { return key % B; }
public:
    MyHashMap(): table(B) {}
    void put(int key, int value) {
        int i = idx(key);
        for (auto &p : table[i]) if (p.first == key) { p.second = value; return; }
        table[i].emplace_back(key, value);
    }
    int get(int key) {
        int i = idx(key);
        for (auto &p : table[i]) if (p.first == key) return p.second;
        return -1;
    }
    void remove(int key) {
        int i = idx(key);
        auto &vec = table[i];
        for (size_t j = 0; j < vec.size(); ++j)
            if (vec[j].first == key) { vec[j] = vec.back(); vec.pop_back(); return; }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */