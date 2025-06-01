#include <bits/stdc++.h>
using namespace std;

int n, r, a[30];

void dfs(int idx, int start) {
    if (idx == r) {
        for (int i = 0; i < r; ++i) {
            cout << setw(3) << a[i];
        }
        cout << '\n';
        return;
    }
    
    for (int i = start; i <= n; ++i) {
        a[idx] = i;
        dfs(idx + 1, i + 1);
    }
}

int32_t main() {
    cin >> n >> r;
    dfs(0, 1);
    return 0;
}