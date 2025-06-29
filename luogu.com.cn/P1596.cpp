#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x << " : " << x

const int MAXN = 101, MAXM = 101;
int N, M, cnt = 0;
char ground[MAXN][MAXM];

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void flood_fill(int x, int y) {
    // cout << "run:" << cnt << '\n';
    queue<pair<int, int>> q;
    ground[x][y] = '.';
    q.push({x, y});
    while (!q.empty()) {
        auto [cx, cy] = q.front();q.pop();
        for (int d = 0; d < 8; ++d) {
            int nx = cx + dx[d], ny = cy + dy[d];
            if (nx >= 0 && nx < N && 
                ny >= 0 && ny < M && 
                ground[nx][ny] == 'W') {
                    ground[nx][ny] = '.';
                    q.push({nx,ny});
                }
        }
    }
}

int main() {
    // int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) 
            cin >> ground[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            if (ground[i][j] == 'W') {
                cnt++;
                flood_fill(i, j);
            }
        }

    cout << cnt << '\n';
            
}