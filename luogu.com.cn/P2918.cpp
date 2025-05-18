#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define MAXH 60000
#define MAXN 101

i64 H, N, c[MAXN] = {0}, v[MAXN] = {0}, dp[MAXN][MAXH];

int32_t main() {
    cin >> N >> H;
    i64 h = H;
    for (int i = 1; i <= N; ++i) {
        cin >> v[i] >> c[i];
    }
    H += *max_element(v, v + N + 1);
    std::fill(dp[0], dp[0] + MAXH, LONG_LONG_MAX);
    dp[0][0] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= H; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - v[i] >= 0 && dp[i][j - v[i]] != LONG_LONG_MAX)
                dp[i][j] = std::min(dp[i][j], dp[i][j - v[i]] + c[i]);
        }
    }
    // for (int i = 0; i <= N; ++i) {
    //     for (int j = 0; j <= H; ++j) {
    //         if (dp[i][j] == LONG_LONG_MAX)
    //             cout << "LLMAX" << ' ';
    //         else
    //             cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

   cout << *std::min_element(dp[N] + h, dp[N] + H + 1) << '\n';
}