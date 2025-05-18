#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int MAXM = 10005;

int N, M;
int cost[MAXN];
int dp[MAXM];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> cost[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = M; j >= cost[i]; --j) {
            dp[j] += dp[j - cost[i]];
        }
    }

    cout << dp[M] << '\n';
    return 0;
}
