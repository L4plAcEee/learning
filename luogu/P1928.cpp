#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << x << '\n'
#else
#define dbg(x) 
#endif

string in;

string solve(string &s, int &idx) {
    string res;
    int repeat = 0;
    while (idx < s.length()) {
        char cur = s[idx++];
        dbg(cur);
        if (isdigit(cur)) {
            repeat = repeat * 10 + (cur - '0');
        } else if (cur == '[') {
            res += solve(s, idx);
            dbg(res);
        } else if (isalpha(cur)) {
            res += cur;
        } else if (cur == ']') {
            string temp = res;
            dbg(repeat);
            while (repeat > 1) {
                res += temp;
                repeat--;
            }
            return res;
        }
    }
    return res;
}

int32_t main() {
    cin >> in;
    int idx = 0;
    cout << solve(in, idx) << '\n';
}