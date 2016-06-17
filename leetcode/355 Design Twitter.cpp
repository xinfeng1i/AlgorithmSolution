#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
using namespace std;

struct Tweet {
	int tweet_id;
	int post_time;
	Tweet(int id = 0, int t = 0) : tweet_id(id), post_time(t) {}
	bool operator< (const Tweet& other) const {
		if (post_time != other.post_time) {
			return post_time > other.post_time;
		} else {
			return tweet_id < other.tweet_id;
		}
	}
};

struct User {
	int user_id;
	set<int> follows;
	set<int> funs;
	set<Tweet> tweets;
	User(int id=0) : user_id (id) {}
};

class Twitter {
public:
	/** Initialize your data structure here. */
	Twitter() {
		m_time = 0;
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		Tweet t(tweetId, m_time++);
		if (m_users.find(userId) == m_users.end()) {
			User my_user(userId);
			m_users[userId] = my_user;
		}
		m_users[userId].tweets.insert(t);
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		set<Tweet> temp_tweets;
		for (auto it = m_users[userId].tweets.begin();
			it != m_users[userId].tweets.end(); ++it) {
				temp_tweets.insert(*it);
		}
		for (auto it = m_users[userId].follows.begin(); it != m_users[userId].follows.end(); ++it) {
			int foll = *it;
			for (auto it2 = m_users[foll].tweets.begin(); it2 != m_users[foll].tweets.end(); ++it2) {
				temp_tweets.insert(*it2);
			}
		}

		int cnt = 0;
		vector<int> ans;
		for (auto it = temp_tweets.begin(); it != temp_tweets.end(); ++it) {
			ans.push_back(it->tweet_id);
			cnt++;
			if (cnt >= 10) {
				break;
			}
		}
		return ans;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int a, int b) {
		if (m_users.find(a) == m_users.end()) {
			User u(a);
			m_users[a] = u;
		}
		if (m_users.find(b) == m_users.end()) {
			User u(b);
			m_users[b] = u;
		}
		m_users[a].follows.insert(b);
		m_users[b].funs.insert(a);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int a, int b) {
		if (m_users.find(a) == m_users.end() || m_users.find(b) == m_users.end())
			return;
		if (m_users[a].follows.find(b) != m_users[a].follows.end()) {
			m_users[a].follows.erase(b);
		}
		if (m_users[b].funs.find(a) != m_users[b].funs.end()) {
			m_users[b].funs.erase(a);
		}
	}
private:
	unordered_map<int, User> m_users;
	int m_time;
};