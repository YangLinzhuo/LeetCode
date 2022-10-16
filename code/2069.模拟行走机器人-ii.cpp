/*
 * @lc app=leetcode.cn id=2069 lang=cpp
 *
 * [2069] 模拟行走机器人 II
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Robot {
public:
    Robot(int width, int height) : m_width(width), m_height(height), 
                                   m_x(0), m_y(0), m_direction('E'),
                                   is_moved(false) {

    }
    
    bool isOverBound(int num) {
        switch (m_direction) {
            case 'E':
                return (m_x + num) >= m_width;
                break;
            case 'N':
                return (m_y + num) >= m_height;
                break;
            case 'W':
                return (m_x - num) < 0;
                break;
            case 'S':
                return (m_y - num) < 0;
                break;
            default:
                return false;
                break;
        }
    }

    void step(int num) {
        if (num == 0) {
            return;
        }
        is_moved = true;
        num %= (m_width + m_height) * 2 - 4;
        while (num) {
            switch (m_direction) {
                case 'E':
                    if (isOverBound(num)) {
                        reverseDir();
                        num -= (m_width - 1 - m_x);
                        m_x = m_width - 1;
                    } else {
                        m_x += num;
                        num = 0;
                    }
                    break;
                case 'N':
                    if (isOverBound(num)) {
                        reverseDir();
                        num -= (m_height - 1 - m_y);
                        m_y = m_height - 1;
                    } else {
                        m_y += num;
                        num = 0;
                    }
                    break;
                case 'W':
                    if (isOverBound(num)) {
                        reverseDir();
                        num -= m_x;
                        m_x = 0;
                    } else {
                        m_x -= num;
                        num = 0;
                    }
                    break;
                case 'S':
                    if (isOverBound(num)) {
                        reverseDir();
                        num -= m_y;
                        m_y = 0;
                    } else {
                        m_y -= num;
                        num = 0;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    
    vector<int> getPos() {
        return {m_x, m_y};
    }
    
    string getDir() {
        if (m_x == 0 && m_y == 0) {
            if (is_moved) {
                return "South";
            } else {
                return "East";
            }
        }
        switch (m_direction) {
            case 'E':
                return "East";
                break;
            case 'N':
                return "North";
                break;
            case 'W':
                return "West";
                break;
            case 'S':
                return "South";
                break;
            default:
                return "";
                break;
        }
    }

    void reverseDir() {
        switch (m_direction) {
        case 'E':
            m_direction = 'N';
            break;
        case 'N':
            m_direction = 'W';
            break;
        case 'W':
            m_direction = 'S';
            break;
        case 'S':
            m_direction = 'E';
            break;
        default:
            break;
        }
    }

private:
    int m_width;
    int m_height;
    int m_x;
    int m_y;
    char m_direction; // N, E, S, W
    bool is_moved;
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
// @lc code=end

