#include <bits/stdc++.h>
using namespace std;

using f64 = double;
const int N = 20;
const int INF = 1 << 30;

int n;
f64 dp[1 << N][N];  // 状态压缩DP
f64 dis[N][N];      // 距离矩阵
pair<f64, f64> a[N];

f64 get_distance(pair<f64, f64> p1, pair<f64, f64> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    // 预处理距离
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dis[i][j] = get_distance(a[i], a[j]);

    // 初始化
    for (int i = 0; i < (1 << n); ++i)
        for (int j = 0; j < n; ++j)
            dp[i][j] = 1e9;

    // 起点到各个点的距离
    for (int i = 0; i < n; ++i)
        dp[1 << i][i] = get_distance({0.0, 0.0}, a[i]);

    // 状态转移
    for (int s = 1; s < (1 << n); ++s) {
        for (int i = 0; i < n; ++i) {
            if (!(s & (1 << i))) continue; // 如果 i 不在当前集合里，跳过
            for (int j = 0; j < n; ++j) {
                if (i == j || !(s & (1 << j))) continue; // j 不在集合里
                dp[s][i] = min(dp[s][i], dp[s ^ (1 << i)][j] + dis[j][i]);
            }
        }
    }

    f64 ans = 1e9;
    int full = (1 << n) - 1;

    // 最小答案
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp[full][i]);
    }

    cout << fixed << setprecision(2) << ans << '\n';

    return 0;
}
