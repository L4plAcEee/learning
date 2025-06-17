#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> d(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }

    // 1. 计算环形的增量总和 S = sum_{i=1..n} max(d[i] - d[i-1], 0)，其中 d[0] 视为 d[n]
    long long S = 0;
    for (int i = 1; i <= n; ++i) {
        int prev = (i == 1 ? n : i - 1);
        S += max(d[i] - d[prev], 0LL);
    }

    // 2. 枚举每个断点 r，计算 cost(r)，取最小
    long long ans = LLONG_MAX;
    for (int r = 1; r <= n; ++r) {
        int prev = (r == 1 ? n : r - 1);
        int nxt  = (r == n ? 1 : r + 1);

        long long term1 = d[r];                      // 先把第 r 块降到 0
        long long term2 = d[nxt];                    // 线性段最左端的基底
        long long sub1  = max(d[r] - d[prev], 0LL);
        long long sub2  = max(d[nxt] - d[r], 0LL);

        long long cost_r = term1 + term2 + S - sub1 - sub2;
        ans = min(ans, cost_r);
    }

    cout << ans << "\n";
    return 0;
}
