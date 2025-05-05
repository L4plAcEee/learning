#include <bits/stdc++.h>
using namespace std;

int T, M;

void solve() {
    cin >> T >> M;
    vector<int> value(M + 1, 0);
    vector<int> cost(M + 1, 0);
    for (int i = 1; i <= M; ++i) {
        cin >> cost[i] >> value[i];
    }

    vector<vector<int>> dp(M + 1, vector<int>(T + 1, 0));
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= T; ++j) {
            if (j - cost[i] >= 0) {
                #ifdef LOCAL
                {
                    cout << "i == " << i << " j == " << j << '\n';
                    cout << "cost[i] ==" << cost[i] << " value[i] == " << value[i] << '\n';
                }
                #endif
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + value[i]);
                #ifdef LOCAL
                {
                    cout << "dp[i][j] == " << dp[i][j] << '\n';
                }
                #endif
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[M][T] << '\n';
}

int32_t main() {
    solve();
}