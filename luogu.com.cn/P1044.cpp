#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 20

// 计算第 n 个卡特兰数 C_n = (1/(n+1)) * binom(2n, n)
ll catalan(int n) {
    ll c = 1;
    // 先计算 binom(2n, n)
    for (int i = 0; i < n; ++i) {
        // c = c * (2n - i) / (i + 1)
        c = c * (2LL * n - i) / (i + 1);
    }
    // 再除以 (n+1)
    return c / (n + 1);
}

// 计算栈出栈序列数的“一维空间压缩”DP
long long dp_one(int n) {
    // dp[j] 在每一轮 i 中，初始存储 dp[i+1][j]
    long long dp[MAXN] = {0};
    dp[n] = 1;  // base case：dp[n][n] = 1

    // 从 i = n → 0 依次“压缩”每一层
    for (int i = n; i >= 0; --i) {
        // j 从右向左，保证 dp[j+1] 已经更新为 dp[i][j+1]
        for (int j = n; j >= 0; --j) {
            // 只有当栈非空（i > j）时，才能 pop
            if (j < i) 
                dp[j] += dp[j + 1];
        }
    }
    return dp[0];  // 最终 dp[0] 即 dp[0][0]
}

long long dp(int n) {
    long long dp[MAXN][MAXN] = {0};  // 假设 n ≤ 18，开到 20
    dp[n][n] = 1;  // base case：in = n, out = n，只有一种方式

    for (int i = n; i >= 0; --i) {
        for (int j = n; j >= 0; --j) {
            if (i + 1 <= n)
                dp[i][j] += dp[i + 1][j];  // push
            if (j + 1 <= n && i > j)
                dp[i][j] += dp[i][j + 1];  // pop，需保证 in > out（栈不空）
        }
    }
    return dp[0][0];  // 初始状态：0 个入栈，0 个出栈
}


int32_t main() {
    int n;
    cin >> n;
    // cout << dp(n) << '\n';
    cout << dp_one(n) << '\n';
    return 0;
}