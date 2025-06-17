#include <bits/stdc++.h>
using namespace std;

const int MAXN = 401;
const int MAXM = 401;
int n, m, x, y, mat[MAXN][MAXM];

int dx[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
int dy[8] = {-1, 1, -1, 1, -2, 2, -2, 2};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    mat[x][y] = 0;
    while (!q.empty()) {
        auto [cx, cy] = q.front();q.pop();
        for (int i = 0; i < 8; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m || mat[nx][ny] != -1)
                continue;
            
            mat[nx][ny] = mat[cx][cy] + 1;
            q.push({nx, ny});
        }
    }
}


int main() {
    cin >> n >> m >> x >> y;
    fill(&mat[0][0], &mat[0][0] + MAXN * MAXM, -1);
    bfs(x, y);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }
}