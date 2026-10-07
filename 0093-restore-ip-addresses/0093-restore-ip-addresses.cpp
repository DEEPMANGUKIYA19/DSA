 class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        
         
        for (int i = 1; i <= 3; i++) {
            for (int j = i + 1; j <= i + 3; j++) {
                for (int k = j + 1; k <= j + 3; k++) {
                    
                    if (k >= s.size())
                        continue;
                    
                    string a = s.substr(0, i);
                    string b = s.substr(i, j - i);
                    string c = s.substr(j, k - j);
                    string d = s.substr(k);
                    
                    
                    if (a.size() > 3 || b.size() > 3 ||
                        c.size() > 3 || d.size() > 3)
                        continue;
                    
                   
                    if ((a.size() > 1 && a[0] == '0') ||
                        (b.size() > 1 && b[0] == '0') ||
                        (c.size() > 1 && c[0] == '0') ||
                        (d.size() > 1 && d[0] == '0'))
                        continue;
                    
                     
                    if (stoi(a) <= 255 &&
                        stoi(b) <= 255 &&
                        stoi(c) <= 255 &&
                        stoi(d) <= 255) {
                        
                        ans.push_back(a + "." + b + "." + c + "." + d);
                    }
                }
            }
        }
        
        return ans;
    }
};