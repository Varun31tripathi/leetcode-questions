class MyHashSet {
    static const int B = 10007;
    vector<vector<int>> table;
    int idx(int key) const { return key % B; }

public:
    MyHashSet() : table(B) {}

    void add(int key) {
        int i = idx(key);
        for (int x : table[i])
            if (x == key) return;
        table[i].push_back(key);
    }

    void remove(int key) {
        int i = idx(key);
        auto &v = table[i];
        for (size_t j = 0; j < v.size(); ++j)
            if (v[j] == key) {
                v[j] = v.back();
                v.pop_back();
                return;
            }
    }

    bool contains(int key) {
        int i = idx(key);
        for (int x : table[i])
            if (x == key) return true;
        return false;
    }
};
