/*
 * @lc app=leetcode.cn id=2034 lang=cpp
 *
 * [2034] 股票价格波动
 */
#include <map>
#include <unordered_map>
using namespace std;
// @lc code=start
class StockPrice {
public:
    StockPrice() : max_timestamp(-1){

    }
    
    void update(int timestamp, int price) {
        auto iter = records.find(timestamp);
        if (iter == records.end()) {
            records.emplace(timestamp, price);
            count[price] += 1;
        } else {
            int old_price = iter->second;
            count[old_price] -= 1;
            if (count[old_price] == 0) {
                count.erase(old_price);
            }
            records[timestamp] = price;
            count[price] += 1;
        }
        max_timestamp = max(max_timestamp, timestamp);
    }
    
    int current() {
        return records[max_timestamp];
    }
    
    int maximum() {
        return count.rbegin()->first;
    }
    
    int minimum() {
        return count.begin()->first;
    }

private:
    int max_timestamp;
    unordered_map<int, int> records;    // timestamp, price
    map<int, int> count;    // price, #timestamp
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// @lc code=end

