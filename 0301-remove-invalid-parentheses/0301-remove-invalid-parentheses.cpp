 class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> visited;
        queue<string> q;
        vector<string> ans;
        bool found = false;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            int balance = 0;
            bool valid = true;

            for (char c : curr) {
                if (c == '(') {
                    balance++;
                } else if (c == ')') {
                    balance--;
                }

                if (balance < 0) {
                    valid = false;
                    break;
                }
            }

            if (balance != 0) {
                valid = false;
            }

            if (valid) {
                ans.push_back(curr);
                found = true;
            }

            if (found) {
                continue;
            }

            for (int i = 0; i < curr.size(); i++) {
                if (curr[i] != '(' && curr[i] != ')') {
                    continue;
                }

                string next = curr.substr(0, i) + curr.substr(i + 1);

                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return ans;
    }
};

