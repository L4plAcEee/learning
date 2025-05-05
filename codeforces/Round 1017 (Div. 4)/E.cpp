#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAX_BITS = 31;
int t, n;


void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    // 统计每一位上有多少个 1
    vector<int> bitCount(MAX_BITS, 0);
    for (int i = 0; i < n; ++i) {
        for (int b = 0; b < MAX_BITS; ++b) {
            if ((a[i] >> b) & 1) {
                bitCount[b]++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int total = 0;
        for (int b = 0; b < MAX_BITS; ++b) {
            int cnt1 = bitCount[b];
            int cnt0 = n - cnt1;
            if ((a[i] >> b) & 1) {
                // 当前数该位为 1，与 cnt0 个 0 异或为 1
                total += cnt0 * (1LL << b);
            } else {
                // 当前数该位为 0，与 cnt1 个 1 异或为 1
                total += cnt1 * (1LL << b);
            }
        }
        ans = max(ans, total);
    }

    cout << ans << '\n';
}

void solve1() {
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            cur += (a[i] ^ a[j]);
        }
        res = max(res, cur);
    }
    cout << res << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
}
