#include <bits/stdc++.h>
using namespace std;

#define MAXN 33001   // 最大总金额
#define MAXM 65      // 物品数量（1-based编号）

int cost[MAXM] = {0}, val[MAXM] = {0};
int fans[MAXM] = {0}, follows[MAXM][2] = {0}; // 每个主件最多两个附件
bool king[MAXM] = {false}; // 是否为主件

int dp[MAXN] = {0}; // 01背包状态数组
int n, m;

// 空间压缩 + 附件组合法
int DP() {
    for (int i = 1; i <= m; ++i) {
        if (king[i]) {
            int fan1 = fans[i] >= 1 ? follows[i][0] : -1;
            int fan2 = fans[i] >= 2 ? follows[i][1] : -1;

            for (int j = n; j >= 0; --j) {
                // 主件
                if (j >= cost[i])
                    dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);

                // 主件 + 附件1
                if (fan1 != -1 && j >= cost[i] + cost[fan1])
                    dp[j] = max(dp[j], dp[j - cost[i] - cost[fan1]] + val[i] + val[fan1]);

                // 主件 + 附件2
                if (fan2 != -1 && j >= cost[i] + cost[fan2])
                    dp[j] = max(dp[j], dp[j - cost[i] - cost[fan2]] + val[i] + val[fan2]);

                // 主件 + 附件1 + 附件2
                if (fan1 != -1 && fan2 != -1 && j >= cost[i] + cost[fan1] + cost[fan2])
                    dp[j] = max(dp[j], dp[j - cost[i] - cost[fan1] - cost[fan2]] + val[i] + val[fan1] + val[fan2]);
            }
        }
    }
    return dp[n];
}

void solve() {
    cin >> n >> m;
    for (int i = 1, c, v, q; i <= m; ++i) {
        cin >> c >> v >> q;
        cost[i] = c;
        val[i] = c * v;

        if (q == 0) {
            king[i] = true; // 主件
        } else {
            follows[q][fans[q]++] = i; // q 是主件编号，i 是附件编号
        }
    }
    cout << DP() << '\n';
}

int32_t main() {
    solve();
    return 0;
}
