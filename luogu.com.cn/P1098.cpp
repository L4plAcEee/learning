// P1098 [NOIP 2007 提高组] 字符串的展开
// https://www.luogu.com.cn/problem/P1098
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using f64 = double;
using u32 = unsigned;
using f32 = float;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << '\n';
#else
#define debug(x)
#endif

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

struct fastio {
    fastio () {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    }
} fastio;


string _parse(char l, char r, int p1, int p2, int p3) {
    if (r <= l || (isdigit(l) != isdigit(r)) || (isalpha(l) != isalpha(r))) {
        return "-";
    }

    string res = "";
    for (char c = l + 1; c < r; ++c) {
        char to_add;
        if (p1 == 3) {
            to_add = '*';
        } else if (p1 == 1) {
            to_add = tolower(c);
        } else if (p1 == 2) {
            to_add = toupper(c);
        }

        for (int i = 0; i < p2; ++i) {
            res += to_add;
        }
    }

    if (p3 == 2) {
        reverse(res.begin(), res.end());
    }

    return res;
}


int main() {
    int p1, p2, p3;
    string in;
    stringstream ss;
    cin >> p1 >> p2 >> p3 >> in;
    for (int i = 0; i < in.length(); ++i) {
        if (in[i] != '-') {
            ss << in[i];
        } else if (i > 0 && i + 1 < in.length()) {
            ss << _parse(in[i - 1], in[i + 1], p1, p2, p3);
        } else {
            ss << "-";
        }
    }    
    cout << ss.str() << '\n';
}