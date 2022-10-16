/*
 * @lc app=leetcode.cn id=1797 lang=cpp
 *
 * [1797] 设计一个验证系统
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class AuthenticationManager {
public:
    AuthenticationManager(int timeToLive) : m_timeToLive(timeToLive), m_currentTime(0) {

    }
    
    void generate(string tokenId, int currentTime) {
        m_tokens.emplace(tokenId, currentTime + m_timeToLive);
        m_currentTime = currentTime;
        checkExpired();
    }
    
    void renew(string tokenId, int currentTime) {
        m_currentTime = currentTime;
        checkExpired();
        if (m_tokens.find(tokenId) != m_tokens.end()) {
            m_tokens[tokenId] = m_currentTime + m_timeToLive;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        m_currentTime = currentTime;
        checkExpired();
        return m_tokens.size();
    }

    void checkExpired() {
        for (auto iter = m_tokens.begin(); iter != m_tokens.end();) {
            if (iter->second <= m_currentTime) {
                iter = m_tokens.erase(iter);
            } else {
                ++iter;
            }
        }
    }

private:
    int m_timeToLive;
    int m_currentTime;
    unordered_map<string, int> m_tokens;  // token, expired_time

};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
// @lc code=end

