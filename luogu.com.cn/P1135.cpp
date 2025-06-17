#include <bits/stdc++.h>
using namespace std;

const int MAXN = 201;
int N, A, B, arr[MAXN];
bool visited[MAXN] = {false};

void bfs() {
    queue<int> q;
    q.push(A);
    visited[A] = true;
    int depth = 0;

    while (!q.empty()) {
        int size = q.size(); // 当前层节点个数
        while (size--) {
            int cur = q.front(); q.pop();
            if (cur == B) { // 找到目标
                cout << depth << '\n';
                return;
            }

            int n = cur - arr[cur];
            if (n >= 1 && n <= N && !visited[n]) {
                visited[n] = true;
                q.push(n);
            }

            n = cur + arr[cur];
            if (n >= 1 && n <= N && !visited[n]) {
                visited[n] = true;
                q.push(n);
            }
        }
        depth++; // 每遍历完一层，步数加 1
    }

    cout << -1 << '\n'; // 找不到目标
}

int main() {
    cin >> N >> A >> B;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }
    bfs();
}
