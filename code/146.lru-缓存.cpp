/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */
#include <list>
#include <unordered_map>
using namespace std;
// @lc code=start
class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node (int key_, int value_) : key(key_), value(value_) {

        }
    };

    LRUCache(int capacity) : m_capacity(capacity) {

    }
    
    int get(int key) {
        auto iter = m_keyToIterator.find(key);
        if (iter != m_keyToIterator.end()) {
            auto list_iter = iter->second;
            int value = list_iter->value;
            m_cache.erase(list_iter);
            m_cache.push_front(Node(key, value));
            m_keyToIterator[key] = m_cache.begin();
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto iter = m_keyToIterator.find(key);
        if (iter == m_keyToIterator.end()) {
            if (m_cache.size() == m_capacity) {
                Node node = m_cache.back();
                m_cache.pop_back();
                m_keyToIterator.erase(node.key);
            }
            m_cache.push_front(Node(key, value));
            m_keyToIterator.emplace(key, m_cache.begin());
        } else {
            auto list_iter = iter->second;
            m_cache.erase(list_iter);
            m_cache.push_front(Node(key, value));
            m_keyToIterator[key] = m_cache.begin();
        }
    }

private:
    size_t m_capacity;
    list<Node> m_cache;  // save value
    unordered_map<int, list<Node>::iterator> m_keyToIterator;  // save key
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

