#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n, m, nxt[MAXN] = {0}, pre[MAXN] = {0};

int main() {
    cin >> n;
    nxt[0] = 1;
    for (int i = 2; i <= n; ++i) {
        int tg = -1, op = -1;
        cin >> tg >> op;
        if (op == 1) {
            int tmp = nxt[tg];
            nxt[tg] = i;
            pre[i] = tg;
            nxt[i] = tmp;
            pre[tmp] = i;
        } else {
            int tmp = pre[tg];
            nxt[i] = tg;
            pre[i] = tmp;
            nxt[tmp] = i;
            pre[tg] = i;
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int tg = -1;
        cin >> tg;
        int pre_v = pre[tg], nxt_v = nxt[tg];
        if (pre_v == 0 && nxt_v == 0) continue;
        nxt[pre_v] = nxt_v;
        pre[nxt_v] = pre_v;
        pre[tg] = 0;
        nxt[tg] = 0;
    }

    int head = 0;
    while (nxt[head]) {
        head = nxt[head];
        cout << head << ' ';
    }
}