#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[n][m] = true;
        for (int j = m - 1; j >= 0; --j) {
            dp[n][j] = p[j] == '*' && dp[n][j + 1];
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (p[j] == '*')
                    dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
                else 
                    dp[i][j] = (s[i] == p[j] || p[j] == '?') && dp[i + 1][j + 1];
            }
        }

        return dp[0][0];
    }
    bool f1(string &s, string &p, int i, int j) {
        if (i == s.length()) {
            if (j == p.length()) 
                return true;
            return p[j] == '*' && f1(s, p, i, j + 1);
        } else if (j == p.length()) 
            return false;
        
        if (p[j] == '*') {
            return f1(s, p, i + 1, j) || f1(s, p, i, j + 1);
        } else {
            return (s[i] == p[j] || p[j] == '?') && f1(s, p, i + 1, j + 1);
        }
    }
};