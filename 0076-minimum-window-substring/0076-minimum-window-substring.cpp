class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> hash(256, 0);

        for (char ch : t)
            hash[ch]++;

        int l = 0, r = 0;
        int count = 0;
        int m = t.size();

        int minLen = INT_MAX;
        int sindex = -1;

        while (r < s.size()) {
            if (hash[s[r]] > 0)
                count++;

            hash[s[r]]--;

            while (count == m) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sindex = l;
                }

                hash[s[l]]++;

                if (hash[s[l]] > 0)
                    count--;

                l++;
            }

            r++;
        }

        if (sindex == -1)
            return "";

        return s.substr(sindex, minLen);
    }
};