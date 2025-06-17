#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 5;

int n, m;
int a[MAXN];

int32_t main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; cin >> a[i++]);

    while (m--) {
        int idx = 0;
        cin >> idx;
        cout << a[idx] << '\n';
    }
}