#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << '\n'
// #define int unsigned long long

int N;

string string_plus(string &a, string &b) {
    int i = a.length() - 1, j = b.length() - 1;
    int carry = 0;
    string ret = string(max(a.length(), b.length()) + 1, '0');
    int k = ret.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int digitA = i >= 0 ? a[i--] - '0' : 0;
        int digitB = j >= 0 ? b[j--] - '0' : 0;
        int res = digitA + digitB + carry;
        ret[k--] = res % 10 + '0';
        carry = res / 10;
    }

    if (ret[0] == '0') return ret.substr(1);
    return ret;
}


void solve() {
    cin >> N;
    if (N <= 2) {
        cout << N << '\n';
        return;
    }
    string pre = "2", preX2 = "1", cur;
    for (int i = 3; i <= N; ++i) {
        cur = string_plus(pre, preX2);
        preX2 = pre;
        pre = cur;
        #ifdef LOCAL
        dbg(cur);
        #endif
    }
    cout << cur << '\n';
}

int32_t main() {
    solve();
    return 0;
}
