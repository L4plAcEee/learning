#include <bits/stdc++.h>
using namespace std;

int R, C, K;
char grids[101][101];

int f(int i, int j) {
    int cnt_i = 0, cnt_j = 0;
    for (int idx = i; idx < R && cnt_i < K && grids[idx][j] != '#'; ++idx, ++cnt_i);
    for (int idx = j; idx < C && cnt_j < K && grids[i][idx] != '#'; ++idx, ++cnt_j);
    return (cnt_i == K ? 1 : 0) + (cnt_j == K ? 1 : 0);
}

int32_t main() {
    cin >> R >> C >> K;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grids[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grids[i][j] == '.') {
                ans += f(i, j);
            }
        }
    }
    cout << (K == 1 ? ans / 2 : ans) << '\n';
}