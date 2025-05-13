#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 21

int a, b, c;

int memo[MAXN][MAXN][MAXN];

int dp_table[MAXN][MAXN][MAXN];

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    if (a < b && b < c) return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    return w(a - 1, b , c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int w2(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w2(20, 20, 20);
    if (memo[a][b][c] != -1) return memo[a][b][c];
    if (a < b && b < c)
        return memo[a][b][c] = w2(a, b, c - 1) + w2(a, b - 1, c - 1) - w2(a, b - 1, c);
    return memo[a][b][c] = w2(a - 1, b, c) + w2(a - 1, b - 1, c) + w2(a - 1, b, c - 1) - w2(a - 1, b - 1, c - 1);
}

void dp() {
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            for (int k = 0; k < MAXN; ++k) {
                if (i == 0 || j == 0 || k == 0) {
                    dp_table[i][j][k] = 1;
                } else if (i < j && j < k) {
                    dp_table[i][j][k] = dp_table[i][j][k - 1] + dp_table[i][j - 1][k - 1] - dp_table[i][j - 1][k];
                } else {
                    dp_table[i][j][k] = dp_table[i - 1][j][k]
                                      + dp_table[i - 1][j - 1][k]
                                      + dp_table[i - 1][j][k - 1]
                                      - dp_table[i - 1][j - 1][k - 1];
                }
            }
        }
    }
}

int32_t main() {
    memset(memo, -1, sizeof(memo));
    dp();  // 预处理DP表

    while (cin >> a >> b >> c) {
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = ";

        // 1. 暴力递归版
        // cout << w(a, b, c) << '\n';

        // 2. 记忆化搜索版
        // cout << w2(a, b, c) << '\n';

        // 3. DP版本
        int x = a, y = b, z = c;
        if (x <= 0 || y <= 0 || z <= 0) cout << 1 << '\n';
        else if (x > 20 || y > 20 || z > 20) cout << dp_table[20][20][20] << '\n';
        else cout << dp_table[x][y][z] << '\n';
    }

    return 0;
}
