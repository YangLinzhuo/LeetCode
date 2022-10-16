/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

#include <list>
#include <unordered_map>
using namespace std;
// @lc code=start
class LFUCache {
public:
    struct Node
    {
        int m_key;
        int m_value;
        int m_freq;
        list<list<Node>::iterator>::iterator m_iter;
        Node() = default;
        Node(int key, int value, int freq) : m_key(key), m_value(value), m_freq(freq) {

        }
    };
    
    LFUCache(int capacity) : m_capacity(capacity) {

    }
    
    int get(int key) {
        auto iter = m_key2node.find(key);
        if (iter == m_key2node.end()) {
            return -1;
        } else {
            auto cache_iter = iter->second;
            // update freq2list
            update_freq(cache_iter);
            return cache_iter->m_value;
        }
    }
    
    void put(int key, int value) {
        if (m_capacity == 0) {
            return;
        }
        auto iter = m_key2node.find(key);
        // if key not in key2node
        if (iter == m_key2node.end()) {
            // if reach to capacity
            if (m_cache.size() == m_capacity) {
                // find the min freq
                auto cache_iter = m_freq2list[min_freq].back();
                m_freq2list[cache_iter->m_freq].erase(cache_iter->m_iter);
                m_key2node.erase(cache_iter->m_key);
                m_cache.erase(cache_iter);
            }
            min_freq = 1;   // insert a new node
            Node node(key, value, min_freq);
            // insert to cache
            m_cache.push_front(node);
            auto cache_iter = m_cache.begin();
            // insert to key2node
            m_key2node.emplace(key, cache_iter);
            // insert to fre2node
            m_freq2list[cache_iter->m_freq].push_front(cache_iter);
            cache_iter->m_iter = m_freq2list[cache_iter->m_freq].begin();
        } else {
            // update freq
            auto cache_iter = iter->second;
            // erase node in freq2list
            update_freq(cache_iter);
            cache_iter->m_value = value;
        }
    }

    void update_freq(list<Node>::iterator &cache_iter) {
        int old_freq = cache_iter->m_freq;
        // erase node in freq2list
        m_freq2list[old_freq].erase(cache_iter->m_iter);
        m_freq2list[old_freq + 1].push_front(cache_iter);
        cache_iter->m_iter = m_freq2list[old_freq + 1].begin();
        cache_iter->m_freq = old_freq + 1;
        if ((min_freq == old_freq) && (m_freq2list[min_freq].size() == 0)) { // min_freq = old_freq
            min_freq++;
        }
    }

private:
    int m_capacity;
    int min_freq;
    list<Node> m_cache;
    unordered_map<int, list<Node>::iterator> m_key2node;
    unordered_map<int, list<list<Node>::iterator>> m_freq2list;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

