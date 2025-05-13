#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        return f1(s, p, 0, 0);
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