#include <bits/stdc++.h>
using namespace std;

int grids[6][6] = {0};
int N, M, T, SX, SY, FX, FY;
int ans = 0;
void dfs(int x, int y) {
    if (x < 1 || x > N || y < 1 || y > M || grids[x][y] != 0) {
        return;
    }
    if (x == FX && y == FY) {
        ans++;
        return;
    }
    grids[x][y] = 1;
    dfs(x + 1, y);
    dfs(x, y + 1);
    dfs(x - 1, y);
    dfs(x, y - 1);
    grids[x][y] = 0;
}

int main() {
    cin >> N >> M >> T;
    cin >> SX >> SY >> FX >> FY;
    int BX, BY;
    while (T--) {
        cin >> BX >> BY;
        grids[BX][BY] = -1;
    }
    dfs(SX, SY);
    cout << ans << '\n';
}