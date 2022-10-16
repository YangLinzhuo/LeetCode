/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
// @lc code=start
class Twitter {
public:
    struct Tweet {
        int m_tweetId;
        int m_idx;
        int m_timestamp;

        bool operator<(const Tweet &other) const {
            return m_timestamp > other.m_timestamp;
        }
        // bool operator>(Tweet &other) {
        //     return m_timestamp > other.m_timestamp;
        // }
        Tweet() = default;
        Tweet(int tweetId, int idx, int timestamp) : m_tweetId(tweetId), m_idx(idx), m_timestamp(timestamp) {

        }
    };

    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        m_posts[userId].push_back(tweetId);
        int size = m_timestamp.size();
        m_timestamp[tweetId] = size;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> posts;
        posts.reserve(10);
        vector<int> candidates;
        candidates.reserve(m_follow[userId].size() + 1);
        candidates.push_back(userId);
        for (int id : m_follow[userId]) {
            candidates.push_back(id);
        }
        vector<int> idx(candidates.size(), 0);
        for (int i = 0; i < candidates.size(); ++i) {
            int size = m_posts[candidates[i]].size(); // unsigned to signed
            idx[i] = size - 1;
        }

        for (size_t i = 0; i < m_recent_posts_count; ++i) {
            int tweetId = -1;
            set<Tweet> post2idx;
            for (size_t j = 0; j < idx.size(); ++j) {
                int index = idx[j];
                if (index >= 0) {
                    int post_idx = m_posts[candidates[j]][index];
                    //cout << "index: " << index << " post_idx: " << post_idx << endl;
                    Tweet tweet(post_idx, j, m_timestamp[post_idx]);
                    post2idx.emplace(tweet);
                } else {
                    continue;
                }
            }
            if (!post2idx.empty()) {
                auto iter = post2idx.begin();
                posts.push_back(iter->m_tweetId);
                idx[iter->m_idx]--;
            } else {
                break;  // no more posts
            }
        }
        // sort(posts.begin(), posts.end(), greater<int>());
        return posts;
    }
    
    void follow(int followerId, int followeeId) {
        m_follow[followerId].emplace(followeeId);
        m_followed[followeeId].emplace(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        m_follow[followerId].erase(followeeId);
        m_followed[followeeId].erase(followerId);
    }

private:
    unordered_map<int, unordered_set<int>> m_follow; // userid, follow_list
    unordered_map<int, unordered_set<int>> m_followed; // userid, followed_list
    unordered_map<int, vector<int>> m_posts;  // userid, post
    unordered_map<int, int> m_timestamp;
    const int m_recent_posts_count = 10;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

