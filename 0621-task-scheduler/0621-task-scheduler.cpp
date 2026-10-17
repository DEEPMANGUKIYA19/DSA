 class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char task : tasks) 
        {
            freq[task - 'A']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int maxfreq = freq[0];
        int idle = (maxfreq - 1) * n;

        for (int i = 1; i < 26; i++) 
        {
            idle -= min(maxfreq - 1, freq[i]);
        }

        return tasks.size() + max(0, idle);
    }
};