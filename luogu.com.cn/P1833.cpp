#include <bits/stdc++.h>
using namespace std;

#define MAXT 1005
#define MAXN 10005

int T, n;
int dp[MAXT] = {0};

int32_t main() {
    int start_hour, start_min;
    int end_hour, end_min;
    scanf("%d:%d", &start_hour, &start_min);
    scanf("%d:%d", &end_hour, &end_min);
    scanf("%d", &n);
    T = (end_hour * 60 + end_min) - (start_hour * 60 + start_min);

    for (int i = 1; i <= n; ++i) {
        int c, v, m;
        cin >> c >> v >> m;
        if (!m) {
            m = T / c;
        }
        for (int k = 1; m > 0; k <<= 1) {
            int cnt = min(k, m), cost = cnt * c, val = cnt * v;
            m -= cnt;
            for (int j = T; j >= cost; --j) {
                dp[j] = max(dp[j], dp[j - cost] + val);
            }
        }
    }
    cout << dp[T] << '\n';
    return 0;
}