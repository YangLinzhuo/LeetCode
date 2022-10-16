/*
 * @lc app=leetcode.cn id=1472 lang=cpp
 *
 * [1472] 设计浏览器历史记录
 */
#include <string>
#include <vector>

using namespace std;
// @lc code=start
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        m_history.emplace_back(homepage);
        m_cur = 0;
    }
    
    void visit(string url) {
        m_history.resize(m_cur + 1);    // m_cur is index, so for #element, should + 1
        m_history.emplace_back(url);
        m_cur++;
    }
    
    string back(int steps) {
        m_cur = max(0, m_cur - steps);
        return m_history[m_cur];
    }
    
    string forward(int steps) {
        int cur_size = m_history.size();
        m_cur = min(cur_size - 1, m_cur + steps);
        return m_history[m_cur];
    }

private:
    vector<string> m_history;
    int m_cur;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end

