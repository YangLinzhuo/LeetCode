#include <vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <list>

using namespace std;

// @lc code=start
class LRUCache {
public:
    LRUCache(int capacity) : m_capacity(capacity) {

    }
    
    int get(int key) {
        auto iter = m_keyToIterator.find(key);
        if (iter != m_keyToIterator.end()) {
            auto list_iter = iter->second;
            int val = *list_iter;
            m_cache.erase(list_iter);
            m_cache.push_front(val);
            m_keyToIterator[key] = m_cache.begin();
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto iter = m_keyToIterator.find(key);
        if (iter == m_keyToIterator.end()) {
            if (m_cache.size() == m_capacity) {
                int val_to_remove = m_cache.back();
                m_cache.pop_back();
                m_keyToIterator.erase(val_to_remove);
            }
            m_cache.push_front(value);
            m_keyToIterator.emplace(key, m_cache.begin());
        } else {
            auto list_iter = iter->second;
            m_cache.erase(list_iter);
            m_cache.push_front(value);
            m_keyToIterator[key] = m_cache.begin();
        }
    }

private:
    size_t m_capacity;
    list<int> m_cache;  // save value
    unordered_map<int, list<int>::iterator> m_keyToIterator;  // save key
};

int main() {
    freopen("./data.txt", "r", stdin);
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    string s = ")(f";
    vector<string> commands{"put","put","get","put","get","put","get","get","get"};
    vector<vector<int>> values = {{1,0},{2,2},{1},{3,3},{2},{4,4},{1},{3},{4}};
    LRUCache cache(2);
    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "put") {
            cache.put(values[i][0], values[i][1]);
        } else {
            cache.get(values[i][0]);
        }
    }
    // solution.solveSudoku(board);
    // for (int i = 0; i < BOARD_SIZE; ++i) {
    //     for (int j = 0; j < BOARD_SIZE; ++j) {
    //         cout << board{i}{j} << " ";
    //     }
    //     cout << endl;
    // }
    
    return 0;
}