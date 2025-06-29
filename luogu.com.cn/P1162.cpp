#include <bits/stdc++.h>
using namespace std;

const int MAXN = 31;

int n, grids[MAXN][MAXN] = {0};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0 ,-1};

void flood_fill(int x, int y, int color) {
    queue<pair<int, int>> q;
    grids[x][y] = color;
    q.push({x, y});
    while (!q.empty()) {
        auto [cx, cy] = q.front();q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = cx + dx[d], ny = cy + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grids[nx][ny] == 0) {
                grids[nx][ny] = color;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grids[i][j];
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                if (grids[i][j] == 0) {
                    flood_fill(i, j, -1);
                }
            }
        }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (grids[i][j] == 1 ? 1 : (grids[i][j] == -1 ? 0 : 2)) << ' ';
        }
        cout << '\n';
    }
}