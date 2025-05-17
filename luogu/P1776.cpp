#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define MAXW 10005

int n, W;

int v[MAXN], w[MAXN], m[MAXN];
int dp[MAXW] = {0};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> W;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i] >> m[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = W; j >= 0; --j) {
            for (int cnt = 0; cnt <= m[i] && j - cnt * w[i] >= 0; ++cnt) {
                dp[j] = std::max(dp[j], dp[j - cnt * w[i]] + cnt * v[i]);
            }
        }
    }
    
    cout << dp[W] << '\n';
    return 0;
}