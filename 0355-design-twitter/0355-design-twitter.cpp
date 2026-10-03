 class Twitter {
public:
    vector<pair<int, int>> tweets[501];
    set<int> followlist[501];
    int time = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> all;

        
        for (auto t : tweets[userId]) {
            all.push_back(t);
        }

         
        for (int user : followlist[userId]) {
            for (auto t : tweets[user]) {
                all.push_back(t);
            }
        }

         
        sort(all.rbegin(), all.rend());

        vector<int> ans;

        for (int i = 0; i < all.size() && i < 10; i++) {
            ans.push_back(all[i].second);
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followlist[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followlist[followerId].erase(followeeId);
    }
};

 