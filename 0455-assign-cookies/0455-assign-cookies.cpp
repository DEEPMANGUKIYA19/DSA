 class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int n = g.size();
        int m = s.size();

        int greedi = 0;
        int studant = 0;

        while (studant < m && greedi < n) {

            if (g[greedi] <= s[studant]) {
                greedi++;
            }

            studant++;
        }

        return greedi;
    }
};