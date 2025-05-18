#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[n][m] = true;
        for (int j = m - 1; j >= 0; --j) {
			dp[n][j] = j + 1 < m && p[j + 1] == '*' && dp[n][j + 2];
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (j + 1 == m || p[j + 1] != '*')
 					dp[i][j] = (s[i] == p[j] || p[j] == '.') && dp[i + 1][j + 1];
                else 
 					dp[i][j] = dp[i][j + 2] || ((s[i] == p[j] || p[j] == '.') && dp[i + 1][j]);
            }
        }
        return dp[0][0];
    }
    bool f2(string &s, string &p, int i, int j, vector<vector<int>> &dp) {
        if (i == s.length()) {
            if (j == p.length()) return true;
            return j + 1 < p.length() && p[j + 1] == '*' && f2(s, p, i, j + 2, dp);
        } else if (j == p.length()) return false;
        
        if (dp[i][j] != -1) return (bool)dp[i][j];

        if (j + 1 == p.length() || p[j + 1] != '*') {
            dp[i][j] = (s[i] == p[j] || p[j] == '.') && f2(s, p, i + 1, j + 1, dp);
        } else {
            bool p1 = f2(s, p, i, j + 2, dp);
            bool p2 = (s[i] == p[j] || p[j] == '.') && f2(s, p, i + 1, j, dp);
            dp[i][j] = p1 || p2;
        }
        return (bool)dp[i][j];
    }
    bool f1(string &s, string &p, int i, int j) {
        if (i == s.length()) {
            if (j == p.length()) {
                return true;
            } else {
                return j + 1 < p.length() && p[j + 1] == '*' && f1(s, p, i, j + 2);
            }
        } else if (j == p.length()) {
            return false;
        } else {
            if (j + 1 == p.length() || p[j + 1] != '*') {
                return (s[i] == p[j] || p[j] == '.') && f1(s, p, i + 1, j + 1);
            } else {
                bool p1 = f1(s, p, i, j + 2);
                bool p2 = (s[i] == p[j] || p[j] == '.') && f1(s, p, i + 1, j);
                return p1 || p2;
            }
        }
    }
};