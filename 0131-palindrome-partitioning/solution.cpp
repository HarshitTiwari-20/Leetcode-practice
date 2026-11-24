class Solution {
private:
    void backtrack(int start, string &s, vector<vector<int>> &dp,
                   vector<string> &curr, vector<vector<string>> &ans) {
        if (start == (int)s.size()) {
            ans.push_back(curr);
            return;
        }
        for (int end = start; end < (int)s.size(); end++) {
            if (dp[start][end] == 1) {
                curr.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, dp, curr, ans);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 1; len <= n; len++) {
            for (int start = 0; start + len - 1 < n; start++) {
                int end = start + len - 1;
                if (s[start] == s[end] && (len <= 2 || dp[start + 1][end - 1] == 1)) {
                    dp[start][end] = 1;
                }
            }
        }

        vector<vector<string>> ans;
        vector<string> curr;
        backtrack(0, s, dp, curr, ans);
        return ans;
    }
};