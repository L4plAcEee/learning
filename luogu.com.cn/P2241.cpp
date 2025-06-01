#include <bits/stdc++.h>
using namespace std;

int n, m;
// int dp_a[5001][5001]; // 正方形
// int dp_b[5001][5001]; // 矩形（所有）

int main() {
    cin >> n >> m;
    long long sum_a = 0, sum_b = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // dp_a[i][j] =     // 正方形数量（以 i,j 为右下角）
            // dp_b[i][j] = i * j;         // 矩形数量（以 i,j 为右下角）
            sum_a += min(i, j); 
            sum_b += i * j;
        }
    }

    cout << sum_a << " " << (sum_b - sum_a) << endl;
    return 0;
}
