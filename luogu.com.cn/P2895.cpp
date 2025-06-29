#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305;
const int INF = 1e9;

int g[MAXN][MAXN];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct Node {
    int x, y, t;
};

void bfs() {
    queue<Node> q;
    vector<vector<bool>> vis(MAXN, vector<bool>(MAXN, false));

    if (g[0][0] == 0) { // 起点已被砸
        cout << -1 << '\n';
        return;
    }

    q.push({0, 0, 0});
    vis[0][0] = true;

    while (!q.empty()) {
        auto [x, y, t] = q.front(); q.pop();

        if (g[x][y] == INF) { // 找到永远不会被砸的安全区
            cout << t << '\n';
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nt = t + 1;

            if (nx < 0 || ny < 0 || nx >= MAXN || ny >= MAXN)
                continue;

            if (vis[nx][ny])
                continue;

            if (nt >= g[nx][ny]) // 到达时格子已经被砸，不可走
                continue;

            vis[nx][ny] = true;
            q.push({nx, ny, nt});
        }
    }
    cout << -1 << '\n'; // 无法到达安全区
}

int main() {
    int M;
    cin >> M;

    for (int i = 0; i < MAXN; ++i)
        for (int j = 0; j < MAXN; ++j)
            g[i][j] = INF;

    for (int i = 0; i < M; ++i) {
        int X, Y, T;
        cin >> X >> Y >> T;

        if (T < g[X][Y])
            g[X][Y] = T;

        for (int d = 0; d < 4; ++d) {
            int nx = X + dx[d];
            int ny = Y + dy[d];
            if (nx >= 0 && ny >= 0 && nx < MAXN && ny < MAXN)
                if (T < g[nx][ny])
                    g[nx][ny] = T;
        }
    }

    bfs();
    return 0;
}
