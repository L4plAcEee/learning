#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
char mat[MAXN][MAXN];
bool vis[MAXN][MAXN]; // 标记最终匹配成功的位置
int n;
string pattern = "yizhong";

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void check(int x, int y, int dir) {
    for (int i = 0; i < pattern.size(); ++i) {
        int nx = x + dx[dir] * i;
        int ny = y + dy[dir] * i;
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) return;
        if (mat[nx][ny] != pattern[i]) return;
    }

    for (int i = 0; i < pattern.size(); ++i) {
        int nx = x + dx[dir] * i;
        int ny = y + dy[dir] * i;
        vis[nx][ny] = true;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int d = 0; d < 8; ++d)
                check(i, j, d);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << (vis[i][j] ? mat[i][j] : '*');
        cout << '\n';
    }
    return 0;
}
