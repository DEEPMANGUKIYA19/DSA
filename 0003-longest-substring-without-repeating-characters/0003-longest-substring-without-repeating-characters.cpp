 class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> hash;

        int l = 0;
        int r = 0;
        int maxlen = 0;

        while (r < s.length()) {

            if (hash.find(s[r]) != hash.end()) {

                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }

            int len = r - l + 1;
            maxlen = max(maxlen, len);

            hash[s[r]] = r;
            r++;
        }

        return maxlen;
    }
};
