 class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();

        vector<vector<string>> dp(n + 1);
        dp[0].push_back("");

        for (int i = 0; i < n; i++) {
            if (dp[i].empty())
                continue;

            string word = "";

            for (int j = i; j < n && j < i + 10; j++) {
                word += s[j];

                if (st.count(word)) {
                    for (string prev : dp[i]) {
                        if (prev.empty())
                            dp[j + 1].push_back(word);
                        else
                            dp[j + 1].push_back(prev + " " + word);
                    }
                }
            }
        }

        return dp[n];
    }
};