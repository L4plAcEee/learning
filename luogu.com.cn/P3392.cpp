#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x << " : " << x << '\n';

int N, M;
// char mat[51][51];
int cnt_W[51] = {0}, cnt_B[51] = {0}, cnt_R[51] = {0};

int32_t main() {
    cin  >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            // cin >> mat[i][j];
            char tmp;
            cin >> tmp;
            if (tmp == 'W') cnt_W[i]++;
            else if (tmp == 'B') cnt_B[i]++;
            else cnt_R[i]++;
        }
    }
    int cnt = INT_MAX;
    // 修改循环边界：i表示白色区域的行数，j表示白色+蓝色区域的总行数
    for (int i = 1; i <= N - 2; ++i) {         // 白色区域：[0, i)，至少1行，最多N-2行
        for (int j = i + 1; j <= N - 1; ++j) { // 蓝色区域：[i, j)，至少1行；红色区域：[j, N)，至少1行
            int tmp = 0;
            // 白色区域：需要把B和R涂成W
            tmp += reduce(cnt_B, cnt_B + i, 0) + reduce(cnt_R, cnt_R + i, 0);
            // 蓝色区域：需要把W和R涂成B
            tmp += reduce(cnt_W + i, cnt_W + j, 0) + reduce(cnt_R + i, cnt_R + j, 0);
            // 红色区域：需要把W和B涂成R
            tmp += reduce(cnt_W + j, cnt_W + N, 0) + reduce(cnt_B + j, cnt_B + N, 0);
            cnt = min(tmp, cnt);
        }
    }
    cout << cnt << '\n';
    return 0;
}