/*
 * @lc app=leetcode.cn id=1912 lang=cpp
 *
 * [1912] 设计电影租借系统
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
// @lc code=start
class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        m_num_shops = n;
        m_search_return_count = 5;
        for (auto &entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
            Entry e(shop, movie, price);
            m_entries[shop][movie] = e;
            // m_shop2movies[shop].emplace(movie);
            // m_movie2shops[movie].emplace(shop);
            m_search[movie].emplace(e);
            // m_records.emplace(e);
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        int size = m_search[movie].size();
        size = min(size, m_search_return_count);
        for (const Entry &e : m_search[movie]) {
            if (size == 0) {
                break;
            }
            ans.push_back(e.m_shop);
            --size;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        Entry &e = m_entries[shop][movie];
        e.is_rent = true;
        m_report.emplace(e);
        // m_search[movie].emplace(e);
        m_search[movie].erase(e);
    }
    
    void drop(int shop, int movie) {
        Entry &e = m_entries[shop][movie];
        e.is_rent = false;
        m_report.erase(e);
        // m_search[movie].erase(e);
        m_search[movie].emplace(e);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int size = m_report.size();
        size = min(m_search_return_count, size);
        for (const Entry &e : m_report) {
            if (size == 0) {
                break;
            }
            vector<int> item = {e.m_shop, e.m_movie};
            ans.emplace_back(item);
            --size;
        }
        return ans;
    }

private:
    struct Entry {
        int m_shop;
        int m_movie;
        int m_price;
        bool is_rent;
        Entry() = default;
        Entry(int shop, int movie, int price) : m_shop(shop), m_movie(movie), m_price(price), is_rent(false) {}

        bool operator<(const Entry& other) const {
            if (m_price < other.m_price) {
                return true;
            } else if (m_price == other.m_price && m_shop < other.m_shop) {
                return true;
            } else if (m_price == other.m_price && m_shop == other.m_shop && m_movie < other.m_movie) {
                return true;
            }
            return false;
        }

        bool operator==(const Entry& other) const {
            return m_shop == other.m_shop && m_movie == other.m_movie;
        }
    };

    struct Hash {
        size_t operator()(const Entry& e) const {
            size_t h1 = hash<int>()(e.m_shop);
            size_t h2 = hash<int>()(e.m_movie);
            return (h1 << 1) ^ h2;
        }
    };

    int m_num_shops;
    int m_search_return_count;
    unordered_map<int, unordered_map<int, Entry>> m_entries;
    // unordered_set<Entry, Hash> m_records;
    // unordered_map<int, unordered_set<int>> m_shop2movies;
    // unordered_map<int, unordered_set<int>> m_movie2shops;
    set<Entry> m_report;
    unordered_map<int, set<Entry>>  m_search;
    
    void insert(vector<Entry> &ans, Entry &e) {
        auto iter = lower_bound(ans.begin(), ans.end(), e);
        ans.emplace(iter, e);
        int size = ans.size();
        if (size == m_search_return_count + 1) {
            ans.pop_back();
        }
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
// @lc code=end

