#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define MAXM 10001
#define MAXT 10000001

i64 t, m, dp[MAXT], c[MAXM], v[MAXM];

int32_t main() {
    cin >> t >> m;
    for (int i = 0; i < m; ++i) {
        cin >> c[i] >> v[i];
    }
    fill(dp, dp + MAXT, 0ll);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= t; ++j) {
            if (j - c[i] >= 0) dp[j] = std::max(dp[j], dp[j - c[i]] + v[i]);
        }
    }
    cout << dp[t] << '\n';
}