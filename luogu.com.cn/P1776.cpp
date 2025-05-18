#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define MAXW 100005

int n, W;
int v, w, m;
int dp[MAXW];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> W;

    for (int i = 1; i <= n; ++i) {
        cin >> v >> w >> m;

        // 二进制拆分优化
        for (int k = 1; m > 0; k <<= 1) {
            int cnt = min(k, m);
            m -= cnt;
            int cost = cnt * w;
            int val = cnt * v;
            for (int j = W; j >= cost; --j) {
                dp[j] = max(dp[j], dp[j - cost] + val);
            }
        }
    }

    cout << dp[W] << '\n';
    return 0;
}