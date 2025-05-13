#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000001
#define MOD 10000
int N, prefix[MAXN];

int32_t main() {
    cin >> N;
    int dp[3];
    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    prefix[0] = 1, prefix[1] = 2, prefix[2] = 4;
    for (int i = 3, cur; i <= N; ++i) {
        cur = (dp[2] + dp[1]+ 2 * prefix[i - 3]) % MOD;
        prefix[i] = (prefix[i - 1] + cur) % MOD;
        dp[0] = dp[1], dp[1] = dp[2], dp[2] = cur;
    }
    cout << dp[2] << '\n';
}