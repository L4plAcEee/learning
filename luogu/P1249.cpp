#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define i64 long long
#define EACH(x, y) for (auto &x : y)
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#define debug(m, v) cerr << m << " : " << v << endl
#else 
#define debug(x, y)
#endif

vector<int> build_sequence(int n) {
    vector<int> seq;
    int sum = 0;

    for (int i = 2; sum + i <= n; ++i) {
        seq.pb(i);
        sum += i;
    }

    #ifdef LOCAL
    debug("sum", sum);
    EACH(x, seq) {
        debug("原始序列元素", x);
    }
    #endif

    int remain = n - sum;
    if (remain > 0) {
    for (auto &n : seq) {
            if (find(all(seq), n + remain) == seq.end()) {
                n += remain;
                break;
            }
        }
    }
    #ifdef LOCAL
    // 调试：输出最终用于乘法的序列
    EACH(x, seq) {
        debug("最终序列元素", x);
    }
    #endif

    return seq;
}

vector<int> multiply(const vector<int>& seq) {
    vector<int> res = {1};
    for (int num : seq) {
        for (int &d : res) d *= num;
        for (size_t i = 0; i < res.size(); ++i) {
            if (res[i] >= 10) {
                int carry = res[i] / 10;
                res[i] %= 10;
                if (i + 1 == res.size()) res.pb(carry);
                else res[i + 1] += carry;
            }
        }
    }
    return res;
}

void solve(int n) {
    if (n == 3 || n == 4) {
        cout << n << '\n' << n << '\n';
        return;
    }

    auto seq = build_sequence(n);
    sort(seq.begin(), seq.end());
    for (int i = 0; i < (int)seq.size(); ++i) {
        if (i) cout << ' ';
        cout << seq[i];
    }
    cout << '\n';

    auto prod = multiply(seq);
    for (auto it = prod.rbegin(); it != prod.rend(); ++it)
        cout << *it;
    cout << '\n';
}

int main() {
    int n;
    #ifdef LOCAL
    n = 16;
    cerr << "测试 n :" << n << '\n'; 
    #else
    cin >> n;
    #endif
    solve(n);
    return 0;
}
