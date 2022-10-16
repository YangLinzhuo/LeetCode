/*
 * @lc app=leetcode.cn id=2043 lang=cpp
 *
 * [2043] 简易银行系统
 */
#include <vector>
using namespace std;
// @lc code=start
class Bank {
public:
    Bank(vector<long long>& balance) : m_balance(balance) {

    }
    
    bool check_account(int account) {
        if (account >= 1 && account <= m_balance.size()) {
            return true;
        }
        return false;
    }

    bool transfer(int account1, int account2, long long money) {
        
        if (!check_account(account1) || !check_account(account2) || m_balance[account1 - 1] < money) {
            return false;
        }
        m_balance[account2 - 1] += money;
        m_balance[account1 - 1] -= money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (!check_account(account)) {
            return false;
        }
        m_balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (!check_account(account) || m_balance[account - 1] < money) {
            return false;
        }
        m_balance[account - 1] -= money;
        return true;
    }

private:
    vector<long long> m_balance;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
// @lc code=end

