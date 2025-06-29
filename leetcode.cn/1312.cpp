#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(string &s, int l, int r) {
        if (l > r) return s[l] == s[r] ? 0 : 1;
        if (l == r) return 0;
        if (s[l] == s[r]) return func(s, l + 1, r - 1);
        return min(func(s, l, r - 1) + 1, func(s, l + 1, r) + 1);
    }
    int func2(string &s, vector<vector<int>> &memo, int l, int r) {
        if (l >= r) return 0;
        if (memo[l][r] != -1) return memo[l][r];
        if (s[l] == s[r]) return memo[l][r] = func2(s, memo, l + 1, r - 1);
        return memo[l][r] = min(func2(s, memo, l, r - 1) + 1, func2(s, memo, l + 1, r) + 1);
    }
    int dp(string &s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));

        for (int i = s.length() - 1; i >= 0; --i) {
            for (int j = i; j < s.length(); ++j) {
                if (i == j) continue;
                dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : min(dp[i][j - 1] + 1, dp[i + 1][j] + 1);
            }
        }
        return dp[0][s.length() - 1];
    }
    int minInsertions(string s) {
        // return func(s, 0, s.length() - 1);
        // vector<vector<int>> memo(s.length(), vector<int>(s.length(), -1));
        // return func2(s, memo, 0, s.length() - 1);
        return dp(s);
    }
};